# Advanced Programming Project: TurboHiker

This is a report about the advanced programming project TurboHiker, 
containing information about how how the game has been implemented and why I used some specific design principles.

## Game info

Your job is to *avoid as much collisions and yells as possible, whilst trying to finish in the shortest amount of time*. This will earn you the most points.

## Note

I've followed the given assignment quite strictly in terms of gameplay so most should look familiar. Information about the used keys can be found below as there are a few specific keys mentioned (used for starting / restarting a hike, or yelling).

## Gameplay Cheatsheet

### Starting a hike
The game starts when pressing the key `S` in which the timer starts running. 
From now on, you can use the arrows to move the purple (player)hiker.

### Arrow keys

The `Up` arrow key is used to move the player at a faster pace, while the `Down` arrow key is used to make the player go slower, in case you wanted to be able to dodge in a more controlled manner. If you use the `left` arrow key, you move a lane to the right at a constant pace. The `right` arrow key makes you go a lane to the right.

### Yelling

Yelling can be done using the `spacebar`, which has different effects on the different types of hiker. The [Running Hiker](#features) goes slower (at 1/4th the original speed) and the [Static Hiker](#features) is [deleted](#mark-for-removal) from the world, (on a successful hike, with 50% chance per space bar pressed). A small penalty in the score is given for each succesful yell, so its best to avoid it if you can easily avoid a collision. If there are no other options besides actually colliding with another hiker, you will be better off yelling.

### Finish

After doing a hike for around 30 - 45 seconds, you will reach the finish. The game will then go into the state 'After Hiking' which means that you cannot control your own hiker anymore. The final score is calculated as you should see on the `top right corner` of your game.

### Resetting the world

If you press `R` during hiking or after (when you have reached the finish) you will be back at the beginning of the world. If you do this after you have reached the finish, the final score will be added to the list of scores *in case it is a [new highscore](#scoring-system)* If not, the current score will not be saved in the high scores. From here on you can [start hiking again](#starting-a-hike) by pressing the `S` key.

## Features

The `player hiker` is the hiker in *blue / purple* which animates between these two colors. The animation is just for fanciness and doesn't add anything special, same for the other two types. This is also used to demonstrate how the [Rendering](#rendering-system) system works.

The `static hiker` is the *green/yellow* hiker which stays static throughout the hike. *Be aware that they may seem like moving obstactles due to the moving [Camera](#view-system-sophisticated-transformation-class)*.

The `running hiker` is the *red/black* hiker implemented as 'the hiker running towards the player'. These are the hardest ones to dodge and again, due to the moving camera they may seem like going even faster.

The competing hikers are [spawned on the fly](#generation-of-competing-hikers) and [cleaned up afterwards](#cleaning-up) as well.

### Scores

Scores are measured as follows: each time a hiker collides with another hiker, minus points will be given (-300). No distinction is made between a running hiker or a static hiker. A small penalty (-5) will be given *for each succesful [yell](#yelling)* as it is not the 'best' but its definitely not as bad as colliding with another hiker.

### Collisions

Colliding with another hiker *makes the competing hiker dissapear* and give you minus points, as mentioned in [HighScores](#high-scores).

### Spawning

Enemies are be spawned on the fly and will appear constantly from the top of the screen until you've reached the finish. *Try to avoid all hikers*. The mechanics are explained [here](#generation-of-competing-hikers).

## Design Principles / Underlying Mechanics

### Scene Nodes

Scene Nodes are the fundamental objects the game is built of. They make up everything the [World](#the-world) consists of. These SceneNodes can be purely decorative, [Entities](#entities-and-the-hikers), [zones](#zones) or something custom. Each Type has a rendering component which is, in the logic library of TurboHiker, just and abstract class. This [rendering](#rendering-system) component can then be implemented by your specific visual implementation of the game and it can be set to render the given Type.

#### Locations

Each Type has a specific Vector2d (x, y) coordinate to position the Type in the world. The [BoundingBox](#boundingboxes) is calculated with regard to this location.

#### Lanes

The lanes are basic SceneNodes that represent a lane. These lanes don't do anything on their own and are mostly decorative. The only thing here is that the x locations of the lanes are used to position the Hikers correctly on their current lane.

#### Entities and the Hikers

Entities are basically SceneNodes with an extra attribute 'velocity'. Hikers are an example of this.

#### Zone

A zone is a specific type of Type which is only used in [collisions](#collision-handling) and does nothing on itself, such as the finish.

### The World

The world keeps track of all game logic from above: it does some logic itself, and delegates other logic to its children. Also the rendering requests are delegated further. The [SceneNodes](#scene-nodes) I talked about earlier are kept track in the [Scene Graph](#scene-graph) instead of in the world itself.
#### Scene Graph

The Scene Graph is basically an *'extension' of the world* that is only responsible for maintaining all SceneNodes currently present. It delegates specific requests such as commands, updates, or rendering, to all its 'children'. At first I kept track of all SceneNodes directly in the world class. So why did I switch? I was struggling to find a way to `not use downcasts` for each Type to get to their derived form (e.g. Hikers), as this is generally something to avoid. The SceneGraph solves this problem for you: internally it keeps track of a vector of shared ptrs to SceneNodes. Also the derivations of these SceneNodes are kept here using weak_ptrs. So the main 'ownership' is still in the list of SceneNodes, but there are already references to all derived objects added to the world. For example: If you want to add a competing hiker to the list of SceneNodes but still be able to directly get access to the derived Object (of the StaticHiker class for example), you use the function `addCompetingHiker`. This will automatically add the Hiker (Type) to the list of objects to be updated/rendered/..., but also add a weak pointer to still directly have access to the derived version.

Another reason why I used it is because it hides most of the 'specific' implementation of how the SceneNodes are kept track of. If it would ever change, the world doesn't necessarily needs to know.

### Collision Handling

The [World](#the-world) is responsible for reacting to collisions between [SceneNodes](#scene-nodes). I think that collisions should be handled from the top, to always be able to correctly define behaviour of two colliding SceneNodes. I thought at first that each Type should be responsible for reacting to collisions with other SceneNodes, but this doesn't guarantee that one Type reacts first. For example, let's say a Type reacts to another Type by moving away from the other Type so that they don't collide anymore. The location of this Type has changed and the behaviour of the other Type may now be different than intented.

#### BoundingBoxes

All SceneNodes can set a `bounding size`, which just means how big (in world coordinates) the Type is. This bounding size is then used to calculate the current bounding box, which is the rectangle (world coordinates) that currently represents the entity. These boundingBoxes have a left, bottom, width and height component and if the Type location changes, the bounding box is adjusted accordingly. I implemented the boundingBox so that the *origin of the 'location' of the Type is in the middle of the boundingBox*.

#### Collision Pairs

When checking for and handling collisions, the world sends a request to find all pairs of SceneNodes which collide with each other, by asking the [SceneGraph](#scene-graph) for it. The world will then react to these collisions individually in the `handleCollisions()` method.

### Input handling

**Pattern used:** [Command Pattern](https://gameprogrammingpatterns.com/command.html)

#### PlayerSFML and ActionBinder class

The ActionBinder is a class which binds actions with specific commands so that they can be executed on the world or SceneNodes. This ActionBinder class is part of the library. In the SFML implementation, the PlayerSFML class handles any keyBoard input which is binded to an Action. This way, `dynamic key bindings` are enabled as you just need to assign a different key to a different action to get the same effect, which is very easy to do. Each Action is in turn binded to a corresponding command using the ActionBinder. So indirectly, each key is binded to a specific command to execute as well.

#### Commands

Commands in the TurboHiker game are basic implementations of the command pattern. Each command holds a function pointer and this function will be executed in the correct places of the World. I used this pattern because it is very easy to keep Input apart from the Logic itself, and it is very easy to delegate commands to all its corresponding destinations. The function takes as parameters a reference to a Commandable and the delta time, in case you wanted to do some commands based on the timeStep. Examples of Commandables are the SceneNodes and the World.

Commandable is a simple interface with an unimplemented onCommand() function to do something specific if wanted.

### Rendering System

**Pattern used:** [Component Pattern](https://gameprogrammingpatterns.com/component.html)

The Rendering System is used to separate all Game Logic from the concrete Visual implementation of the game. Each Type has a renderer which is a component of the Type. This Renderer is simply an interface in the game logic library and can be implemented in the concrete visual implementation, so that the logic library does not know anything about how, or if, the object is actually rendered. The RendererSFML simply implements this class and adds some extra SFML specific things to actually make it work using SFML.

*Why I chose a Rendering Component above Rendering Hierarchy:* I think that the visual representation of an object should not really be a part of the Object itself, this pattern decouples the Game logic from the Visual implementation a bit more. The Renderer should never be able to control any Game Logic, it should only track the current state and render depending on those states. Another reason why I did this is that its fairly easy to create different renderers for the same type of Type now. Just `plug in` a different renderer and the object will be rendered differently. This would be harder to do using inheritance, and you would get a bigger inheritance structure by all the different visualizations of the a same thing.
### View System (Sophisticated Transformation class)

**Pattern used:** [Singleton Pattern](https://gameprogrammingpatterns.com/singleton.html)

In its essence, the Transformation class is a class which converts pixel values to the visible 2D game world space, as was mentioned in the programming assignment. It doesn't use SFML specific classes to implement views or enable scrolling.

*I did some more upgrades on this Transformation class though*, to have a better gaming experience. A View system was implemented in the transformation class itself, with a `working Camera`: you can adjust how much you can see of the world (in world coordinates), both in width and in height. I've implemented it so that the ratios of the screen and world view are always one to one, so that you don't get any stretched renderings of the SceneNodes. This also made sure that `resizing the window to any arbitrary size` is now easy to do and this just makes sure you can see more / less of the world, but everything still looks perfect. If you can't see as wide to see all lanes of the world, the camera moves along with the player to keep the player in the middle of the screen. On the other hand, if its possible to see all lanes at once, the camera is centered in the middle and doesn't move to the left/right if the player switches lanes.

#### Scrolling

Scrolling is very important, as the world is a lot higher than what you can initially see. Whenever the player moves above the center of the screen, the view starts moving along with the player to keep the player in sight and scroll upwards on the lanes.

Why the transformation class resides in the Game Logic instead of the Visual implementation: some of the game logic depends on the View system (which only uses world coordinates, so its okay to put into the logic library), such as tracking the player or [cleaning](#cleaning-up) up some of the competing hikers. This is why I had to implement the transformation class in the game logic libary instead of the SFML implementation I would have preferred to use another pattern than the Singleton pattern so that I could do a part of the transformation system in the Game logic (the World View implementation) and use inheritance for the SFML implementation to do the conversions from coordinates into their corresponding pixel values.

### Scoring System

**Pattern used:** [Observer Pattern](https://gameprogrammingpatterns.com/observer.html).

The class `Score` is used to keep track of the Score of a hike, which takes in account the amount of successful [yells](#yelling), the amount of hikers [collided](#collisions) with and the time of arrival. The `total score is calculated in the end`, because the time of arrival is completely unkown whilst hiking. It uses the Observer pattern to receive events when something happens and update the score accordingly. This way, the Score cannot be manipulated directly in every corner of the Game, which decouples the code.

To maintain the current HighScores, the `HighScoreContainer` class is used. Upon construction, you can set the max amount of HighScores to keep. Whenever a hike is [Reset](#resetting-the-world), the current score is passed into the `addScore` function of the HighScoreContainer and does the following:

1. If the HighScoreContainer did not reach the max capacity of HighScores yet, the new Score is simply added.
2. If the HighScoreContainer is at its max capacity, the Score
   1. Either replaces the current 'worst' high score, if the new score is better
   2. Is not added to the list of HighScores as it doesn't defeat any other HighScores.

### Generating SceneNodes and Competing Hikers

**Pattern used:** [Abstract Factory Pattern](https://refactoring.guru/design-patterns/abstract-factory)

#### SceneNodeFactory

The SceneNodeFactory is my implementation of the Abstract Factory Pattern: no concrete SceneNodes are created from the library, but it can be implemented by a concrete visual implementation, which creates the Type and sets the [renderer](#rendering-system) for it as well (which is specific to the visual implementation of the Game). The concrete implementation of the SceneNodeFactory is done in the `SceneNodeFactorySFML` class.

#### Generation Of Competing Hikers

To meet the requirement of 'different runs should not result in the same games', I've decided to `dynamically generate competing hikers on the fly`. All hikers are placed quite randomly on the lanes which makes the game more unpredictable and harder to avoid collisions. This is all done in the `generateCompetingHikers()` function of the [world](#the-world). When they go out of screen, the hikers are [removed](#cleaning-up)
### Cleaning up

When the competing hikers are not relevant anymore, the competing Hikers are removed from the world as they are no longer relevant and won't participate anymore. This increases efficiency as you won't have to do pointless collision detections and no updates and renderings are done anymore. You can see the workings of this a bit when you look on the `top left corner of the screen: currentAmountOfCompetingHikers: X`.

#### Mark for removal

I've implemented a markForRemoval function in the `Removable` abstract class which just implements a simple boolean value to indicate whether or not an object should be removed in the next update. Every update of the world, the sceneGraph gets the command to `cleanup all dead objects` first, meaning all objects who have been marked for removal in the previous update.

The mark for removal is useful as no objects are directly removed, which makes sure that no other 'living' SceneNodes are skipped whenever you are iterating over the them. For example: if you would remove a Type in the middle of iteration, the vector shifts all its SceneNodes to the left meaning that the Type previously at index i can now be found at i - 1. If you would increment the index, you would actually move two SceneNodes forward.

Another usefulness about this is that the markForRemoval can be called from anywhere, while the actual removal can only be done within the SceneGraph itself.
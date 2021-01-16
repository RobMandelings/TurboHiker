# Advanced Programming Project: TurboHiker

This is a report about the advanced programming project TurboHiker, 
containing information about how how the game has been implemented and why I used some specific design principles.

## Note

I've followed the given assignment fairly well in terms of gameplay so most should look familiar.

## Gameplay Cheatsheet

### Starting a hike
The game starts when pressing the key `S` in which the timer starts running. 
From now on, you can use the arrows to move your purple friend.

### Arrow keys

The `Up` arrow key is used to move the player at a faster pace, while the `Down` arrow key is used to make the player go slower.
If you want to be able to dodge in a more controlled manner for example. If you use the `left` arrow key, you move a lane to the right at a constant pace. The `right` arrow key makes you go a lane to the right.

### Yelling

Yelling can be done using the `spacebar`, which has different effects on the different types of hiker. The [Running Hiker](#running-hiker) goes slower (at 1/4th the original speed) and the [Static Hiker](#static-hiker) is deleted from the world, (on a successful hike, with 50% chance per space bar pressed). A small penalty in the score is given for each succesful yell, so its best to avoid it if you can easily avoid a collision. If there are no other options besides actually colliding with another hiker, you will be better off yelling.

### Finish

After doing a hike for around 30 - 45 seconds, you will reach the finish. The game will then go into the state 'After Hiking' which means that you cannot control your own hiker anymore. The final score is calculated as you should see on the `top right corner` of your game.

### Resetting the world

If you press `R` during hiking or after (when you have reached the finish) you will be back at the beginning of the world. If you do this after you have reached the finish, the final score will be added to the list of scores `in case it is a new high score`. If not, the current score will not be saved. From here on you can [start hiking again](#starting-a-hike) by pressing the `S` key.

## Features

The `player hiker` is the hiker in blue / purple which animates between these two colors. The animation is just for fanciness and doesn't add anything special, same for the other two types. This is also used to demonstrate how the [Rendering](#Rendering) system works.

The `static hiker` is the green/yellow hiker which stays static throughout the hike. *Be aware that they may 'seem' like moving obstactles due to the moving [Camera](#Camera)*.

The `running hiker` is the red/black hiker implemented as 'the hiker running towards the player'. These are the hardest one to dodge and again, due to the moving camera they may seem like going even faster.

The competing hikers are [spawned on the fly](#enemygeneration) and [cleaned up afterwards](#markforremoval) as well

### High Scores

High scores are measured as follows: each time a hiker collides with another hiker, minus points will be given (-300). No distinction is made between a running hiker or a static hiker. A small penalty (-5) will be given *for each succesful [yell](#yelling)* as it is not the 'best' but its definitely not as bad as colliding with another hiker.

### Collisions

Colliding with another hiker `makes the competing hiker dissapear` and give you minus points, as mentioned in [HighScores](#high-scores).

### Spawning

Enemies will be spawned on the fly, creating a more `dynamic hike` each time you run a game. This is to make sure that no two hikes will be exactly the same as the positions of the competing hikers are unknown until they appear. When they go [out of screen](#view-system), they are also [removed](#cleaned) from the world.

## Design Principles 

### Scene Nodes

### The World

#### Scene Graph

### Commands
### Rendering System

### View System (Sophisticated Transformation class)

### Cleaning up

This is also what you can see on the top left corner of your screen as `'current amount of hikers'`.

## Extras
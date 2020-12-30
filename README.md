# TurboHiker
Advanced Programming course assignment to create a game called 'Turbo Hiker' 

## Installation guide

This project requires a the SFML Library you need to download yourself, for your platform and compiler.
I have divided the installation guide in a linux and a windows part, as the installation is different for each platform.
The SFML version used in this project is 2.4.2, so it is recommended that you download this version.

### On linux:

### On windows:

Its best to use static libraries for this as it is the easiest to set up. Go to the download page of SFML (https://www.sfml-dev.org/download.php)
and go to the older versions of sfml. Select version 2.4.2. Download the sfml 2.4.2-32bit release and the appropriate compiler for it as well.
I used MinGW32-6.1.0. Be careful: the compilers need to match 100%. Once you have downloaded SFML, go to the project folder of the TurboHiker and create a directory lib
Which contains the SFLM directory (containing binaries, include folders and lib/ folder). The CMakeLists.txt is set up so that it will find SFML using this file structure.
Other 'general' locations are also allowed, but you might have to look in FindSFML.cmake for that.

You still need to configure the corresponding compiler as well. In the case you are using Clion:
First unzip the MinGW file and place the folder in a directory like C:\MinGW\MinGW-6.1.0\mingw32\ (for example). Then you can go and configure your toolchain using the settings of clion.
Point to mingw folder you have extracted and put into a directory you like. Now Clion should find this compiler.
You can now go to the 'Cmake' option in the settings and select that you want to use the MinGW toolchain to startRunning your program.
Once this is done, everything should be set up and you should able to startRunning the program!

# TODOs

Maybe also add an update() in the render component for usage in animations and such, or to change the sprite being used depending on the physical state of an entity,...
Make sure the actions and commands are in a separate class (maybe divide into Player and PlayerSFML).

# Important 'features' / coding designs used

Component pattern for rendering: illustrated well with animations

Sophisticated view system: moving center, scaling,resizing of window

Custom amount of lanes


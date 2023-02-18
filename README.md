# SO_LONG

## Introduction
In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general. In my case, it will be Hungry Chicken for mandatory part and Community Service game for bonus. 

![ezgif com-video-to-gif](https://user-images.githubusercontent.com/100228348/219850741-8adc9183-506a-4541-9e06-25d0976fe46e.gif)

#### Bonus Community Service game
By the school rules it's not allowed to leave drinks on the table or to forget your ID card somewhere. You need to collect all IDs and Bottles and exit before Guillaume (pedago team) catch you. 

<img width="1057" alt="Screen Shot 2023-02-18 at 9 15 56 AM" src="https://user-images.githubusercontent.com/100228348/219850852-7b3ba658-d170-4783-b492-65e3e0f7a682.png">

#### Mandatory Hungry Chick Game
Your small chicks are hungry. Help chicken collect all worms and take to the nest.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` *(player)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player to collect all the collectibles on the map before going to an exit in the least possible number of steps

## How it Works
For the graphics part of the project we used a library called ``minilibx``. It's fairly basic and somewhat limited, but was still fun to use in the project. 

### !!We have mlx library in 42school's Macs, but if you don't have, you need to downoload and add it to Makefile.!! 

## HOW TO USE  
### MANDATORY 
Just type ``make`` and ``./so_long ./maps/Your choice`` 
### BONUS 
Firstly ``make bonus`` then ``cd bonus`` and ``./so_long_bonus ../maps/Yourchoice``

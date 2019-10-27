# Maze project : ENSICAEN

## First project of following course : "Introduction à la programmation"

This project is part of the programming course (ENSICAEN - Engineering School).
The goal is to become familiar with the C language to create a maze game.

## Developer manual

### **Choices**

I made the choice to develop this project so that it turns on the **Linux OS**. In the long run, however, I would like to extend it to Windows, that's why I noticed some TODO and started to anticipate this extension in some functions. This is particularly the case with the **int OSlinux () function.**

### Documentation

I also generated the documentation of my project thanks to the tool Doxygen to be able to visualize more easily the structure of my project.

It is accessible here: **Maze_Project_BSECHI/doc/html/index.html** and will help a potential future developer to understand in detail the structure of the project as well as known bugs.

### Functionalities developed

* Creating a perfect labyrinth
* Create a labyrinth according to user input (size, name)
* Saving and loading a previously created labyrinth
* Play a labyrinth loaded
* System of scores and treasures / traps

### Features to develop

* Part 4 and monster management is entirely up for grabs
* Score management is still working, including the fact that only the top 10 players see their score recorded in the score file associated with the program.

### Known bugs

* The fact that the project is developed for the Linux OS (knowing that the subject specifies that the executable must be running on Windows **or** Linux) will surely cause problems in the creation of folders if the player executes the program on Windows.
* I must prevent the user from loading a file by typing "../", which would result in a file search in the wrong folder.
* Similarly for the backup, I must prevent the user from typing "../" so that it does not save the file to another folder.
* I have to load a labyrinth before playing (option 3). The program stops if the player decides to play without having loaded a file beforehand.

## User manual

**Step 1:** Launch the game

1. Go to the "cmake-build-debug" folder of the project.
2. Open a terminal (Right click - Open in a terminal).
3. Type "./Maze_Project_BSECHI".

**Step 2:** Choose an option

Choose one of the 4 options (enter the number followed by the enter key):
* Create a new maze
* Load an existing maze
* To play
* Leave the game

**1. Create a labyrinth**

You can create a maze based on height and length. Both must be odd and greater than 1.

You then have two choices. Either the maze suits you and you want to save it (type 1), or it does not suit you and you want to return to the menu (type 0).

If you want to save the maze, please enter a name. This name will be the same that you will use to load this labyrinth. For the good functioning of the game, thank you not to relocate the file by typing characters of this type "../" in the name of your labyrinth. Numbers and letters (lowercase and uppercase) are accepted.

**2. Load an existing maze**

The list of labyrinths already created is displayed. If there is none, the program writes it and you are returned to the menu. You must first create one with option # 1.

Once a labyrinth has been created, you can load it by simply typing its name without the ".cfg" extension.

**3. Playing**

Once you are returned to the menu after loading a labyrinth, you can now choose option # 3 to play the maze.

Be careful, you can not choose the Play option before loading a maze.

**Step 3:** Play

You can move in 4 directions:
* **z:** top
* **q:** left
* **s:** down
* **d:** right

To move, you must type the letter of the direction followed by the enter key. You can also return to the menu (type the letter m) or leave the game (type the letter p). If you return to the menu without reloading another labyrinth in the meantime, you can resume your game where you left off.

A base score is awarded to the player based on the size of the maze. You lose 10 points each move, 20 if you come across a trap. Your score increases by 20 points if you recover a treasure. The goal is of course to get as many points as possible at the end of the game.

Once the game is over, enter your name for your final score to be recorded.

#### Copyright (C) 2019 - Bahia SECHI

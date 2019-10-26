/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex

 * Note :
 * This file is owned by an ENSICAEN student.  No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.

 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>

 * @date October 2019

 * @file main.c
 * @version 1.0
 *
 * @brief Main file to begin to play the game
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameplay.h"
#include "tools.h"

void main() {

    clear_console();

    srand(time(NULL));

    int choice = 0;
    Maze maze;

    Maze maze_loaded;

    while (choice != 4) {

        choice = menu();

        switch (choice) {
            case 1:
                clear_console();
                create_maze(maze);
                break;
            case 2:
                clear_console();
                maze_loaded = load_maze(maze);
                break;
            case 3:
                clear_console();
                play_maze(maze_loaded, maze_loaded.name);
                break;
            case 4:
                exit(0);
        }
    }

}
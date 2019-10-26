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

 * @file gameplay.h
 * @version 1.0
 *
 * @brief Header of the gameplay.c source in which the main playing functions are developed to play the maze game.
 */

#ifndef MAZE_PROJECT_BSECHI_GAMEPLAY_H
#define MAZE_PROJECT_BSECHI_GAMEPLAY_H

#endif //MAZE_PROJECT_BSECHI_GAMEPLAY_H

#include "maze.h"

/**
 * @fn int menu ()
 * @brief Display the menu to choose what to do.
 *
 * @return The choice of the user.
 */
int menu ();

/**
 * @fn void display_maze (Maze maze_creation)
 * @brief Display the maze previously created
 *
 * @param maze_creation The maze to display.
 */
void display_maze (Maze maze_creation);

/**
 * @fn void propagation (Maze * maze, int cell_value, int pos_height, int pos_length)
 * @brief Recursive function to verify if the neighbours of the cells are related
 *
 * @param maze The maze in which we apply the recursive function
 * @param cell_value The value contained by the cell
 * @param pos_height The position height of the cell
 * @param pos_length The position length of the cell
 */
void propagation (Maze * maze, int cell_value, int pos_height, int pos_length);

/**
 * @fn void create_maze ()
 * @brief Asks the user the size of the maze and calls the initialization function.
 */
void create_maze ();

/**
 * @fn void init_maze (int height, int length)
 * @brief Initializes the maze with the correct values in the cells
 *
 * @param height Height entered by tbe user
 * @param length Length entered by tbe user
 */
void init_maze (int height, int length);

/**
 * @fn void save_maze (Maze * maze)
 * @brief Saves the created maze in a file
 *
 * @param maze Pointer towards the maze to save
 */
void save_maze (Maze * maze);

/**
 * @fn Maze load_maze (Maze maze_load)
 * @brief Load the maze the user wants to play
 *
 * @param maze_load
 */
Maze load_maze (Maze maze_load);

/**
 * @fn void play_maze (Maze maze, char * maze_name)
 * @brief Allows the user to play the maze previously loaded
 *
 * @param maze The loaded maze
 * @param maze_name The name of the loaded name
 */
void play_maze (Maze maze, char * maze_name);
//
// Created by bahia on 07/10/2019.
//

#ifndef MAZE_PROJECT_BSECHI_GAMEPLAY_H
#define MAZE_PROJECT_BSECHI_GAMEPLAY_H

#endif //MAZE_PROJECT_BSECHI_GAMEPLAY_H

#include "maze.h"

int menu();

void display_maze (Maze maze_creation);

void propagation (Maze * maze, int cell_value, int pos_height, int pos_length);

void init_maze (int height, int length);

void create_maze ();

void save_maze (Maze * maze);

void load_maze (Maze maze);

void play_maze(Maze maze);
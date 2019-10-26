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

 * @file maze.h
 * @version 1.0
 *
 * @brief Header which defines the structure Maze as well as the macros value of cells
 */

#ifndef MAZE_PROJECT_BSECHI_MAZE_H
#define MAZE_PROJECT_BSECHI_MAZE_H

/*
 * Value of cells
 */
#define WALL -1
#define PLAYER -2
#define OUT -3
#define NORMAL 1
#define TREASURE 2
#define TRAP 3

#endif //MAZE_PROJECT_BSECHI_MAZE_H

/**
 * @struct Maze maze.h
 * @brief The structure of a Maze
 *
 * A maze is defined by its position and as a matrix of integers.
 * It has a name and a specific number of walls broken.
 * The level is defined in the structure but not yet used, it
 * comes in the part 4 of the project.
 */
typedef struct
{
    int height;
    int length;
    int **maze;
    char *name;
    int walls_down;
    int level;
} Maze;
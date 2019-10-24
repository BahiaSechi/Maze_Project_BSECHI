//
// Created by bahia on 07/10/2019.
//

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

typedef struct
{
    int height;
    int length;
    int **maze;
    char *name;
    int walls_down;
    int level;
} Maze;
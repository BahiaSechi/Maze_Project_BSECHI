//
// Created by bahia on 07/10/2019.
//

#ifndef MAZE_PROJECT_BSECHI_MAZE_H
#define MAZE_PROJECT_BSECHI_MAZE_H

#define DEFAULT_HEIGHT 155
#define DEFAULT_LENGTH 155

#define WALL -1

#endif //MAZE_PROJECT_BSECHI_MAZE_H

typedef struct
{
    int height;
    int length;
    int **maze;
    int walls_down;
    int level;
} Maze;

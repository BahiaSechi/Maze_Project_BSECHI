#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameplay.h"

void main() {

    srand(time(NULL));

    int choice = menu();

    /*
     * Initialisation of variables to create a maze.
     * Use of the structure Maze defined in maze.h.
     */
    Maze maze;

    /*TODO DELETE THIS
     * An example in case of I want to modify something in my structure :
     * Maze *pointer = &maze;
     * pointer->height = 55;
    */

    switch (choice) {
        case 1:
            create_maze(maze);
            break;
        case 2:
            //TODO load_maze();
            printf("Load an existing labyrinth\n");
            break;
        case 3:
            //TODO play_maze();
            printf("Play\n");
            break;
        case 4:
            quit_game();
            break;
    }

}
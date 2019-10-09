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

    Maze maze_creation;
    /*
     * An example in case of I want to modify something in my structure :
     * Maze *pointer = &maze_creation;
     * pointer->height = 55;
    */
    printf("You chose to create a maze.\nPlease enter a size. \n Height : ");
    scanf("%d", &maze_creation.height);
    printf("\n Length : ");
    scanf("%d", &maze_creation.length);

    switch (choice) {
        case 1:
            create_maze(maze_creation);
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
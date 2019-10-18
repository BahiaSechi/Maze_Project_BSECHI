#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameplay.h"

void main() {

    srand(time(NULL));

    int choice = 0;
    Maze maze;
    Maze * ptr = &maze;


    while (choice != 4) {

        choice = menu();

        switch (choice) {
            case 1:
                create_maze(maze);
                break;
            case 2:
                load_maze(maze);
                //printf("Load an existing labyrinth\n");
                break;
            case 3:
                //play_maze(maze);
                break;
            case 4:
                exit(0);
        }
    }

}
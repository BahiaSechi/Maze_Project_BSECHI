#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameplay.h"

void main() {

    srand(time(NULL));

    int choice = menu();

    Maze maze;

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
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
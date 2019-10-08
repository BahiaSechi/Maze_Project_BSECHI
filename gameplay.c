//
// Created by bahia on 07/10/2019.
//

#include "gameplay.h"
#include <stdio.h>
#include <stdlib.h>

int menu() {

    printf("\n#####################\n   MAZE GAME \n#####################\n \n");
    printf("Choose an option : \n");
    printf("   Option 1 : Create a new maze\n");
    printf("   Option 2 : Load an existing maze\n");
    printf("   Option 3 : Play\n");
    printf("   Option 4 : Quit\n\n");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void display_maze (Maze maze_creation) {
    for (int i = 0; i < maze_creation.height; i++)
    {
        for (int j = 0; j < maze_creation.length; j++) {
            if (maze_creation.maze[i][j] != -1){
                printf("%d", maze_creation.maze[i][j]);
            } else {
                printf("%c", '#');
            }
        }
        printf("\n");
    }
}


void create_maze (Maze maze) {

    Maze *pointer = &maze;

    //FIRST INITIALISATION

    int cell_value = 1;
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.length; j++) {
            if (i % 2 != 0 && j % 2 != 0) {
                maze.maze[i][j] = cell_value;
                cell_value++;
            } else {
                //WALL
                maze.maze[i][j] = -1;
            }
        }
    }
    display_maze(maze);

    int random_height = rand() % (maze.height);
    int random_length = rand() % (maze.length);

    if ((maze.maze[random_height][random_length] != -1) &&                   /* If my random cell is a wall and */
        (random_height != maze.height - 1 && random_height != 0) &&          /* my wall is not a border. */
        (random_length != maze.length - 1 && random_length != 0)) {
        random_height = rand() % (maze.height);                              /* I pick a random number. */
        random_length = rand() % (maze.length);
    }

    while (maze.walls_down != (maze.height * maze.length - 1) / 2) {
        if ((maze.maze[random_height - 1][random_length] != -1 && maze.maze[random_height + 1][random_length] != -1)) {     /* If the cells upper and under are not a wall. */
            int val = maze.maze[random_height - 1][random_length] - maze.maze[random_height +1][random_length];             /* I find out which is greater than the other one. */
            if (val < 0) {                                                                                                  /* The case under is greater than the other one. */
                maze.maze[random_height + 1][random_length] = maze.maze[random_height - 1][random_length];
                maze.maze[random_height][random_length] = maze.maze[random_height - 1][random_length];
                pointer->walls_down++;
                printf("COUCOU 1");
                //display_maze(maze);
            } else {
                maze.maze[random_height - 1][random_length] = maze.maze[random_height +
                                                                        1][random_length];                                  /* If the cells (left/right) are not a wall. */
                maze.maze[random_height][random_length] = maze.maze[random_height + 1][random_length];
                pointer->walls_down++;
                printf("COUCOU 2");
                //display_maze(maze);
            }
        } else if (maze.maze[random_height][random_length - 1] != -1 && maze.maze[random_height][random_length + 1]) {
            int val = maze.maze[random_height][random_length - 1] - maze.maze[random_height][random_length + 1];
            if (val < 0) {
                maze.maze[random_height][random_length + 1] = maze.maze[random_height][random_length - 1];
                maze.maze[random_height][random_length] = maze.maze[random_height][random_length - 1];
                pointer->walls_down++;
                printf("COUCOU 3");
                //display_maze(maze);
            } else {
                maze.maze[random_height][random_length - 1] = maze.maze[random_height][random_length + 1];
                maze.maze[random_height][random_length] = maze.maze[random_height][random_length + 1];
                pointer->walls_down++;
                printf("COUCOU 4");
                //display_maze(maze);
            }
        }
    }
    display_maze(maze);
}

void load_maze () {}

void play_maze() {}

void quit_game() {
    exit(0);
};
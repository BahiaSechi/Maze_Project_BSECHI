//
// Created by bahia on 07/10/2019.
//

#include "gameplay.h"
#include <stdio.h>
#include <stdlib.h>

int menu() {

    printf("\n#####################\n      MAZE GAME \n#####################\n \n");
    printf("Choose an option : \n");
    printf("   Option 1 : Create a new maze\n");
    printf("   Option 2 : Load an existing maze\n");
    printf("   Option 3 : Play\n");
    printf("   Option 4 : Quit\n\n");

    int choice;
    printf("   Chosen option : ");
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
    pointer->walls_down = 0;

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

    int rand_up, rand_down, rand_left, rand_right, actual_rand;

    while (maze.walls_down < (maze.height * maze.length - 1) / 2) {

        int random_height = (rand() % (maze.height-2) + 1);
        int random_length = (rand() % (maze.length-2) + 1);

        actual_rand = maze.maze[random_height][random_length];
        rand_up = maze.maze[random_height-1][random_length];
        rand_down = maze.maze[random_height+1][random_length];
        rand_left = maze.maze[random_height][random_length-1];
        rand_right = maze.maze[random_height][random_length+1];

        if (actual_rand != -1)                  /* If my random cell is not a wall */
        {
            random_height = (rand() % (maze.height-2) + 1);                 /* I pick another random number. */
            random_length = (rand() % (maze.length-2) + 1);
        }

        printf("\nRandom height : %d ; Random length : %d ; Cell = %d\n",random_height, random_length, maze.maze[random_height][random_length]);

        if (rand_up != -1 && rand_down != -1) {     /* If the cells upper and under are not a wall. */
            int val = rand_up - rand_down;          /* I find out which is greater than the other one. */
            if (val < 0) {                          /* The case under is greater than the other one. */
                pointer->maze[random_height+1][random_length] = rand_up;
                pointer->maze[random_height][random_length] = rand_up;
                pointer->walls_down++;
                display_maze(maze);
            } else {
                pointer->maze[random_height-1][random_length] = rand_down;                                  /* If the cells (left/right) are not a wall. */
                pointer->maze[random_height][random_length] = rand_down;
                pointer->walls_down++;
                display_maze(maze);
            }
        } else if (rand_left != -1 && rand_right != -1) {
            int val = rand_left - rand_right;
            if (val < 0) {                          /* The right case is greater than the other one. */
                pointer->maze[random_height][random_length+1] = rand_left;
                pointer->maze[random_height][random_length] = rand_left;
                pointer->walls_down++;
                display_maze(maze);
            } else {
                pointer->maze[random_height][random_length-1] = rand_right;
                pointer->maze[random_height][random_length] = rand_right;
                pointer->walls_down++;
                display_maze(maze);
            }
        }
    }
    //display_maze(maze);
}

void load_maze () {}

void play_maze() {}

void quit_game() {
    exit(0);
};
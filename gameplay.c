//
// Created by bahia on 07/10/2019.
//

#include "gameplay.h"
#include "tools.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

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
            if (maze_creation.maze[i][j] != -1 || (i == 1 && j == 0) || (i == maze_creation.height-2 && j == maze_creation.length-1)){
                printf(" ");
            } else {
                printf("█");
            }
        }
        printf("\n");
    }
}

void propagation (Maze * maze, int cell_value, int pos_height, int pos_length) {

    int *up_cell, *down_cell, *left_cell, *right_cell, *actual_cell;

    if ((pos_height < 0 || pos_height > maze->height) || (pos_length < 0 || pos_length > maze->length)) {
        return;
    }

    up_cell = &maze->maze[pos_height-1][pos_length];
    down_cell = &maze->maze[pos_height+1][pos_length];
    left_cell = &maze->maze[pos_height][pos_length-1];
    right_cell = &maze->maze[pos_height][pos_length+1];
    actual_cell = &maze->maze[pos_height][pos_length];

    if (*up_cell != -1 && *up_cell != cell_value) {
        *up_cell = *actual_cell;
        propagation(maze, *up_cell, pos_height-1, pos_length);
    }

    if (*down_cell != -1 && *down_cell != cell_value) {
        *down_cell = *actual_cell;
        propagation(maze, *down_cell, pos_height+1, pos_length);
    }

    if (*left_cell != -1 && *left_cell != cell_value) {
        *left_cell = *actual_cell;
        propagation(maze, *left_cell, pos_height, pos_length-1);
    }

    if (*right_cell != -1 && *right_cell != cell_value) {
        *right_cell = *actual_cell;
        propagation(maze, *right_cell, pos_height, pos_length+1);
    }
}

void init_maze (int height, int length) {

    Maze maze;
    Maze *pointer = &maze;
    pointer->walls_down = 0;
    pointer->height = height;
    pointer->length = length;

    /*
     * Allocating memory for the matrix.
     */
    pointer->maze = malloc(pointer->height * sizeof(int *));
    for (int k = 0; k < pointer->height; k++) {
        pointer->maze[k] = malloc(pointer->length * sizeof(int));
    }

    int cell_value = 1;
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.length; j++) {
            if (i % 2 != 0 && j % 2 != 0) {
                maze.maze[i][j] = cell_value;
                cell_value++;
            } else {
                maze.maze[i][j] = WALL;
            }
        }
    }

    int rand_up, rand_down, rand_left, rand_right, actual_rand;
    int height_min, height_max, length_min, length_max;

    height_min = 1;
    height_max = maze.height-2;
    length_min = 1;
    length_max = maze.length-2;

    while (maze.walls_down < (maze.height/2) * (maze.length/2) - 1) {

        int random_height = (rand() % (height_max + 1 - height_min)) + height_min;
        int random_length = (rand() % (length_max + 1 - length_min)) + length_min;

        actual_rand = maze.maze[random_height][random_length];

        while (actual_rand != WALL)
        {
            random_height = (rand() % (height_max + 1 - height_min)) + height_min;                 /* I pick another random number. */
            random_length = (rand() % (length_max + 1 - length_min)) + length_min;
            actual_rand = maze.maze[random_height][random_length];
        }

        rand_up = maze.maze[random_height - 1][random_length];
        rand_down = maze.maze[random_height + 1][random_length];
        rand_left = maze.maze[random_height][random_length - 1];
        rand_right = maze.maze[random_height][random_length + 1];

        if (rand_up != WALL && rand_down != WALL && rand_up!=rand_down) {     /* If the cells upper and under are not a wall. */
            int val = rand_up - rand_down;          /* I find out which is greater than the other one. */
            if (val < 0) {                          /* The case under is greater than the other one. */
                pointer->maze[random_height + 1][random_length] = rand_up;
                pointer->maze[random_height][random_length] = rand_up;
                propagation(pointer, rand_up, random_height + 1, random_length);
                pointer->walls_down++;
            } else {
                pointer->maze[random_height - 1][random_length] = rand_down;
                pointer->maze[random_height][random_length] = rand_down;
                propagation(pointer, rand_down, random_height - 1, random_length);
                pointer->walls_down++;
            }
        } else if (rand_left != WALL && rand_right != WALL && rand_left!=rand_right){
            int val = rand_left - rand_right;
            if (val < 0) {                          /* The right case is greater than the other one. */
                pointer->maze[random_height][random_length + 1] = rand_left;
                pointer->maze[random_height][random_length] = rand_left;
                propagation(pointer, rand_left, random_height, random_length + 1);
                pointer->walls_down++;
            } else {
                pointer->maze[random_height][random_length - 1] = rand_right;
                pointer->maze[random_height][random_length] = rand_right;
                propagation(pointer, rand_right, random_height, random_length - 1);
                pointer->walls_down++;
            }
        }
    }
    display_maze(maze);

    printf("\nDo you want to save your maze ? Type 1 for Yes, 0 for No.\n");
    int qu_save;
    scanf("%d", &qu_save);
    if (qu_save == 1) {
        save_maze(pointer);
    }
    else {
        exit(0);
    }

}

void create_maze () {

    int height, length;

    printf("You chose to create a maze.\nPlease enter a size. \n Height :\n");
    scanf("%d", &height);
    printf("\n Length :\n");
    scanf("%d", &length);

    empty_buffer();

    init_maze(height, length);
}

void save_maze (Maze * maze) {

    /*
     * Check whether the directory is existent or not.
     * If not, it is created.
     */
    struct stat st = {0};

    if (stat("../mazes", &st) == -1) {
        mkdir("../mazes", 0700);
    }

    char * path = "../mazes/";
    char *chosen_name;
    char * extension = ".cfg";

    chosen_name = (char *) malloc(25*sizeof(char));

    printf("\nChoose a name to save the file : ");
    scanf("%s", chosen_name);

    char * file_name = concat(concat(path, chosen_name), extension);

    FILE *file;
    file = fopen(file_name, "w");

    fprintf(file, "%d %d\n", maze->height, maze->length);

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->length; j++) {
            fprintf(file, "%d ", maze->maze[i][j]);
        }
        fprintf(file,"\n");
    }

    fclose(file);

    free(file_name);

    printf("\nMaze successfully saved !\n");
}

void load_maze (Maze maze_load) {

    Maze * maze = &maze_load;

    struct stat st = {0};

    if (stat("../mazes", &st) == -1) {
        printf("No maze has been saved.\n");
        exit(0);
    } else {
        printf("\nMazes already saved :\n");
        system("ls ../mazes");
    }

    char * load_file;
    load_file = (char *) malloc(25*sizeof(char));

    printf("\nWhich maze do you want to load ? (no extension)\n");
    scanf("%s", load_file);
    printf("\nLoading '%s'...\n", load_file);

    char * path = "../mazes/";
    char * extension = ".cfg";

    char * file_name = concat(concat(path, load_file), extension);

    FILE * file = NULL;
    file = fopen(file_name,"r");

    fscanf(file, "%d %d", &maze->height, &maze->length);

    maze->maze = (int **) malloc(maze->height * sizeof(int *));

    for (int i = 0; i < maze->height ; i++) {
        maze->maze[i] = malloc(maze->length * sizeof(int));
    }

    for (int j = 0; j < maze->height ; j++) {
        for (int i = 0; i < maze->length; i++) {
            fscanf(file, "%d", &maze->maze[j][i]);
        }
        fscanf(file, "\n");
    }
    display_maze(maze_load);

    play_maze(maze_load);

    fclose(file);
}

void play_maze (Maze maze) {

    Player player;
    Maze * ptr_maze = &maze;
    Player * ptr_player = &player;

    ptr_player->height_position = 1;
    ptr_player->length_position = 0;

    for (int i = 0; i < ptr_maze->height; i++) {
        for (int j = 0; j < ptr_maze->length; j++) {
            if (i == ptr_player->height_position && j == ptr_player->length_position) {
                printf("o");
            }
        }
    }

    char entry;

    printf("\nUse z/q/s/d to move.\n");
    scanf("%c", &entry);

    switch (entry) {
        case 'z':
            break;
        case 'q' :
            break;
        case 's' :
            break;
        case 'd' :
            break;
    }


}
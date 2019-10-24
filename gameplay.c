//
// Created by bahia on 07/10/2019.
//

#include "gameplay.h"
#include "tools.h"
#include "player.h"
#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int menu() {

    int choice;

    printf("\n#####################\n      MAZE GAME \n#####################\n \n");
    printf("Choose an option : \n");
    printf("   Option 1 : Create a new maze\n");
    printf("   Option 2 : Load an existing maze\n");
    printf("   Option 3 : Play\n");
    printf("   Option 4 : Quit\n\n");

    printf("   Option chosen : ");

    while (scanf("%d", &choice) != 1) {

        printf("\033[0;31m");
        printf("    \nPlease enter a number between 1 and 4.\n ");
        printf("\033[0m");

        printf("\n#####################\n      MAZE GAME \n#####################\n \n");
        printf("Choose an option : \n");
        printf("   Option 1 : Create a new maze\n");
        printf("   Option 2 : Load an existing maze\n");
        printf("   Option 3 : Play\n");
        printf("   Option 4 : Quit\n\n");

        empty_buffer();
        printf("   Option chosen : ");
    }

    return choice;
}

void display_maze (Maze maze_creation) {
    for (int i = 0; i < maze_creation.height; i++)
    {
        for (int j = 0; j < maze_creation.length; j++) {
            int value = maze_creation.maze[i][j];

            switch (value) {
                case PLAYER :
                    printf("\033[0;34m");
                    printf("o");
                    printf("\033[0m");
                    break;
                case TREASURE :
                    printf("\033[0;33m");
                    printf("x");
                    printf("\033[0m");
                    break;
                case WALL :
                    printf("█");
                    break;
                case TRAP :
                    printf("\033[0;31m");
                    printf("x");
                    printf("\033[0m");
                    break;
                default :
                    printf(" ");
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
    Player player;
    Player * ptr_player = &player;

    pointer->walls_down = 0;
    pointer->height = height;
    pointer->length = length;

    ptr_player->height_position = 1;
    ptr_player->length_position = 0;

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

    pointer->maze[ptr_player->height_position][ptr_player->length_position] = PLAYER;
    pointer->maze[height_max][length_max+1] = OUT;

    int treasure, nb_treasure, treasure_i, treasure_j, maze_size;
    int trap, nb_trap, trap_i, trap_j;

    maze_size = maze.height * maze.length;

    nb_treasure = maze_size / 30;
    nb_trap = maze_size / 45;

    treasure = 0;
    trap = 0 ;

    while (treasure < nb_treasure) {
        treasure_i = (rand() % (height_max + 1 - height_min)) + height_min;
        treasure_j = (rand() % (length_max + 1 - length_min)) + length_min;

        if (pointer->maze[treasure_i][treasure_j] == NORMAL) {
        pointer->maze[treasure_i][treasure_j] = TREASURE;

        treasure++;
        }
    }

    while (trap < nb_trap) {
        trap_i = (rand() % (height_max + 1 - height_min)) + height_min;
        trap_j = (rand() % (length_max + 1 - length_min)) + length_min;

        if (pointer->maze[trap_i][trap_j] == NORMAL) {
            pointer->maze[trap_i][trap_j] = TRAP;

            trap++;
        }
    }

    display_maze(maze);

    //TODO VERIFY ENTRIES
    printf("\nDo you want to save your maze ? Type 1 for Yes, 0 for No.\n");
    int qu_save;
    while (scanf("%d", &qu_save) != 1) {
        printf("\033[0;31m");
        printf("Please enter a number between 0 and 1.\n");
        printf("\033[0m");
        printf("\nDo you want to save your maze ? Type 1 for Yes, 0 for No.\n");
        empty_buffer();
    }
    if (qu_save == 1) {
        save_maze(pointer);
    }
}

void create_maze () {

    int height, length;

    printf("You chose to create a maze.\nPlease enter a size. \n Height :\n");
    while (scanf("%d", &height) != 1 || height%2 != 1) {
        printf("\033[0;31m");
        printf("Please enter an odd height.\n");
        printf("\033[0m");
        empty_buffer();
    }
    printf("\n Length :\n");
    while (scanf("%d", &length) != 1 || length%2 != 1) {
        printf("\033[0;31m");
        printf("Please enter an odd length.\n");
        printf("\033[0m");
        empty_buffer();
    }
    printf("\n");

    empty_buffer();

    init_maze(height, length);
}

void save_maze (Maze * maze) {

    /*
     * Check whether the directory is existent or not.
     * If not, it is created.
     */
    //TODO WINDOWS
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
    file = fopen(file_name, "wb");

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

    sleep(1);

    clear_console();
}

Maze load_maze (Maze maze_load) {

    Maze *maze = &maze_load;

    //TODO WINDOWS
    struct stat st = {0};

    if (stat("../mazes", &st) == -1) {
        printf("No maze has been saved.\n");
    } else {
        printf("\nMazes already saved :\n\n");
        system("ls -1 ../mazes");

        char *load_file;
        load_file = (char *) malloc(25 * sizeof(char));

        printf("\nWhich maze do you want to load ? (no extension)\n");
        scanf("%s", load_file);

        char *path = "../mazes/";
        char *extension = ".cfg";

        char *file_name = concat(concat(path, load_file), extension);

        if (stat(file_name, &st) == -1) {
            printf("\nThe maze named %s has not been created. Choose the option 1 in the menu to create it.\n", concat(load_file, extension));
        } else {
            printf("\nLoading '%s.cfg'...\n", load_file);

            maze->name = load_file;

            FILE *file = NULL;
            file = fopen(file_name, "r");

            fscanf(file, "%d %d", &maze->height, &maze->length);

            maze->maze = (int **) malloc(maze->height * sizeof(int *));

            for (int i = 0; i < maze->height; i++) {
                maze->maze[i] = malloc(maze->length * sizeof(int));
            }

            for (int j = 0; j < maze->height; j++) {
                for (int i = 0; i < maze->length; i++) {
                    fscanf(file, "%d", &maze->maze[j][i]);
                }
                fscanf(file, "\n");
            }
        }
    }
    sleep(1);
    clear_console();
    return maze_load;
}

void play_maze(Maze maze, char * maze_name) {

    Player player;
    Maze * ptr_maze = &maze;
    Player * ptr_player = &player;
    int score;

    display_maze(maze);

    score = (maze.height * maze.length)*8;

    ptr_player->height_position = 1;
    ptr_player->length_position = 0;

    while (ptr_maze->maze[ptr_player->height_position-1][ptr_player->length_position] != OUT && ptr_maze->maze[ptr_player->height_position+1][ptr_player->length_position] != OUT
            && ptr_maze->maze[ptr_player->height_position][ptr_player->length_position+1] != OUT)
    {

    char entry;

    printf("\nUse z/q/s/d to move.\n Type m to go back to the menu and p to quit the game.\n");

        empty_buffer();
        scanf("%c", &entry);

        switch (entry) {
            case 'z':
                if (ptr_maze->maze[ptr_player->height_position-1][ptr_player->length_position] != WALL) {
                    if (ptr_maze->maze[ptr_player->height_position-1][ptr_player->length_position] == TREASURE) {
                        score += 20;
                    }
                    if (ptr_maze->maze[ptr_player->height_position-1][ptr_player->length_position] == TRAP) {
                        score -= 20;
                    }
                    ptr_maze->maze[ptr_player->height_position-1][ptr_player->length_position] = ptr_maze->maze[ptr_player->height_position][ptr_player->length_position];
                    ptr_player->height_position = ptr_player->height_position-1;
                    ptr_maze->maze[ptr_player->height_position+1][ptr_player->length_position] = NORMAL;
                    score -= 10;
                }
                else {
                    printf("\033[1;31m");
                    printf("\nYou cannot move upwards.\n");
                    printf("\033[0m");
                }
                break;
            case 'q' :
                // Conditions so we can not go out of the maze thanks to the enter.
                if (ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] == NORMAL || ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] == TRAP
                    || ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] == TREASURE) {
                    if (ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] == TREASURE) {
                        score += 20;
                    }
                    if (ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] == TRAP) {
                        score -= 20;
                    }
                    ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] = ptr_maze->maze[ptr_player->height_position][ptr_player->length_position];
                    ptr_player->length_position = ptr_player->length_position - 1;
                    ptr_maze->maze[ptr_player->height_position][ptr_player->length_position+1] = NORMAL;
                    score -= 10;
                } else {
                    printf("\033[1;31m");
                    printf("\nYou cannot move to the left.\n");
                    printf("\033[0m");
                }
                break;
            case 's' :
                if (ptr_maze->maze[ptr_player->height_position+1][ptr_player->length_position] != WALL) {
                    if (ptr_maze->maze[ptr_player->height_position+1][ptr_player->length_position] == TREASURE) {
                        score += 20;
                    }
                    if (ptr_maze->maze[ptr_player->height_position+1][ptr_player->length_position] == TRAP) {
                        score -= 20;
                    }
                    ptr_maze->maze[ptr_player->height_position+1][ptr_player->length_position] = ptr_maze->maze[ptr_player->height_position][ptr_player->length_position];
                    ptr_player->height_position = ptr_player->height_position+1;
                    ptr_maze->maze[ptr_player->height_position-1][ptr_player->length_position] = NORMAL;
                    score -= 10;
                } else {
                    printf("\033[1;31m");
                    printf("\nYou cannot move downwards.\n");
                    printf("\033[0m");
                }
                break;
            case 'd' :
                if (ptr_maze->maze[ptr_player->height_position][ptr_player->length_position+1] == TREASURE) {
                    score += 20;
                }
                if (ptr_maze->maze[ptr_player->height_position][ptr_player->length_position+1] == TRAP) {
                    score -= 20;
                }
                if (ptr_maze->maze[ptr_player->height_position][ptr_player->length_position+1] != WALL) {
                    ptr_maze->maze[ptr_player->height_position][ptr_player->length_position+1] = ptr_maze->maze[ptr_player->height_position][ptr_player->length_position];
                    ptr_player->length_position = ptr_player->length_position + 1;
                    ptr_maze->maze[ptr_player->height_position][ptr_player->length_position-1] = NORMAL;
                    score -= 10;
                } else {
                    printf("\033[1;31m");
                    printf("\nYou cannot move to the right.\n");
                    printf("\033[0m");
                }
                break;
            case 'p' :
                exit(0);
            case 'm' :
                return;
        }
        clear_console();
        display_maze(maze);
        printf("\n Score : %d\n", score);

    }
    printf("\033[0;32m");
    printf("\n YOU WIN WITH THE SCORE %d!\n", score);
    printf("\033[0m");

    ptr_player->name = (char *) malloc(25*sizeof(char));

    printf("\nWhat is your name ?\n");
    scanf("%s", ptr_player->name);

    save_score(ptr_player->name, maze_name, score);

    clear_console();
}
//
// Created by bahia on 16/10/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "files_io.h"
#include "tools.h"

void save_maze (Maze maze) {

    Maze * maze_pointer = &maze;

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

    chosen_name = (char *) malloc(MAX_NAME*sizeof(char));

    printf("\nChoose a name to save the file : \n");
    scanf("%s", chosen_name);

    char * file_name = concat(concat(path, chosen_name), extension);

    FILE *file;
    file = fopen(file_name, "w");

    for (int i = 0; i < maze_pointer->height; i++) {
        for (int j = 0; j < maze_pointer->length; j++) {
            fprintf(file, "%d ", maze_pointer->maze[i][j]);
        }
        fprintf(file,"\n");
    }

    fclose(file);

    //TODO load_file(); once the maze is saved

    free(file_name);

    printf("\nMaze successfully saved !\n");
}

void load_maze_choice (Maze maze) {

    struct stat st = {0};

    if (stat("../mazes", &st) == -1) {
        printf("No maze has been saved.\n");
        exit(0);
    } else {
        printf("\nMazes already saved :\n");
        system("ls ../mazes");
    }

    char * load_file;
    load_file = (char *) malloc(MAX_NAME*sizeof(char));

    printf("\nWhich maze do you want to load ? (no extension)\n");
    scanf("%s", load_file);
    printf("\nLoading '%s'...\n", load_file);

    char * path = "../mazes/";
    char * extension = ".cfg";

    char * file_name = concat(concat(path, load_file), extension);

    load_maze(maze, file_name);
}


void load_maze (Maze maze, char * load_file) {

    Maze * pointer = &maze;

    FILE *file;
    file = fopen(load_file, "r");

    pointer->maze = malloc(pointer->height * sizeof(int *));
    for (int k = 0; k < pointer->height; k++) {
        pointer->maze[k] = malloc(pointer->length * sizeof(int));
    }

    for (int i = 0; i < pointer->height ; ++i) {
        for (int j = 0 ; j < pointer->length ; j++) {
            fscanf(file, "%d", &pointer->maze[i][j]);
        }
        fscanf(file, "\n");
    }

    fclose(file);

}

void play_maze() {}
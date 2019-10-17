//
// Created by bahia on 16/10/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "files_io.h"
#include "tools.h"

#define MAX_NAME 25

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

    chosen_name = (char *) malloc(MAX_NAME * sizeof(char));

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

void load_maze () {}

void play_maze() {}
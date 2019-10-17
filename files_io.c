//
// Created by bahia on 16/10/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "files_io.h"
#include "tools.h"

void save_maze(Maze maze) {

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

    chosen_name = (char *) malloc(20*sizeof(char));

    printf("\nChoose a name to save the file : ");
    scanf("%s", chosen_name);

    char * file_name = concat(concat(path, chosen_name), extension);

    FILE *file;
    file = fopen(file_name, "w");

    for (int i = 0; i < maze_pointer->height; i++) {
        for (int j = 0; j < maze_pointer->length; j++) {
            if (maze.maze[i][j] != -1 || (i == 1 && j == 0) || (i == maze.height - 2 && j == maze.length - 1)) {
                fprintf(file, " ");
            } else {
                fprintf(file, "█");
            }
        }
        fprintf(file,"\n");
    }

    fclose(file);

    free(file_name);

    printf("\nMaze successfully saved !\n");
}

void load_maze () {}

void play_maze() {}
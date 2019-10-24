//
// Created by bahia on 21/10/2019.
//

#include "score.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void save_score(char *player_name, char *maze_name, int score) {

    //TODO WINDOWS
    struct stat st = {0};

    if (stat("../scores", &st) == -1) {
        mkdir("../scores", 0700);
    }

    char *path = "../scores/";
    char *extension = ".score";

    char *score_file = concat(concat(path, maze_name), extension);

    FILE *file;
    file = fopen(score_file, "a");

    fprintf(file, "%s : %d\n", player_name, score);

    fclose(file);

    free(score_file);

    printf("\nScore successfully saved !\n");

    display_score(maze_name);
    sleep(5);
}

void display_score(char *maze_name) {

    char *path = "../scores/";
    char *extension = ".score";
    char *player_name;
    int score;
    player_name = (char *) malloc(25 * sizeof(char));

    char *file_name = concat(path, concat(maze_name, extension));

    FILE *file = NULL;
    file = fopen(file_name, "r");

    while (!feof(file)) {
        fscanf(file, "%s : %d", player_name, &score);
        printf("%s : %d\n", player_name, score);
    }

    fclose(file);
}
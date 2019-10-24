//
// Created by bahia on 21/10/2019.
//

#include "score.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

void save_score (char * player_name, char * maze_name, int score) {

    printf("Name : %s\nScore : %d\n", player_name, score);

    //TODO WINDOWS
    struct stat st = {0};

    if (stat("../scores", &st) == -1) {
        mkdir("../scores", 0700);
    }

    char * path = "../scores/";
    char * extension = ".score";

    char * score_file = concat(concat(path, maze_name), extension);

    printf("Score file : %s\n", score_file);

    FILE *file;
    file = fopen(score_file, "a");

    fprintf(file, "%s : %d\n", player_name, score);

    fclose(file);

    free(score_file);

    printf("Score successfully saved !");
}
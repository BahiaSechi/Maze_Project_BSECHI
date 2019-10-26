/**
 * Address :
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex

 * Note :
 * This file is owned by an ENSICAEN student. No portion of this
 * document may be reproduced, copied  or revised without written
 * permission of the authors.

 * @author Bahia SECHI <bahia.sechi@ecole.ensicaen.fr>

 * @date October 2019

 * @file score.c
 * @version 1.0
 *
 * @brief Functions to manage the scores
 */

#include "score.h"
#include "tools.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * @fn void save_score(char *player_name, char *maze_name, int score)
 * @brief Function allowing to save the score in a file
 *
 * @param player_name The name of the player to save
 * @param maze_name The name of the played maze
 * @param score The score of the player to save
 *
 * @bug Unsure about this but I think I need to manage the creation of a directory on Windows.
 * @bug I need to save only the 10 best scores.
 */
void save_score(char *player_name, char *maze_name, int score) {

    struct stat st = {0};

    if (stat("../scores", &st) == -1) {
        if (OSlinux() ==1) mkdir("../scores", 0700);
        //TODO WINDOWS
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

/**
 * @fn void display_score (char *maze_name)
 * @brief Display the scores of a specific maze
 *
 * @param maze_name The name of the maze
 *
 * @bug When I call display_score from save_score, the score saved is printed two times.
 */
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
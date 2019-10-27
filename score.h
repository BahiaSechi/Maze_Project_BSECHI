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

 * @file score.h
 * @version 1.0
 *
 * @brief Header which defines the functions to manage the scores
 */

#ifndef MAZE_PROJECT_BSECHI_SCORE_H
#define MAZE_PROJECT_BSECHI_SCORE_H

#endif //MAZE_PROJECT_BSECHI_SCORE_H

/**
 * @fn void save_score(char *player_name, char *maze_name, int score)
 * @brief Function allowing to save the score in a file
 *
 * @param player_name The name of the player to save
 * @param maze_name The name of the played maze
 * @param score The score of the player to save
 */
void save_score(char *player_name, char *maze_name, int score);

/**
 * @fn void display_score (char *maze_name)
 * @brief Display the scores of a specific maze
 *
 * @param maze_name The name of the maze
 */
void display_score(char *maze_name);
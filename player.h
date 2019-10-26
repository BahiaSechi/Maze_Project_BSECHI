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

 * @file player.h
 * @version 1.0
 *
 * @brief Header which defines the structure Player
 */

#ifndef MAZE_PROJECT_BSECHI_PLAYER_H
#define MAZE_PROJECT_BSECHI_PLAYER_H

#endif //MAZE_PROJECT_BSECHI_PLAYER_H

/*
 * The height position represents the number of the line.
 * The length position represents the number of the column.
 */

/**
 * @struct Player player.h
 * @brief The structure of a Player
 *
 * A player is defined with a name and a position.
 * He/She also has a score updated when playing.
 */
typedef struct {
    char *name;
    int height_position;
    int length_position;
    int score;
} Player;

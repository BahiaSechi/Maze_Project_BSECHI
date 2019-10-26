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

 * @file tools.c
 * @version 1.0
 *
 * @brief Header of functions that are useful in several sources of the whole project
 */

#ifndef MAZE_PROJECT_BSECHI_TOOLS_H
#define MAZE_PROJECT_BSECHI_TOOLS_H

#endif //MAZE_PROJECT_BSECHI_TOOLS_H

/**
 * @fn void empty_buffer ()
 * @brief A function allowing the user to empty the input buffer. See also : TD1.
 */
void empty_buffer();

/**
 * @fn char * concat (char * first_string, char * scd_string)
 * @brief Allows two strings to be concatenated.
 *
 * @param first_string is the first string to concatenate
 * @param scd_string is the first second to concatenate
 * @return The string which is the two first parameters concatenated
 */
char * concat(char * first_string, char * scd_string);

/**
 * @fn int OSlinux ()
 * @brief Detect the user's OS
 *
 * @return 0 is the OS is Windows, 1 otherwise
 */
int OSlinux ();

/**
 * @fn void clear_console ()
 * @brief Clears the console when this function is called
*/
void clear_console ();
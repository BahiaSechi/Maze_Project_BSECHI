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
 * @brief Some functions that are useful in several sources of the whole project
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

/**
 * @fn void empty_buffer ()
 * @brief A function allowing the user to empty the input buffer. See also : TD1.
 */
void empty_buffer () {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * @fn char * concat (char * first_string, char * scd_string)
 * @brief Allows two strings to be concatenated.
 *
 * @param first_string is the first string to concatenate
 * @param scd_string is the first second to concatenate
 * @return The string which is the two first parameters concatenated
 */
char * concat (char * first_string, char * scd_string) {
    const size_t len1 = strlen(first_string);
    const size_t len2 = strlen(scd_string);
    char * result = malloc(len1 + len2 + 1);
    memcpy(result, first_string, len1);
    memcpy(result + len1, scd_string, len2 + 1);
    return result;
}

/**
 * @fn int OSlinux ()
 * @brief Detect the user's OS
 *
 * @return 0 is the OS is Windows, 1 otherwise
 */
int OSlinux () {
#if defined __WIN_32
    return 0;
#else
    return 1;
#endif
}

/**
 * @fn void clear_console ()
 * @brief Clears the console when this function is called
*/
void clear_console () {
    if (OSlinux() == 1) {
        system("clear");
    } else {
        system("cls");
    }
/*TODO remove this if it works on Windows
#if defined __WIN32__
    system ("cls");
#else
    system("clear");
#endif
 */
}
//
// Created by bahia on 16/10/2019.
//

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

char * concat(char * first_string, char * scd_string) {
    const size_t len1 = strlen(first_string);
    const size_t len2 = strlen(scd_string);
    char * result = malloc(len1 + len2 + 1);
    memcpy(result, first_string, len1);
    memcpy(result + len1, scd_string, len2 + 1);
    return result;
}

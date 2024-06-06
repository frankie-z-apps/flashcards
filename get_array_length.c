#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_array_length.h"

/*
get length of an array of strings
REQUIRE: NULL sentinel value as last elem of array
*/
int get_array_length(char **arr) 
{
    if (!arr) {
        fprintf(stderr, "Not a valid array.\n");
        return 1;
    }
    
    int count = 0;
    while (arr[count] != NULL) {
        count++;
    }

    return count;
}
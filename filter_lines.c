#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
//#define INITIAL_ARRAY_SIZE 5

int get_array_size(char **arr);

/*
given an array of strings, exclude the strings beginning with a letter
(every question for the flashcards begins with an "-" character)
then return a new array with just the selected strings (the questions)
*/

char **filter_lines(char **rawlines)
{
    char **filtered_lines = NULL;
    char buffer[MAX_LINE_LENGTH];
    int array_size = get_array_size(rawlines);

}

int get_array_size(char **arr) 
{
    if (!arr) {
        fprintf(stderr, "Not a valid array.\n");
        return 1;
    }

    int len = 0;
    char *str = arr;

    while (str != NULL) {
        len++;
        str++;
    }

    return len;
}
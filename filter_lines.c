#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int get_array_length(char **arr);
int is_whitechar(char c);

/*
given an array of strings, exclude the strings beginning with a letter
(every question for the flashcards begins with an "-" character)
then return a new array with just the selected strings (the questions)
*/

char **filter_lines(char **rawlines)
{
    char **filtered_lines = NULL;
    char buffer[MAX_LINE_LENGTH];
    int array_size = get_array_length(rawlines); // at most, length of raw array
    int line = 0;

    filtered_lines = malloc(array_size * sizeof(char *));
    if (!filtered_lines) {
        fprintf(stderr, "Error while allocating memory.\n");
        return 1;
    }
 
    /*
    Verify if the string is a valid question:
     if so, accept it -> copy it in filtered lines 
     (else, do nothing)
     */
    for (line; line < array_size; line++) {
        char c = getc(rawlines[line]);
        while (is_whitechar(c)) {
            c = getc(rawlines[line]);
        }
        // c is now the first non-white char of line
        
        if (c = '-') { // valid line
            fgets(buffer, MAX_LINE_LENGTH, rawlines[line]);
            filtered_lines[line] = malloc((strlen(buffer) + 1) * sizeof(char));
            if (!filtered_lines[line]) {
                fprintf(stderr, "Error while allocating memory for line.\n");
                return 2;
            }
            strcpy(filtered_lines[line], buffer);
        }
    }

    return filtered_lines;
}
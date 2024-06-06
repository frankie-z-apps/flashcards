#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "is_whitespace.h"
#include "get_array_length.h"

#define MAX_LINE_LENGTH 1024

int get_array_length(char **arr);
int is_whitechar(char c);

/*
given an array of strings, exclude the strings beginning with a letter
(every question for the flashcards begins with an "-" character)
then return a new array with just the selected strings (the questions)
REQUIRE: NULL as last element of array.
*/
char **filter_lines(char **rawlines)
{
    char **filtered_lines = NULL;
    int array_size = get_array_length(rawlines); // at most, length of raw array
    int valid_lines_count = 0;

    filtered_lines = malloc(array_size * sizeof(char *));
    if (!filtered_lines) {
        fprintf(stderr, "Error while allocating memory.\n");
        return NULL;
    }
 
    /*
    Verify if the string is a valid question:
     if so, accept it -> copy it in filtered lines 
     (else, do nothing)
     */
    for (int line = 0; line < array_size; line++) {
        char *string = rawlines[line];
        //printf("Line number %d of raw-lines: %s\n. Current char(c): %c.\n", line, string, *string);
        char c = *string;
        if (c) {
            while (is_whitechar(c)) {
                //printf("In the while loop, current char -> %c\n", c);
                string++;
                c = *string;
            }
            // c is now the first non-white char of line
            //printf("Exiting the while loop, current value of c: %c.\n", c);

            if (c == '-') { // valid line
                //printf("The line at index %d is valid!\n", line);
                int line_len = strlen(rawlines[line]);
                filtered_lines[valid_lines_count] = malloc((line_len + 1) * sizeof(char));
                if (!filtered_lines[valid_lines_count]) {
                    fprintf(stderr, "Error while allocating memory for valid line.\n");
                    return NULL;
                }
                strcpy(filtered_lines[valid_lines_count], rawlines[line]);
                //printf("Once copied, the line '%s' has been copied in filtered_lines at index %d -> '%s'.\n", rawlines[line], valid_lines_count, filtered_lines[valid_lines_count]);
                valid_lines_count++;
            }
            /*
            else {
                printf("Line at index %d is NOT valid!\n", line);
            }
            */
            
        }
        
    }
    return filtered_lines;
}


/* Testing
int main() 
{
    char *raw_example[] = {
        "first sentence", 
        "\t - second sentence",
        "third sentence",
        "\t  \tfourth sentence",
        "",
        "\n-fifth sentence",
        "sixth sentence",
        NULL
        };

    char **filtered_lines = filter_lines(raw_example);
    int filtered_len = get_array_length(filtered_lines);

    for (int i=0; i < filtered_len; i++) {
        printf("Line %d:\n%s\n", i, filtered_lines[i]);
    }

    return 0;
}
*/
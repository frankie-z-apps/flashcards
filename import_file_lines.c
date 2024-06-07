#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "import_file_lines.h"

#define MAX_LINE_LENGTH 1024
#define INITIAL_ARRAY_SIZE 5

/*
Given an OPEN file,
get all file lines and put them
in an array of strings <- returned value
*/
char **import_file_lines(FILE *file)
{
    char **lines = NULL;
    char buffer[MAX_LINE_LENGTH];
    int array_size = INITIAL_ARRAY_SIZE;
    int line_count = 0;

    // Allocate initial memory for array of lines
    lines = malloc(array_size * sizeof(char *));
    if (!lines) {
        fprintf(stderr, "Error while allocating memory.\n");
        fclose(file);
        return NULL;
    }

    // Copy every line in the array
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        // Remove newline if present
        buffer[strcspn(buffer, "\n")] = '\0';

        if (line_count >= array_size) {
            array_size *= 2 + 1;
            lines = realloc(lines, array_size * sizeof(char *));
            if (!lines) {
                fprintf(stderr, "Error while reallocating memory.\n");
                fclose(file);
                return NULL;
            }
        }

        // allocate memory for the current line and store it
        lines[line_count] = malloc((strlen(buffer) + 1) * sizeof(char));
        if (!lines[line_count]) {
            fprintf(stderr, "Error while allocating memory for line.\n");
            fclose(file);
            return NULL;
        }
        strcpy(lines[line_count], buffer);

        line_count++;
    }

    // Add a NULL sentinel value indicating end of list
    if (line_count >= array_size) {
        array_size++; // Adding just one more line;
        lines = realloc(lines, array_size * sizeof(char *));
        if (!lines) {
            fprintf(stderr, "Error while reallocating memory.\n");
            fclose(file);
            return NULL;
        }
    }
    lines[line_count] = NULL;
    
    line_count++;

    // Close file
    fclose(file);

    return lines;
}
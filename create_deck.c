#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "create_deck.h"
#include "import_file_lines.h"
#include "filter_lines.h"
#include "get_array_length.h"


char **create_deck(char *filename)
{           
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error while opening file %s. Please try again.\n", filename);
        return NULL;
    }

    // file is valid
    char **raw_lines = import_file_lines(file);
    if (!raw_lines) {
        fprintf(stderr, "Error while importing lines from file %s. Please try again.\n", filename);
        return NULL;
    }

    // lines are stored 
    char **filtered_lines = filter_lines(raw_lines);
    if (!raw_lines) {
        fprintf(stderr, "Error while filtering lines.\n");
        return NULL;
    }

    return filtered_lines;
}

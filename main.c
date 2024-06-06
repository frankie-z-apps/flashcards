#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "import_file_lines.h"
#include "filter_lines.h"
#include "get_array_length.h"


int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Correct usage: %s [filename].\n", argv[0]);
        return 1;
    }

    // if given filename is valid, get lines
    char *filename = argv[1];
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error while opening file %s. Please try again.\n", filename);
        return 2;
    }

    // file is valid
    char **raw_lines = import_file_lines(file);
    if (!raw_lines) {
        fprintf(stderr, "Error while importing lines from file %s. Please try again.\n", filename);
        return 3;
    }

    // lines are stored 
    char **filtered_lines = filter_lines(raw_lines);
    if (!raw_lines) {
        fprintf(stderr, "Error while filtering lines.\n");
        return 4;
    }

    int filtered_len = get_array_length(filtered_lines);

    // print test
    for (int i=0; i<filtered_len; i++) {
        printf("Filtered[%d]: %s.\n", i, filtered_lines[i]);
    }
    
    return 0;
}

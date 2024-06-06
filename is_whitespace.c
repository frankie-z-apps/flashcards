#include <stdio.h>

#include "is_whitespace.h"

int is_whitespace(char c)
{
    char newline = '\n';
    char tab = '\t';
    char space = ' ';

    return c == newline || c == tab || c == space;
}
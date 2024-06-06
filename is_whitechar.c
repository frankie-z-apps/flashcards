#include <stdio.h>

int is_whitechar(char c)
{
    char newline = '\n';
    char tab = '\t';
    char space = ' ';

    return c != newline && c != tab && c != space;
}
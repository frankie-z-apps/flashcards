#include <stdio.h>
#include <string.h>

#include "create_deck.h"

#define MAX_INPUT_LENGTH 1024

int main(int argc, char const *argv[])
{
    char user_input[MAX_INPUT_LENGTH] = { };

    fprintf(stdout, "Please insert text filename from which to extract card texts, then press ENTER: >");
    
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    user_input[strcspn(user_input, "\n")] = '\0';

    char **deck = create_deck(user_input);

    while (*deck) {
        fprintf(stdout, "%s\n", *deck);
        deck++;
    }

    return 0;
}
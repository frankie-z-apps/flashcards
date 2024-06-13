#include <stdio.h>
#include <string.h>

#include "start_menu.h"
#include "play_deck.h"
#include "fill_deck.h"

#define MAX_INPUT_LENGTH 1024

int play_game(char **deck);
char **load_deck(char *input);

int main(int argc, char const *argv[])
{
    int user_choice = start_menu();
    char load_deck_filename[MAX_INPUT_LENGTH] = { };
    char new_deck_filename[MAX_INPUT_LENGTH] = { };

    if (user_choice == 2) {
        printf("Well, see ya!\n");
        return 0;
    } else if (user_choice == 1) {
        fprintf(stdout, "Please insert your deck filename, then press ENTER: >");
        fgets(load_deck_filename, MAX_INPUT_LENGTH, stdin);
        load_deck_filename[strcspn(load_deck_filename, "\n")] = '\0';
        char **loaded_deck = load_deck(load_deck_filename);
        play_game(loaded_deck);
    } else if (user_choice == 0) {
        while (getchar() != '\n');
        fprintf(stdout, "Please insert text filename from which to extract card texts, then press ENTER: >");
        fgets(new_deck_filename, MAX_INPUT_LENGTH, stdin);
        new_deck_filename[strcspn(new_deck_filename, "\n")] = '\0';
        
        struct Deck deck = fill_deck(new_deck_filename);

        play_deck(deck);
    }
    return 0;
}


char **load_deck(char *input) {
    printf("Deck is now loaded!\n");
    return NULL;
} 

int play_game(char **deck) {
    printf("Playing game...\n");
    return 0;
}
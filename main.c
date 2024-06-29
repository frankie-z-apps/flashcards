#include <stdio.h>
#include <string.h>

#include "start_menu.h"
#include "play_deck.h"
#include "fill_deck.h"
#include "load_deck.h"

#define MAX_INPUT_LENGTH 1024

int play_game(char **deck);

int main(int argc, char const *argv[])
{
    struct Deck deck;
    int user_choice = start_menu();
    char load_deck_filename[MAX_INPUT_LENGTH] = { };
    char new_deck_filename[MAX_INPUT_LENGTH] = { };

    if (user_choice == 2) {
        printf("Well, see ya!\n");
        return 0;
    } else if (user_choice == 1) {
        while (getchar() != '\n');
        fprintf(stdout, "Please insert your deck filename, then press ENTER:\n>");
        fgets(load_deck_filename, MAX_INPUT_LENGTH, stdin);
        load_deck_filename[strcspn(load_deck_filename, "\n")] = '\0';
        int load_deck_result = load_deck(load_deck_filename, &deck);
        if (load_deck_result) {
            return load_deck_result;
        }
    } else if (user_choice == 0) {
        while (getchar() != '\n');
        fprintf(stdout, "Please insert text filename from which to extract card texts, then press ENTER: >");
        fgets(new_deck_filename, MAX_INPUT_LENGTH, stdin);
        new_deck_filename[strcspn(new_deck_filename, "\n")] = '\0';
        
        deck = fill_deck(new_deck_filename);
    }
    play_deck(&deck);
    return 0;
}

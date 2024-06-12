#include <stdio.h>
#include <string.h>

#include "create_deck.h"
#include "shuffle_deck.h"
#include "start_menu.h"
#include "play_game.h"

#define MAX_INPUT_LENGTH 1024

int play_game(char **deck);
char **load_deck(char *input);

int main(int argc, char const *argv[])
{
    int user_choice = start_menu();
    char user_input[MAX_INPUT_LENGTH] = { };

    if (user_choice == 2) {
        printf("Well, see ya!\n");
        return 0;
    } else if (user_choice == 1) {
        fprintf(stdout, "Please insert your deck filename, then press ENTER: >");
        fgets(user_input, MAX_INPUT_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        char **loaded_deck = load_deck(user_input);
        play_game(loaded_deck);
    } else if (user_choice == 0) {
        while (getchar() != '\n');
        fprintf(stdout, "Please insert text filename from which to extract card texts, then press ENTER: >");
        fgets(user_input, MAX_INPUT_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';
        char **deck = create_deck(user_input);
        
        // Now I want to shuffle the deck
        char **shuffled_deck = shuffle_deck(deck);

        /* test for shuffled deck
        while (*shuffled_deck) {
            fprintf(stdout, "%s\n", *shuffled_deck);
            shuffled_deck++;
        }
        //*/
        play_game(shuffled_deck);
    }
    return 0;
}


char **load_deck(char *input) {
    printf("Deck is now loaded!\n");
    return NULL;
} 
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "play_game.h"
#include "get_array_length.h"


int insert_card(char **deck, int feedback);

int play_game(char **deck)
{
    int feedback = 0;

    while (1) {
        printf("%s\n", *deck);
        while (1) {
            printf("Evaluate your answer: (input 0-9)\n");
            int choice = scanf("%d", &feedback);
            if (choice == 1 && feedback >= 0 && feedback <= 9) {
                break;
            } else {
                printf("Please insert a value between 0 and 9.\n");
                while (getchar() != '\n');
            }
        }
        insert_card(deck, feedback);
    }

    return 0;
}

int insert_card(char **deck, int feedback)
{
    feedback++;
    int index = 0;
    char *temp = deck[0];
    
    int deck_size = get_array_length(deck);
    double index_ratio = deck_size / 10.0;

    index = (int) ceil(feedback * index_ratio);
    if (index >= deck_size) {
        index--;
    }
    for (int i=0; i<index; i++) {
        deck[i] = deck[i+1];
    }
    deck[index] = temp;

    return 0;
}

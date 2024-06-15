#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fill_deck.h"
#include "import_file_lines.h"
#include "filter_lines.h"
#include "get_array_length.h"
#include "shuffle_deck.h"
#include "card.h"
#include "deck.h"


struct Deck fill_deck(char *filename)
{           
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error while opening file %s. Please try again.\n", filename);
        exit(1);
    }

    // file is valid
    char **raw_lines = import_file_lines(file);
    if (!raw_lines) {
        fprintf(stderr, "Error while importing lines from file %s. Please try again.\n", filename);
        exit(2);
    }

    // lines are stored 
    char **filtered_lines = filter_lines(raw_lines);
    if (!raw_lines) {
        fprintf(stderr, "Error while filtering lines.\n");
        exit(3);
    }

    char **shuffled_lines = shuffle_deck(filtered_lines);

    struct Deck deck;
    deck.size = get_array_length(shuffled_lines);
    deck.cards = (struct Card*)malloc(deck.size * sizeof(struct Card));
    int i = 0;

    while (*shuffled_lines) {
        strcpy(deck.cards[i].question, *shuffled_lines);
        strcpy(deck.cards[i].answer, "This question has not an answer yet. Press <m> to modify this text.");
        shuffled_lines++;
        i++;
    }

    return deck;
}

/*
int main()
{
    char *filename = "test.txt";
    struct Deck deck = fill_deck(filename);

    printf("Deck size = %d\n", deck.size);

    for (int i=0; i<deck.size; i++) {
        printf("%s\n", deck.cards[i].question);
    }

    return 0;
}
*/
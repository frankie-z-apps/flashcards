#include <stdio.h>
#include <stdlib.h>

#include "deck.h"
#include "load_deck.h"


int load_deck(const char *filename, struct Deck *deck) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file for reading");
        return 1;
    }

    // Read the size of the deck first
    fread(&deck->size, sizeof(deck->size), 1, file);

    // Read the cards
    fread(deck->cards, sizeof(struct Card), deck->size, file);

    fclose(file);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "deck.h"
#include "card.h"

#include "save_deck.h"


int save_deck(struct Deck *deck, const char *filename) {
    printf("Saving...\n");
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file for writing\n");
        return 1;
    }

    if (fwrite(&deck->size, sizeof(deck->size), 1, file) != 1) {
        fprintf(stderr, "Failed to write deck size\n");
        fclose(file);
        return 2;
    }

    if (fwrite(deck->cards, sizeof(struct Card), deck->size, file) != deck->size) {
        fprintf(stderr, "Failed to write cards\n");
        fclose(file);
        return 3;
    }

    fclose(file);
    sleep(1);
    printf("Deck saved successfully to %s\n", filename);
    return 0;
}

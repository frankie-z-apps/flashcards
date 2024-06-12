#ifndef DECK_H
#define DECK_H

#include "card.h"

#define MAX_DECK_SIZE 1000

struct Deck
{
    struct Card cards[MAX_DECK_SIZE];
    int size;
};


#endif
#ifndef DECK_H
#define DECK_H

#include "card.h"

#define MAX_DECK_SIZE 1000

struct Deck
{
    int size;
    struct Card *cards;
    
};


#endif
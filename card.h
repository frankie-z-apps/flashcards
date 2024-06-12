#ifndef CARD_H
#define CARD_H

#define MAX_STRING_LENGTH 1024

struct Card
{
    char question[MAX_STRING_LENGTH];
    char answer[MAX_STRING_LENGTH];
};

#endif
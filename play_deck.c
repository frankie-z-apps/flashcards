#include <stdio.h>
#include <math.h>
#include <string.h>

#include "play_deck.h"
#include "deck.h"
#include "card.h"


struct Deck insert_card(struct Deck deck, int feedback);

int play_deck(struct Deck deck)
{
    char view_answer = ' ';
    char modify_answer = ' ';
    char buffer[MAX_STRING_LENGTH] = { };
    int feedback = 0;
    
    printf("Deck size: %d\n", deck.size);

    while (1) {
        printf("\n%s\n\n", deck.cards[0].question);

        while (1) {
            printf("\nPress <Enter> to view answer\n");
            int input = scanf("%c", &view_answer);
            if (input == 1 && view_answer == '\n') {
                printf("Answer:\n\n%s\n\n", deck.cards[0].answer);
                break;
            }
        }

        while (1) {
            printf("\nPress <m> to modify the answer for this card\nPress <Enter> to continue\n");
            int input = scanf("%c", &modify_answer);
            if (input == 1 && modify_answer == '\n') {
                break;
            } else if (input == 1 && modify_answer == 'm' || modify_answer == 'M') {
                while (getchar() != '\n');
                printf("Enter new answer, then press <Enter>\n>");                
                fgets(buffer, MAX_STRING_LENGTH, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                strcpy(deck.cards[0].answer, buffer);
                break;
            } else {
                printf("Invalid input, press <m> or <Enter> to continue.\n>");
                while (getchar() != '\n');
            }
        }

        while (1) {
            printf("\nEvaluate your answer: (input 0-9)\n>");
            int choice = scanf("%d", &feedback);
            if (choice == 1 && feedback >= 0 && feedback <= 9) {
                break;
            } else {
                printf("Please insert a value between 0 and 9.\n");
                while (getchar() != '\n');
            }
        }
        deck = insert_card(deck, feedback);
        while(getchar() != '\n');
    }

    return 0;
}


struct Deck insert_card(struct Deck deck, int feedback)
{
    feedback++;
    int index = 0;
    struct Card temp = deck.cards[0];
    double index_ratio = deck.size / 10.0;

    if (fmod(feedback * index_ratio, 1.0) != 0.0) {
        index = (int) feedback * index_ratio + 1;
    } else {
        index = (int) feedback * index_ratio;
    }
    if (index >= deck.size) {
        index--;
    }
    for (int i=0; i<index; i++) {
        deck.cards[i] = deck.cards[i+1];
    }
    deck.cards[index] = temp;

    return deck;
}


/*
int main()
{
    struct Deck deck;
    deck.size = 4;

    struct Card card1;
    struct Card card2;
    struct Card card3;
    struct Card card4;

    strcpy(card1.question, "Is this the real life?");
    strcpy(card2.question, "Is this just fantasy?");
    strcpy(card3.question, "Does it really matters to me?");
    strcpy(card4.question, "Do you wear wigs?");
    strcpy(card1.answer, "Maybe");
    strcpy(card2.answer, "Could be");
    strcpy(card3.answer, "Only by searching you will find answers to your questions.");
    strcpy(card4.answer, "No I do not.");

    deck.cards[0] = card1;
    deck.cards[1] = card2;
    deck.cards[2] = card3;
    deck.cards[3] = card4;

    play_deck(deck);

    
    for (int i=0; i<deck.size; i++) {
        printf("Question:\n\t%s\nAnswer:\n\t%s\n", deck.cards[i].question, deck.cards[i].answer);
    }


    return 0;
}
//*/
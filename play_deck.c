#include <stdio.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "save_deck.h"
#include "play_deck.h"
#include "deck.h"
#include "card.h"


struct Deck insert_card(struct Deck deck, int feedback);
int saving_prompt(struct Deck *deck);


int play_deck(struct Deck *deck)
{
    char buffer[MAX_STRING_LENGTH] = { };
    int feedback = -1;

    while (1) {
        printf("\n%s\n\n", deck->cards[0].question);

        while (1) {
            printf("\nPress <Enter> to view answer\n");
            char input = getchar();
            if (input == '\n') {
                printf("Answer:\n\n%s\n\n", deck->cards[0].answer);
                break;
            }
            while (getchar() != '\n');
        }

        while (1) {
            printf("\nPress <m> to modify the answer for this card\nPress <Enter> to continue\n");
            char input = getchar();
            if (input == '\n') {
                break;
            } else if (input == 'm' || input == 'M') {
                while (getchar() != '\n');
                printf("Enter new answer, then press <Enter>\n>");
                fgets(buffer, MAX_STRING_LENGTH, stdin);
                buffer[strcspn(buffer, "\n")] = '\0';
                strcpy(deck->cards[0].answer, buffer);
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
        *deck = insert_card(*deck, feedback);
        while(getchar() != '\n');

        while (1) {
            printf("Press <Enter> to continue, <x> to exit.\n");
            char input = getchar();
            if (input == '\n') {
                break;
            } else if (input == 'x' || input == 'X') {
                while (getchar() != '\n');
                saving_prompt(deck);
                return 0;
            } else {
                while (getchar() != '\n');
            }
        }
    }
}


struct Deck insert_card(struct Deck deck, int feedback)
{
    feedback++;
    int index = 0;
    struct Card temp = deck.cards[0];
    double index_ratio = deck.size / 10.0;

    index = (int) ceil(feedback * index_ratio);
    if (index >= deck.size) {
        index--;
    }
    for (int i=0; i<index; i++) {
        deck.cards[i] = deck.cards[i+1];
    }
    deck.cards[index] = temp;

    return deck;
}


int saving_prompt(struct Deck *deck) {
    while (1) {
        printf("Do you want to save the deck before exiting? (y/n)\n");
        char save = getchar();
        if (save == 'y') {
            while (getchar() != '\n');
            // Initialize the local buffer to 0
            char filename[256] = {};
            printf("Enter filename to save the deck:\n>");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';
            save_deck(deck, filename);
            exit(0);
        } else if (save == 'n') {
            printf("Goodbye then!\n");
            exit(0);
        } else {
            printf("Press <y>/<n> to save/exit.\n");
            while (getchar() != '\n');
        }
    }
    return 0;
}


/*
int main()
{
    struct Deck main_deck;
    main_deck.size = 4;

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

    main_deck.cards = (struct Card*)malloc(main_deck.size * sizeof(struct Card));

    main_deck.cards[0] = card1;
    main_deck.cards[1] = card2;
    main_deck.cards[2] = card3;
    main_deck.cards[3] = card4;

    play_deck(&main_deck);

    free(main_deck.cards);

    return 0;
}
//*/

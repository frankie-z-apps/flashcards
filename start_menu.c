#include <stdio.h>

#include "start_menu.h"

int display_welcome_message();
int display_choices();
int is_valid_input(int n);


int start_menu() 
{
    display_welcome_message();
    int choice;

    while (1) {
        display_choices();
        int result = scanf("%d", &choice);

        if (result == 1 && is_valid_input(choice)) {
            break;
        } else {
            printf("Invalid selection, please try again.\n");
            while (getchar() != '\n');
        }
    }
    return choice;
}


int display_welcome_message()
{
    fprintf(stdout, "Dear Player, welcome to this mighty flashcards game, home of fun and knowledge!\n");
    return 0;
}


int display_choices()
{
    fprintf(stdout, "[0] - New game\n[1] - Load previous game\n[2] - Exit\n\n");
    return 0;
}


int is_valid_input(int n)
{
    return n == 0 || n == 1 || n == 2;
}
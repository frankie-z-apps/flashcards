#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shuffle_deck.h"
#include "get_array_length.h"

int generate_random_int(int b);
int *randomize_indexes(int n);

/*
Get an array of strings,
copy the strings in a new array,
randomize the order of entries,
RETURN randomized (shuffled) array
*/
char **shuffle_deck(char **deck)
{
    char **shuffled = NULL;
    int deck_size = get_array_length(deck);

    shuffled = malloc((deck_size + 1) * sizeof(char *));
    if (!shuffled) {
        fprintf(stderr, "Error while allocating memory for shuffled deck.\n");
        exit(1);
    }

    int *randomized_indexes = randomize_indexes(deck_size);

    for (int i=0; i<deck_size; i++) {
        int string_length = strlen(deck[randomized_indexes[i]]);
        shuffled[i] = malloc(string_length * sizeof(char));
        strcpy(shuffled[i], deck[randomized_indexes[i]]);
    }

    shuffled[deck_size] = NULL;
    return(shuffled);
}


/*
Generate a random number in range [0, b]
excluding b
*/
int generate_random_int(int b)
{
    int random_int = 0;
    FILE *urandom = fopen("/dev/urandom", "rb");
    if (!urandom) {
        fprintf(stderr, "Error while opening file '/dev/urandom'.\n");
        exit(1);
    }
    fread(&random_int, sizeof(int), 1, urandom);
    fclose(urandom);

    return abs(random_int) % b;
}


/*
Vefify if a value n is already present in an array of values before the index i
*/
int is_already_in_array(int n, int *values, int i)
{
    for (int j=0; j<i; j++) {
        if (values[j] == n) {
            return 1;
        }
    }
    return 0;
}


/*
Generate an array of n random, non repetitive values in range [0, n-1]
*/
int *randomize_indexes(int n)
{
    int *indexes = NULL;
    indexes = malloc(n * sizeof(int));

    for (int i=0; i<n; i++) {
        int random = generate_random_int(n);
        while (is_already_in_array(random, indexes, i)) {
            random = generate_random_int(n);
        }
        indexes[i] = random;
    }
    return indexes;
}


/* test
int main() 
{
    char *my_deck[] = {
        "first",
        "second",
        "third",
        "fourth",
        "fifth",
        "sixth",
        NULL
    };

    char **shuffled = shuffle_deck(my_deck);

    while (*shuffled) {
        printf("%s.\n", *shuffled);
        shuffled++;
    }

    return 0;
}
//*/

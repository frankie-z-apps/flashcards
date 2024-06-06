Simple implementation of a terminal-based application for the flashcard method.

Concept:

    I   -   Given a text file, whithin which we expect to find at least some 
            lines of the form "(whitespace) - Generic flashcard question (whitespace)",
            the program will filter those (valid) lines and put them randomly in the 
            'flashcard deck'.

    II  -   Once set up, the 'game' is ready to begin:
            A card will be drawn from the deck -> the question will be displayed
            on terminal;
            the user takes some time to answer (in future developement we can think of a time based implementation, for now just let the user think peacefully);

    III -   The user evaluates his answer (he has to imput a value between 0 and 9);
            based on this evaluation (score), the card is re-inserted in a portion of the deck
            so that the higher the feedback (user) value, the further the position in the
            deck from the top (following the principle that if one already knows well a subject,
            he needs to improve on it less)


Further developement:

    -   For now the application doesn't provide the 'back side' of the flashcard, i.e. the ideal answer
        to the given question; it shouldn't be that hard to add later;

    -   As already said, it would be nice to add some timer to keep things interesting (and to add a feeling of real-life test);
    
    -   It could be added some form of indication of the current progress, e.g. the discovered card percent on the total, or the current / global(between sessions) user score;



Author: Francesco Zappalà
2024.06.06
# Define the compiler
CC = clang

# Object file dependencies
FILL_DECK_O = fill_deck.o
PLAY_DECK_O = play_deck.o
IMPORT_FILE_LINES_O = import_file_lines.o
FILTER_LINES_O = filter_lines.o
GET_ARRAY_LENGTH_O = get_array_length.o
IS_WHITESPACE_O = is_whitespace.o
CREATE_DECK_O = create_deck.o
SHUFFLE_DECK_O = shuffle_deck.o
START_MENU_O = start_menu.o
#PLAY_GAME_O = play_game.o
MAIN_O = main.o

# Header files
HEADERS = import_file_lines.h filter_lines.h get_array_length.h is_whitespace.h create_deck.h shuffle_deck.h start_menu.h fill_deck.h play_deck.h play_game.h deck.h card.h

# Target (executable)
.PHONY: main

main: $(IMPORT_FILE_LINES_O) $(FILTER_LINES_O) $(GET_ARRAY_LENGTH_O) $(IS_WHITESPACE_O) $(CREATE_DECK_O) $(SHUFFLE_DECK_O) $(START_MENU_O) $(PLAY_GAME_O) $(FILL_DECK_O) $(PLAY_DECK_O) $(MAIN_O)
	$(CC) $(LDFLAGS) $(IMPORT_FILE_LINES_O) $(FILTER_LINES_O) $(GET_ARRAY_LENGTH_O) $(IS_WHITESPACE_O) $(CREATE_DECK_O) $(SHUFFLE_DECK_O) $(START_MENU_O) $(PLAY_GAME_O) $(FILL_DECK_O) $(PLAY_DECK_O) $(MAIN_O) -o main -lm

# Object files
$(FILL_DECK_O): $(HEADERS) fill_deck.c
	$(CC) -c fill_deck.c

$(PLAY_DECK_O): $(HEADERS) play_deck.c
	$(CC) -c play_deck.c

$(START_MENU_O): $(HEADERS) start_menu.c
	$(CC) -c start_menu.c

$(PLAY_GAME_O): $(HEADERS) play_game.c
	$(CC) -c play_game.c

$(CREATE_DECK_O): $(HEADERS) create_deck.c
	$(CC) -c create_deck.c

$(SHUFFLE_DECK_O): $(HEADERS) shuffle_deck.c
	$(CC) -c shuffle_deck.c

$(IMPORT_FILE_LINES_O): $(HEADERS) import_file_lines.c
	$(CC) -c import_file_lines.c

$(FILTER_LINES_O): $(HEADERS) filter_lines.c
	$(CC) -c filter_lines.c

$(GET_ARRAY_LENGTH_O): $(HEADERS) get_array_length.c
	$(CC) -c get_array_length.c

$(IS_WHITESPACE_O): $(HEADERS) is_whitespace.c
	$(CC) -c is_whitespace.c

$(MAIN_O): $(HEADERS) main.c
	$(CC) -c main.c

# Phony target for make clean
.PHONY: clean

clean:
	rm -f $(IMPORT_FILE_LINES_O) $(FILTER_LINES_O) $(GET_ARRAY_LENGTH_O) $(IS_WHITESPACE_O) $(CREATE_DECK_O) $(SHUFFLE_DECK_O) $(START_MENU_O) $(PLAY_GAME_O) $(FILL_DECK_O) $(PLAY_DECK_O) $(MAIN_O) main
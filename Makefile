#main: import_file_lines.o filter_lines.o main.o
#	clang import_file_lines.o filter_lines.o main.o -o main
#import_file_lines.o: import_file_lines.h import_file_lines.c
#	clang -c import_file_lines.c
#filter_lines.o: filter_lines.h get_array_length.h is_whitespace.h
#	clang -c filter_lines.c
#get_array_length.o: get_array_length.h get_array_length.c
#	clang -c get_array_length.c
#is_whitespace.o: is_whitespace.h is_whitespace.c
#	clang -c is_whitespace.c
#main.o: import_file_lines.h filter_lines.h get_array_length.h main.c

# Define the compiler
CC = clang

# Object file dependencies
IMPORT_FILE_LINES_O = import_file_lines.o
FILTER_LINES_O = filter_lines.o
GET_ARRAY_LENGTH_O = get_array_length.o
IS_WHITESPACE_O = is_whitespace.o
CREATE_DECK_O = create_deck.o
MAIN_O = main.o

# Header files
HEADERS = import_file_lines.h filter_lines.h get_array_length.h is_whitespace.h create_deck.h

# Target (executable)
.PHONY: main

main: $(IMPORT_FILE_LINES_O) $(FILTER_LINES_O) $(GET_ARRAY_LENGTH_O) $(IS_WHITESPACE_O) $(CREATE_DECK_O) $(MAIN_O)
	$(CC) $(LDFLAGS) $(IMPORT_FILE_LINES_O) $(FILTER_LINES_O) $(GET_ARRAY_LENGTH_O) $(IS_WHITESPACE_O) $(CREATE_DECK_O) $(MAIN_O) -o main

$(CREATE_DECK_O): $(HEADERS) create_deck.c
	$(CC) -c create_deck.c

# Object files
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
	rm -f $(IMPORT_FILE_LINES_O) $(FILTER_LINES_O) $(GET_ARRAY_LENGTH_O) $(IS_WHITESPACE_O) $(CREATE_DECK_O) $(MAIN_O) main
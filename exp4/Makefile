CC=gcc
CFLAGS=-Wall

all: command_line_args system_calls library_functions

command_line_args: command_line_args.c
	$(CC) $(CFLAGS) -o command_line_args command_line_args.c

system_calls: system_calls.c
	$(CC) $(CFLAGS) -o system_calls system_calls.c

library_functions: library_functions.c
	$(CC) $(CFLAGS) -o library_functions library_functions.c

clean:
	rm -f command_line_args system_calls library_functions

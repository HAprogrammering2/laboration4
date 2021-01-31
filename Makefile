# Makefile for our session tracker

# Variables section
SRC = date.c sessionlist.c tracker.c
OBJ = date.o sessionlist.o tracker.o
BIN = tracker

# Compiler settings
#CFLAGS = -Wall -pedantic -D DEBUGON
CFLAGS = -Wall -pedantic 
CC = gcc

# Targets section
date.o: date.c date.h 
	$(CC) $(CFLAGS) -c -o date.o date.c 

sessionlist.o: sessionlist.c date.h sessionlist.h debug.h
	$(CC) $(CFLAGS) -c -o sessionlist.o sessionlist.c

tracker.o: tracker.c date.h sessionlist.h debug.h
	$(CC) $(CFLAGS) -c -o tracker.o tracker.c 

# Implicit target for object files
#%.o: %.c
#	$(CC) $(CFLAGS) -c -o $@ $< 
#
# Target for the binary
$(BIN): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

clean:
	rm -rf $(OBJ) $(BIN)

all: $(BIN)

.DEFAULT_GOAL := all
# Variables 
OBJ = date.o sessionlist.o tracker.o
TESTOBJ = datetest.o sessionlisttest.o
CFLAGS = -Wall -pedantic

# Operating system dependent variables
ifeq ($(OS), Windows_NT)
RM = del
BIN = tracker.exe datetest.exe sessionlisttest.exe
EXEEXT = .exe
else
RM = rm
BIN = tracker datetest sessionlisttest
EXEEXT = 
endif

# Targets
#%.o: %.c
#	gcc $(CFLAGS) -c $< -o $@

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c -o date.o

sessionlist.o: sessionlist.c sessionlist.h date.h debug.h
	gcc $(CFLAGS) -c sessionlist.c -o sessionlist.o

tracker.o: tracker.c date.h sessionlist.h debug.h
	gcc $(CFLAGS) -c tracker.c -o tracker.o


tracker$(EXEEXT): date.o sessionlist.o tracker.o
	gcc $(CFLAGS) $(OBJ) -o tracker

all: tracker$(EXEEXT) datetest$(EXEEXT) sessionlisttest$(EXEEXT)

clean:
	$(RM) $(BIN) $(OBJ) $(TESTOBJ)

# -----------------
# TEST TARGETS
# -----------------
datetest.o: datetest.c date.o
	gcc $(CFLAGS) -c datetest.c -o datetest.o

sessionlisttest.o: sessionlisttest.c sessionlist.o date.o
	gcc $(CFLAGS) -c sessionlisttest.c -o sessionlisttest.o

datetest$(EXEEXT): datetest.o
	gcc $(CFLAGS) datetest.o date.o -o datetest

sessionlisttest$(EXEEXT): sessionlisttest.o
	gcc $(CFLAGS) sessionlisttest.o sessionlist.o date.o -o sessionlisttest

test: datetest$(EXEEXT) sessionlisttest$(EXEEXT)

runtest: datetest$(EXEEXT) sessionlisttest$(EXEEXT)
	./datetest$(EXEEXT)
	./sessionlisttest$(EXEEXT)

.DEFAULT_GOAL := all

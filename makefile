#! bin/sh

SRC:=quicksort.c
OBJ:= $(SRC:%.c=%.o) # e.g:  hello.c ==> hello.o 
EXE:= $(SRC:%.c=%)   # e.g:  hello.c ==> hello

# Programs, flags, etc.
CC=gcc
CFLAGS= -gdwarf-2 -g3 -W -Wall -Wshadow -Wreturn-type -Wno-unused-parameter -fno-common\
	-Wtrigraphs -Wformat -Wparentheses -Wpointer-arith 
CLINKS= -pthread 
all:
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CLINKS) $(OBJ) -o $(EXE)
	rm -f *.o
r:
	@./$(EXE)

clean:
	rm -f $(EXE)

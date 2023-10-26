SRC=main.c
LIBS=-lSDL2 -lSDL2_ttf
INC=-I/usr/include/SDL2
CC=gcc
OUTPUT=HelloWorld

all:
	$(CC) $(INC) $(LIBS) src/$(SRC) -o $(OUTPUT) 

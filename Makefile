PROJECT_NAME 		= bars
PROJECT_DESCRIPTION = Bars - A simple example using Box 2D
PROJECT_VERSION 	= 1.0

BOX2D_CFLAGS 		= `pkg-config --cflags box2d`
BOX2D_LIBS 			= `pkg-config --libs box2d`

SDL_CFLAGS          = `pkg-config --cflags sdl2`
SDL_LIBS            = -L/usr/lib/x86_64-linux-gnu `pkg-config --libs sdl2`

SEIDEL_CFLAGS       = -I inc/seidel-0.2
SEIDEL_LIBS			= lib/seidel-0.2.a

CC					= g++
CFLAGS     			= -std=c++1z -c -Wall -g $(BOX2D_CFLAGS) $(SDL_CFLAGS) $(SEIDEL_CFLAGS)
LDFLAGS    			= $(BOX2D_LIBS) $(SDL_LIBS) $(SEIDEL_LIBS)

UNITS      			= main

SRC       			:= $(addsuffix .cpp, $(addprefix src/, $(UNITS)))
OBJ       			:= $(addsuffix .o, $(addprefix bin/, $(UNITS)))

bars: setup $(SEIDEL_LIBS) $(OBJ)
	$(CC) -o $(PROJECT_NAME) $(OBJ) $(LDFLAGS)

bin/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

setup:
	@mkdir -p bin 2> /dev/null

debug:
	@echo $(SRC)
	@echo $(OBJ)

clean:
	rm -f bin/*.o
	rm -f bin/*.a

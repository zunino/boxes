PROJECT_NAME 		= bars
PROJECT_DESCRIPTION = Bars - A simple example using Box 2D
PROJECT_VERSION 	= 1.0

BOX2D_CFLAGS 		= -I/usr/include/Box2D
BOX2D_LIBS 			= -lBox2D

SDL_CFLAGS          = -D_REENTRANT -I/usr/include/SDL2
SDL_LIBS            = -lSDL2

SEIDEL_CFLAGS       = -I inc/seidel-0.2
SEIDEL_LIB			= lib/seidel-0.2.a

CC					= g++
CFLAGS     			= -std=c++1z -c -Wall -g $(BOX2D_CFLAGS) $(SDL_CFLAGS) $(SEIDEL_CFLAGS)
LDFLAGS    			= $(BOX2D_LIBS) $(SDL_LIBS)

UNITS      			= main

SRC       			:= $(addsuffix .cpp, $(addprefix src/, $(UNITS)))
OBJ       			:= $(addsuffix .o, $(addprefix bin/, $(UNITS)))

bars: setup $(OBJ)
	$(CC) -o $(PROJECT_NAME) $(OBJ) $(SEIDEL_LIB) $(LDFLAGS)

bin/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

setup:
	@echo Setting up...
	@mkdir -p bin 2> /dev/null
	@cp ../Seidel/bin/seidel-0.2.a lib

debug:
	@echo $(SRC)
	@echo $(OBJ)

clean:
	@echo Cleaning up...
	@rm -f bin/*.o
	@rm -f bin/*.a

CPP=g++
RM=rm -f
CFLAGS=-g -std=c++11

SRC = playboard.cpp keyboard-event.cpp game.cpp main.cpp snakeGenerator.cpp fruitGenerator.cpp
OBJ = $(SRC:.cpp=.o)

snake : $(OBJ)
	$(CPP) $^ -o $@

# les dépendances
playboard.o : playboard.cpp playboard.h keyboard-event.h
keyboard-event.o : keyboard-event.cpp keyboard-event.h
game.o : game.cpp game.h playboard.h
main.o : main.cpp game.h
snakeGenerator.o : snakeGenerator.cpp snakeGenerator.h playboard.h
fruitGenerator.o : fruitGenerator.cpp snakeGenerator.h

%.o:%.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) *.o snake

.PHONY: clean

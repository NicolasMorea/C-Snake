#include <iostream>
#include <vector>
#include "keyboard-event.h"


// nombre de lignes et de colonne du board
extern int rows;
extern int columns;

extern int MS; // milli-secondes

// vecteur représentant le board
extern std::vector<char> board;

// ré-initialise le board
void reset_board();

// dessine le board
void draw_board();

// dessine le serpent sur le board
void add_snake_to_board(std::vector<int> &snake);

void add_fruit_to_board(int pos);

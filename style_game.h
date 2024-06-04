#ifndef STYLE_GAME_H
#define STYLE_GAME_H
#include <ncurses.h>
#include "board.h"
#include "tetramini.h"

void set_colors();
void print_gamespace(WINDOW *win);
void print_griglia(WINDOW* win, Board &griglia, tetramino* point);
WINDOW* set_win();

#endif
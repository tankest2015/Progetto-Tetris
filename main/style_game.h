#ifndef STYLE_GAME_H
#define STYLE_GAME_H
#include <ncurses.h>
#include "board.h"
#include "tetramini.h"

void set_colors(bool flag);
void print_gamespace(WINDOW *win);
void print_griglia(WINDOW* win, Board &griglia);
WINDOW* set_win();
void flicker_row(WINDOW* win, Board &griglia, int row);

#endif
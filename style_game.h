#ifndef STYLE_GAME_H
#define STYLE_GAME_H
#include <ncurses.h>
#include "board.h"
#include "tetramini.h"

void set_colors(bool flag);
void print_gamespace(WINDOW *win);
void print_griglia(WINDOW* win, Board &griglia);
void flicker_row(WINDOW* win, Board &griglia, int row);
WINDOW* set_win();
WINDOW* set_predict_window();
void predict_window(WINDOW* win, tetramino* next_point);
WINDOW* set_info_window();
void info_window(WINDOW* win, Board &griglia);

#endif
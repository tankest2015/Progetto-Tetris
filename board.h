#ifndef BOARD_H
#define BOARD_H
class tetramino;

#include "tetramini.h"
#include "style_game.h"
#include <iostream>
#include <ncurses.h>

struct Coordinate{
    int x, y;
};

class Board {
    private:
        const int row_size = 10;
        const int col_size = 20;
    public:
        int score = 0;
        int completed_rows = 0;
        Board(int score, int completed_rows);
        int matrix[20][10];

        void init_matrix();
        void print_matrix();
        bool is_full(int row);
        bool is_empty(int row);
        void move_row_down(int row, int n_rows);
        void clear_row(int row);
        int get_row_col_size(bool flag);
};

int max_y(tetramino* point);
void update_score_and_rows(int l_cleared, Board &griglia);
void clear_full_rows(tetramino* point, Board &griglia, WINDOW* win);
bool is_game_over(tetramino* point, Board &griglia);
#endif
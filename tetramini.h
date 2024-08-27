#ifndef TETRAMINI_H
#define TETRAMINI_H
class Board;

#include "board.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

struct Position {
    int x;
    int y;
};

class tetramino {
protected:
        int colour;
        int rot_id;
public:
        Position p1, p2, p3, p4;                //componente x = colonne
                                                //componente y = righe
        tetramino(int colour, Board &griglia);

        int get_colour();
        void print_colour();
        bool control_rot(char C, Board &griglia);
        void left_rotation(Board &griglia);
        void right_rotation(Board &griglia);
        bool move_right(Board &griglia);
        bool move_left(Board &griglia);
        void board_delete_assign (bool action, Board &griglia, int color);
        bool descend(Board &griglia);
};

    tetramino* gen_tetramino(Board &griglia);
    void swap_tetramino_pointer(tetramino* &point, tetramino* &next_point, Board &griglia);    

#endif
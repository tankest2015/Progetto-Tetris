#ifndef TETRAMINI_H
#define TETRAMINI_H

struct Position {
    int x;
    int y;
};

class tetramino {
    protected:
        int colour;
public:
        Position p1, p2, p3, p4;

        tetramino(int colour);

        int get_colour();
        void print_colour();
        void print_griglia();
        tetramino* gen_tetramino();
        void rotation_left(tetramino* point);
        void move_left(tetramino* point);
};

#endif

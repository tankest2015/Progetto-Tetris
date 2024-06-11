#include "tetramini.h"
#include "board.h"
#include "style_game.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

int main(){

    initscr();
    noecho();
    curs_set(0);

    
    tetramino *pointer;
    Board griglia(0);
    pointer = gen_tetramino(griglia);
    WINDOW* win = set_win();
    if(!has_colors) mvwprintw(win, 40, 10, "Daltonico");
    set_colors();
    print_gamespace(win);
    print_griglia(win, griglia, pointer);

    keypad(win, true);
    int movement;
    do{
        movement = wgetch(win);
        switch (movement)
        {
        case KEY_LEFT:
            pointer->move_left(griglia);
            break;

        case KEY_RIGHT:
            pointer->move_right(griglia);
            break;
        
        case 97:
            pointer->left_rotation(griglia);
            break;

        case 100:
            pointer->right_rotation(griglia);
            break;

        default:
            break;
        }

        print_griglia(win, griglia, pointer);
    } while (movement != 113);

    endwin();
    return 0;
}
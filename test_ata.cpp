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

    //keypad(win, true);
    //int movement = wgetch(win);
    char c;
    do{
        c = wgetch(win);
        switch (c)
        {
        case 'a':
            pointer->move_left(griglia);
            break;

        case 'd':
            pointer->move_right(griglia);
            break;
        
        case 'n':
            pointer->left_rotation(griglia);
            break;

        case 'm':
            pointer->right_rotation(griglia);
            break;

        default:
            break;
        }
        print_griglia(win, griglia, pointer);
    } while (c != 'q');

    endwin();
    return 0;
}
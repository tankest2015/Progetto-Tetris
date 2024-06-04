#include <iostream>
#include "style_game.h"


using namespace std;

void set_colors(){
    start_color();
    
    init_color(8, 918, 457, 82);

    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, 8, 8);
}

void print_gamespace(WINDOW *win){
    box(win, 0, 0);
    wrefresh(win);
    }

void print_griglia(WINDOW* win, Board &griglia, tetramino* point){
    print_gamespace(win);
    wmove(win, 1, 1);
    int curr_y = 1;
    int curr_x = 1;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(griglia.matrix[i][j] == 1)
            {
                wattron(win, COLOR_PAIR(point->get_colour())); 
                wprintw(win, "[]");
                wrefresh(win);
                wattroff(win, COLOR_PAIR(point->get_colour()));
            }
            else{
                wprintw(win, "  ");
                wrefresh(win);
            }
            curr_x += 2;
        }
        curr_x = 1;
        curr_y ++;
        wmove(win, curr_y, curr_x);
    }
}

WINDOW* set_win(){
    int height = 22;
    int width = 22;
    WINDOW* win = newwin(height, width, 0, 0);
    return(win);
}

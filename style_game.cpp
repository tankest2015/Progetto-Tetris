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
    init_pair(7, 8, 8);                     //orange
    init_pair(8, COLOR_BLACK, COLOR_BLACK); //for flicker_row()
    init_pair(9, COLOR_WHITE, COLOR_WHITE); //for flicker_row()
}

void print_gamespace(WINDOW *win){
    box(win, 0, 0);
    wrefresh(win);
    }

void print_griglia(WINDOW* win, Board &griglia){
    print_gamespace(win);
    wmove(win, 1, 1);
    int curr_y = 1;
    int curr_x = 1;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(griglia.matrix[i][j] != 0)
            {
                wattron(win, COLOR_PAIR(griglia.matrix[i][j])); 
                wprintw(win, "[]");
                wrefresh(win);
                wattroff(win, COLOR_PAIR(griglia.matrix[i][j]));
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

void flicker_row(WINDOW *win, Board &griglia, int row){
    wmove(win, row, 1);
    int i = 0;
    while (i < 3) {
        for (int j = 0; j < griglia.get_row_col_size(true); j++){
            wattron(win, COLOR_PAIR(9)); //linea bianca
            wprintw(win, "[]");
            wrefresh(win);
            wattroff(win, COLOR_PAIR(9));

            wtimeout(win, 3000);

            wattron(win, COLOR_PAIR(8));  //linea negra
            wprintw(win, "[]");
            wrefresh(win);
            wattroff(win, COLOR_PAIR(8));
        }
        wtimeout(win, 3000);
        i++;
    }
    /*chgat(-1, 9, COLOR_PAIR(9), NULL);
    wrefresh(win);
    wtimeout(win, 500);
    chgat(-1, 8, COLOR_PAIR(8), NULL);
    wrefresh(win);
    wtimeout(win, 500);
    chgat(-1, 9, COLOR_PAIR(9), NULL);
    wrefresh(win);
    wtimeout(win, 500);
    chgat(-1, 8, COLOR_PAIR(8), NULL);
    wrefresh(win);
    wtimeout(win, 500);*/
}

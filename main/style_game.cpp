#include "style_game.h"

using namespace std;

void set_colors(bool flag){
    start_color();

    init_color(8, 918, 457, 82);    //inizializzazione colore arancione
    if(flag){

        init_pair(1, COLOR_RED, COLOR_RED);
        init_pair(2, COLOR_GREEN, COLOR_GREEN);
        init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(4, COLOR_BLUE, COLOR_BLUE);
        init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(6, COLOR_CYAN, COLOR_CYAN);
        init_pair(7, 8, 8);                     //orange
    }
    else{
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, 8, COLOR_BLACK);           //orange
    }
    init_pair(8, COLOR_BLACK, COLOR_BLACK);     //per flicker_row()
    init_pair(9, COLOR_WHITE, COLOR_WHITE);     //per flicker_row()

    init_pair(10, COLOR_GREEN, COLOR_BLACK);    //per personalizzare il colore della scritta
    init_pair(11, COLOR_YELLOW, COLOR_BLACK);   //del livello di difficoltà
    init_pair(12, COLOR_RED, COLOR_BLACK);
    init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
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

void flicker_row(WINDOW *win, Board &griglia, int row){
    wmove(win, row, 1);
    int i = 0;
    bool flag = true;
    while (i < 4) {
        for (int j = 0; j < griglia.get_row_col_size(true); j++){
            if(flag){       //linea bianca
                griglia.matrix[row][j] = 9;
            }
            else{           //linea nera
                griglia.matrix[row][j] = 8;
            }
        }
        flag = !flag;
        print_griglia(win, griglia);
        napms(150);
        i++;
    }
}

WINDOW* set_win(){
    int height = 22;
    int width = 22;
    WINDOW* win = newwin(height, width, 7, 56);
    return(win);
}

WINDOW* set_predict_window(){
    int height = 6;
    int width = 14;
    WINDOW* win = newwin(height, width, 7, 81);
    return(win);
}

void predict_window(WINDOW* win, tetramino* next_point){
    wmove(win, 2, 0);
    wclrtoeol(win);
    wmove(win, 3, 0);
    wclrtoeol(win);

    box(win, 0, 0);
    switch (next_point->get_colour()){  //Stampa del tetramino successivo
    case 1:
        wmove(win, 2, 4);
        wattron(win, COLOR_PAIR(1));
        wprintw(win, "[][]");
        wmove(win, 3, 6);
        wprintw(win, "[][]");
        wattroff(win, COLOR_PAIR(1));
        break;

    case 2:
        wmove(win, 2, 6);
        wattron(win, COLOR_PAIR(2));
        wprintw(win, "[][]");
        wmove(win, 3, 4);
        wprintw(win, "[][]");
        wattroff(win, COLOR_PAIR(2));
        break;

    case 3:
        wmove(win, 2, 5);
        wattron(win, COLOR_PAIR(3));
        wprintw(win, "[][]");
        wmove(win, 3, 5);
        wprintw(win, "[][]");
        wattroff(win, COLOR_PAIR(3));
        break;

    case 4:
        wmove(win, 2, 4);
        wattron(win, COLOR_PAIR(4));
        wprintw(win, "[]");
        wmove(win, 3, 4);
        wprintw(win, "[][][]");
        wattroff(win, COLOR_PAIR(4));
        break;

    case 5:
        wmove(win, 2, 4);
        wattron(win, COLOR_PAIR(5));
        wprintw(win, "[][][]");
        wmove(win, 3, 6);
        wprintw(win, "[]");
        wattroff(win, COLOR_PAIR(5));
        break;

    case 6:
        wmove(win, 3, 3);
        wattron(win, COLOR_PAIR(6));
        wprintw(win, "[][][][]");
        wattroff(win, COLOR_PAIR(6));
        break;

    case 7:
        wmove(win, 2, 8);
        wattron(win, COLOR_PAIR(7));
        wprintw(win, "[]");
        wmove(win, 3, 4);
        wprintw(win, "[][][]");
        wattroff(win, COLOR_PAIR(7));
        break;

    default:
        break;
    }
    wrefresh(win);
}

WINDOW* set_info_window(){
    int height = 9;
    int width = 17;
    WINDOW* win = newwin(height, width, 13, 81);
    return(win);
}

void info_window(WINDOW* win, Board &griglia){
    box(win, 0, 0);
    wmove(win, 2, 2);
    wattron(win, A_BOLD);
    wprintw(win, "SCORE:");
    wattroff(win, A_BOLD);
    mvwprintw(win, 4, 2, "%d", griglia.score);

    if(griglia.score < 1000){
        wattron(win, A_BOLD);
        wattron(win, COLOR_PAIR(10));
        mvwprintw(win, 6, 2, "LEVEL EASY   ");
        wattroff(win, A_BOLD);
        wattroff(win, COLOR_PAIR(10));
    } else if(griglia.score < 1500) {
        wattron(win, COLOR_PAIR(11));
        mvwprintw(win, 6, 2, "LEVEL MEDIUM ");
        wattroff(win, COLOR_PAIR(11));
    }else if(griglia.score < 2000){
        wattron(win, COLOR_PAIR(12));
        mvwprintw(win, 6, 2, "LEVEL HARD   ");
        wattroff(win, COLOR_PAIR(12));
    }else if(griglia.score >= 2500){
        wattron(win, COLOR_PAIR(13));
        mvwprintw(win, 6, 2, "LEVEL EXTREME");
        wattroff(win, COLOR_PAIR(13));
    }
    wrefresh(win);
}

WINDOW* set_crono_window(){
    int height = 7;
    int width = 14;
    WINDOW* win = newwin(height, width, 22, 81);
    box(win,0,0);
    wrefresh(win);
    return win;
}

void crono_window(WINDOW* win, int hours, int minutes, int seconds){
    wmove(win, 4, 0);
    wclrtoeol(win);

    box(win, 0, 0);
    wmove(win, 2, 2);
    wattron(win, A_BOLD);
    wprintw(win, "TIMER:");
    wattroff(win, A_BOLD);
    wrefresh(win);

    mvwprintw(win, 4, 2, "%d", hours);
    wprintw(win, " : ");
    wprintw(win, "%d", minutes);
    wprintw(win, " : ");
    wprintw(win, "%d", seconds);
    wrefresh(win);
}
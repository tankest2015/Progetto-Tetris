#include <ncurses.h>
#include "options.h"

using namespace std;

bool neon(){
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int x, y;
    bool flag = true;
    int key;
    bool select = false;
    getmaxyx(stdscr, y, x);
    WINDOW *neon;
    neon = newwin(y/2, x/2, y/2 - y/4, x/2 - x/4);
    refresh();

    box(neon,0,0);
    wrefresh(neon);
    keypad(neon, true);

    wattron(neon, A_BOLD);
    mvwprintw(neon, 3, 13, "____    _____   _______   _    ____    _   _    _____");
    mvwprintw(neon, 4, 12, "/ __ \\  |  __ \\ |__   __| | |  / __ \\  | \\ | |  / ____|");
    mvwprintw(neon, 5, 11, "| |  | | | |__) |   | |    | | | |  | | |  \\| | | (___");
    mvwprintw(neon, 6, 11, "| |  | | |  ___/    | |    | | | |  | | | . ` |  \\___ \\");
    mvwprintw(neon, 7, 11, "| |__| | | |        | |    | | | |__| | | |\\  |  ____) |");
    mvwprintw(neon, 8, 12, "\\____/  |_|        |_|    |_|  \\____/  |_| \\_| |_____/");

    mvwprintw(neon, 12, 27, "PLEASE SELECT THE MODE:");
    wattron(neon, A_REVERSE);
    mvwprintw(neon, 15, 23, "NEON");
    wattroff(neon, A_REVERSE);
    mvwprintw(neon, 15, 49, "COLOR");
    wattroff(neon, A_BOLD);
    wrefresh(neon);

    while(flag){
        key = wgetch(neon);

        if(key == KEY_LEFT) select = false;
        if(key == KEY_RIGHT) select = true;

        wattron(neon, A_BOLD);

        if(!select){
            mvwprintw(neon, 12, 27, "PLEASE SELECT THE MODE:");
            wattron(neon, A_REVERSE);
            mvwprintw(neon, 15, 23, "NEON");
            wattroff(neon, A_REVERSE);
            mvwprintw(neon, 15, 49, "COLOR");
        }
        else{
            mvwprintw(neon, 12, 27, "PLEASE SELECT THE MODE:");
            wattron(neon,A_REVERSE);
            mvwprintw(neon, 15, 49, "COLOR");
            wattroff(neon,A_REVERSE);
            mvwprintw(neon, 15, 23, "NEON");
        }
        wattroff(neon, A_BOLD);

        if(key == 10)
            flag = false;
    }
    clear();
    wrefresh(neon);
    delwin(neon);

    return select;
}
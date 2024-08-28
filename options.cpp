#include <ncurses.h>
#include "options.h"

using namespace std;

bool neon(){
    initscr();      //initializeed the screen
    noecho();
    cbreak();
    curs_set(0);

    int x,y;
    bool flag = true;
    int key;
    bool select = false;
    getmaxyx(stdscr, y, x);
    WINDOW *neon;
    neon = newwin(y/4, x/4, y/2, x/2);
    refresh();

    box(neon,0,0);      //initialized my boards of menu
    wrefresh(neon);
    keypad(neon, true);

    mvwprintw(neon, 1, 1, "MOD:");
    wattron(neon, A_REVERSE);
    mvwprintw(neon, 3, 1, "NEON");
    wattroff(neon, A_REVERSE);
    mvwprintw(neon, 3, 24, "COLOR");
    wrefresh(neon);

    while(flag){
        key = wgetch(neon);

        if(key == KEY_LEFT) select = false;
        if(key == KEY_RIGHT) select = true;


        if(!select){
            mvwprintw(neon, 1, 1, "MOD:");
            wattron(neon, A_REVERSE);
            mvwprintw(neon, 3, 1, "NEON");
            wattroff(neon, A_REVERSE);
            mvwprintw(neon, 3, 24, "COLOR");
        }
        else if(select){
            mvwprintw(neon, 1, 1, "MOD:");
            wattron(neon,A_REVERSE);
            mvwprintw(neon, 3, 24, "COLOR");
            wattroff(neon,A_REVERSE);
            mvwprintw(neon, 3, 1, "NEON");
        }

        if(key == 10)
            flag = false;
    }
    clear();
    wrefresh(neon);
    delwin(neon);

    return select;
}
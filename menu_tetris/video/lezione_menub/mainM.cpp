#include <ncurses.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>


using namespace std;

int main(int argc , char ** argv)
{
    initscr();
    noecho();
    cbreak();
    /*
    function call is used in the ncurses library to control 
    the visibility of the cursor in a terminal window
    */
    curs_set(0);

    int x,y,xMax,yMax;

    getmaxyx(stdscr, yMax,xMax);


    WINDOW * win = newwin(yMax/2,xMax/2,yMax/4,xMax/4);
    box(win,0,0);
    
    mvwprintw(win,0,2,"File");
    mvwprintw(win,0,7,"Edit");
    mvwprintw(win,0,12,"Options");


    refresh();
    wrefresh(win);

    char c;
    while(c=wgetch(win))
    {
        // MenuBar: check user (Input)
        switch(c)
        {
            //MenuBar: select menu x
            case 'f':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,7,"Edit");
                mvwprintw(win,0,12,"Options");
            break;

            //MenuBar: select menu x
            case 'e':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,7,"Edit");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,12,"Options");
            break;

            //MenuBar: select menu x
            case 'o':
                wattron(win,A_STANDOUT);
                mvwprintw(win,0,12,"Options");
                wattroff(win,A_STANDOUT);
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,7,"Edit");
            break;

            default:
                mvwprintw(win,0,2,"File");
                mvwprintw(win,0,7,"Edit");
                mvwprintw(win,0,12,"Options");
            break;
        }
    }

    endwin();
    return 0;
}




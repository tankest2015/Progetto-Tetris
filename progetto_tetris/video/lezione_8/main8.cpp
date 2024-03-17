#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;



int main(int argc, char ** argv)
{
    int y,x,yBeg,xBeg,yMax,xMax;
    
    initscr();
    noecho();
    cbreak();

    getmaxyx(stdscr,yMax,xMax);

    WINDOW * menuwin = newwin(20,50,(yMax/2)-10,10);
    box(menuwin,0,0);
    refresh();
    wrefresh(menuwin);
//    keypad(menuwin,true);

    Player * p = new Player(menuwin,1,1,'@');
    do{

        p->display();
        wrefresh(menuwin);
        //p->getmv();
    }while(p->getmv()!='x');
    


    //close the program :)
//getch();
    endwin();

    return(0);
}

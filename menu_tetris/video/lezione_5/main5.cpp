#include <ncurses.h>
#include <string>

using namespace std;

void start_ncurses(bool useRaw,bool useNoecho);
void printMenu(WINDOW * menu,string choices[],int size,int highlight);

int main(int argc, char ** argv)
{
    initscr();
    noecho();
    cbreak();

    WINDOW * win = newwin(10,20,10,10);

    int y,x,yBeg,xBeg,yMax,xMax;

    getyx(stdscr, y,x);
    getbegyx(stdscr,yBeg,xBeg);
    getmaxyx(stdscr,yMax,xMax);

    mvprintw(yMax/2,xMax/2,"Forza BFC");

    printw("%d %d %d %d %d %d",y,x,yBeg,xBeg,yMax,xMax);
    
    getch();
	endwin();
    return(0);
}

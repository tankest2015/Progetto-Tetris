#include <ncurses.h>
#include <string>

using namespace std;

void start_ncurses(bool useRaw,bool useNoecho);
void printMenu(WINDOW * menu,string choices[],int size,int highlight);

int main(int argc, char ** argv)
{
    int y,x,yBeg,xBeg,yMax,xMax;
    initscr();
    noecho();
    cbreak();

    getmaxyx(stdscr,yMax,xMax);

    WINDOW * inputwin = newwin(3,xMax-12,yMax-5,5);
    box(inputwin,0,0);
    refresh();
    wrefresh(inputwin);

    keypad(inputwin,true);
    
    int c = wgetch(inputwin);

    while(c!='b')
    {
        mvwprintw(inputwin,1,1,"Fanculo chi non tifa BFC");
        wrefresh(inputwin);
        c = wgetch(inputwin);
    }
    
    //close the program :)
    getch();
	endwin();

    return(0);
}

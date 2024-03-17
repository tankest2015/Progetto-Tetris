#include <ncurses.h>

using namespace std;

int main(int argc, char ** argv)
{
    /*start initialized*/
	initscr();
    //cbreak(); can use crtl+C as break,
    //but there is of default,so is deprecated

    raw();
    //noecho don't show/print in the screen our carachetrs
    noecho();
    int height,width,start_y,start_x;
	height = 10;
	width = 20;
	start_y = start_x = 10;
	
	WINDOW * win = newwin(height,width,start_y,start_x);
	refresh();

    /*0,0 is default characters to top and bottom*/
	box(win,0,0);
    int left,right,top,bottom,tlc,trc,blc,brc;
    left = right = (int)'|';
    top=bottom = (int)'-';
    tlc=trc=blc=brc;

    wborder(win,left,right,top,bottom,tlc,trc,blc,brc);

    //mvwprintw() function allows you to print 
    //a text string at a specific position within a window.
	//mv = "movewindow"
    mvwprintw(win,2,2,"this is my box");
	wrefresh(win);

	//int c = getch();

    getch();
    getch();

	endwin();
	return(0);
}

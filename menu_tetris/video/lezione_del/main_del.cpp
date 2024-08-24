#include<ncurses.h>
#include<stdio.h>

using namespace std;

int main(int argc, char ** argv)
{
	initscr();

    WINDOW *win = newwin(10,25,0,0);
    box(win,0,0);
    refresh();
    wrefresh(win);


    getch();

    wclear(win);
    wrefresh(win);

    /*
        library is used to delete a window that was previously created with newwin() or subwin()
        It deallocates memory associated with the window and releases resources used by it. 
        After calling delwin(), the WINDOW pointer associated with the deleted window becomes invalid, 
        and you should not use it anymore.
    */

    delwin(win);

    getch();

    endwin();


	return 0;
}


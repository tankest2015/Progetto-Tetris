#include<ncurses.h>

using namespace std;

int main(int argc,char ** argv)
{
	initscr();
    noecho();

    refresh();

    printw("Hello World!");
    mvprintw(1,0,"Hello World!");
    move(0,1);

    getch();

    /*
    This function clears the current line from the cursor position to the end of the line. 
    "clrtoeol" stands for "clear to end of line."
    */
    clrtoeol();
    getch();
    mvprintw(2,0,"Everything below this should get cleared");
    mvprintw(3,0,"Everything below this should get cleared");
    mvprintw(6,0,"Everything below this should get cleared");
    mvprintw(10,0,"Everything below this should get cleared");
    move(2,5);
    getch();
    /*
    Similar to clrtoeol(), clrtobot() clears the current line from 
    the cursor position to the end of the screen.
    "clrtobot" stands for "clear to bottom of the screen."
    */
    clrtobot();



    /*
    This function clears the entire window, removing all contents, but it doesn't redraw the window. 
    It simply sets the window's contents to be empty. The cursor position is reset to the upper-left corner of the window. 
    It's often used when you want to clear the screen without redrawing any contents immediately.
    */
    erase();
  
    /*
     also clears the entire window, removing all contents. 
     However, it also instructs the library to redraw the window afterward. 
     So, after calling clear(), you typically follow it with a call to refresh() to redraw the window. 
     This ensures that the cleared window is immediately updated on the screen.
    */
    clear();

	getch();
	endwin();

	return 0;
}


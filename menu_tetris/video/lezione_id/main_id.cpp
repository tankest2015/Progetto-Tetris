#include<ncurses.h>
#include<stdio.h>

using namespace std;

int main(int argc, char ** argv)
{
	initscr();
    noecho();
    refresh();

    WINDOW *win = newwin(5,8,10,10);
    box(win,0,0);

    /*
        library is used to control whether the cursor can leave the window boundaries when scrolling or moving. 
        By default, the cursor is not allowed to leave the window.
        you're allowing the cursor to leave the window boundaries. 
        This can be useful in situations where you want the cursor to move freely. 
    */

    leaveok(win,false);
    wmove(win,1,2);
    wgetch(win);
    /*
        library is used to control whether immediate updates are allowed when inserting or deleting characters. 
        Immediate updates mean that changes made to the window's content will be immediately reflected on the screen.
    */
    immedok(win,true);
    waddch(win,'B');


    /*
        library is used to enable or disable automatic scrolling in a window. 
        When automatic scrolling is enabled, if text is written to the window and the cursor moves off the bottom of the window, 
        the window contents will automatically scroll up to make room for the new text.
    */
    scrollok(win,true);

    int counter = 0;
    while(true)
    {
        chtype ch = (counter % 10) + '0';
        waddch(win,ch);
        wrefresh(win);
        counter++;
    }



    /*
        library is used to control whether the contents of a window are cleared automatically when it is refreshed.
    */
    clearok(win,true);
    getch();
    endwin();


	return 0;
}


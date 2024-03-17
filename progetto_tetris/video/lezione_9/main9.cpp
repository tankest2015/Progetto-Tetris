#include<ncurses.h>

using namespace std;

int main(int argc,char **argv)
{

    /*
    refresh():
        - This function updates the entire screen.
        - It redraws all the windows that have been 
            touched since the last call to refresh().
        - If you've made changes to multiple windows and want to update all of them, 
           you typically call refresh() once at the end to update the entire screen.
    
    wrefresh():

        - This function updates a specific window.
        - It redraws only the specified window and leaves other windows unchanged.
        - You call wrefresh() on the window that you want to update, 
           passing a pointer to that window as an argument.

    very similar way to getch() and wgetch();
    */
    initscr();
    WINDOW * win = newwin(10,30,0,0);
    box(win,0,0);
    refresh();
    //wrefresh(win);

    wgetch(win);
    
    getch();
    endwin();

    return 0;
}
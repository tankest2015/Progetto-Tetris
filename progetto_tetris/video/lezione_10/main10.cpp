#include<ncurses.h>
#include <iostream>

using namespace std;

int main (int argc, char ** argv)
{
    initscr();
    noecho();
/* function is part of the ncurses library in C programming. 
   It is used to disable line buffering for input, meaning that characters typed by the user are immediately
   made available to the program without waiting for the user to press Enter.
*/
//    cbreak();

/*
function is another function provided by the ncurses library in C programming. 
It allows you to set a timeout for user input, so if no input is received within the specified time, 
the getch() function returns ERR.
*/

//halfdelay();

/*
The nodelay() function is part of the ncurses library in C programming, 
and it is used to control whether getch() is blocking or non-blocking.
*/

//nodealy(stdscr,true);

/*
function in ncurses is used to set a maximum amount of time that getch() 
will wait for user input before returning ERR if no input is received. 
It allows you to control the blocking behavior of getch().
*/

//timeout(delay);

    int c;
    while((c=getch()!='x'))
    {
        printw("%d\n",c);
    }
    endwin();

    return 0;
}
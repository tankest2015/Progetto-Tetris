#include <ncurses.h>

using namespace std;

int main(int argc,char ** argv)
{

    int x,y;

    x=10;
    y=10;
    //initialized the screen 
    // sets up memory and clears the screen
    initscr();

    // moves the cursor to the specifified location
    move(x,y);

    //prints a string(const char * ) to a window
    printw("Hello Wordl!");

    //refresh the screen to match whats in memory
    int c = getch();    
    refresh();
    //si può sia muovare che stampare assieme 
    // quale è la migliore, dipende dalle nostre implementazioni

    // %d: Used to format integer numbers .
    // %f: Used to format floating-point.
    // %c: Used to format single characters.
    // %s: Used to format character strings.
    // %x or %X: Used to format integer numbers in hexadecimal (lowercase or uppercase).
    // %o: Used to format integer numbers in octal.
    // %u: Used to format unsigned integer numbers.
    // %e or %E: Used to format floating-point numbers in scientific notation (lowercase or uppercase).

    //move(0,0);
    //printw("%d",c);
    mvprintw(0,0,"%d",c);
    refresh();

    //clear the screen

    clear();

    //printw("%d",c);

    getch();

    
    endwin();

    return(0);
}

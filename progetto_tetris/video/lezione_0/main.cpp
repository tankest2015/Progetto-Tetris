#include <ncurses.h>

using namespace std;

int main(int argc,char ** argv)
{
    //initialized the screen 
    // sets up memory and clears the screen
    initscr();

    //prints a string(const char * ) to a window
    printw("Hello Wordl!");

    //refresh the screen to match whats in memory
  int c = getch();
 //  for(int i=0;i<3;i++)
   //{
    
    //c = getch();
    printw("%d",c);

    getch();

   //}
    
    endwin();

    return(0);
}
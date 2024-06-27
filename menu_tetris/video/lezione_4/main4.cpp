#include <ncurses.h>

using namespace std;

int main(int argc, char ** argv)
{
    initscr();
    endwin();

    move(1,1);

    if(!has_colors())
    {
        printw("Terminal doesn't support the color");
        getch();
        return -1;
    }
    
    start_color();
    
    init_pair(1,COLOR_CYAN,COLOR_RED);

    attron(COLOR_PAIR(1));

    printw("This is some text");

    attroff(COLOR_PAIR(1));
    refresh();
    getch();
    endwin();
    
	return(0);
}

#include <ncurses.h>

using namespace std;

int main(int argc, char ** argv)
{
	int height,width,start_y,start_x;
	height = 10;
	width = 20;
	start_y = start_x = 10;
	initscr();

	WINDOW * win = newwin(height,width,start_y,start_x);
	refresh();

	box(win,'*','|');
	wprintw(win,"this is my box");

	
	wrefresh(win);
	int c = getch();

	endwin();
	return(0);
}

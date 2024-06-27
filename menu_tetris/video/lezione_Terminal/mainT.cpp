#include<ncurses.h>

using namespace std;

int main(int argc,char ** argv)
{
	initscr();

	if(!has_colors())
	{
		return -1;
	}

	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);

	/*
	hich is used to change attributes of characters in a window. 
	This function allows you to change the attributes such as color, 
	boldness, underline, etc., of characters within a specified region of a window.
	*/

	//mwchgat is chgat with move()

	//wchgat is chgat but only to specific WINDOW
	//mvwchgat is wchgat with move()
	move(0,5);
	printw("Hello");
	mvchgat(0,5,5,A_STANDOUT,1,NULL);
	//print("Hello");

	getch();
	endwin();

	return 0;
}

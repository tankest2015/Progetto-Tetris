#include<ncurses.h>
#include<stdlib.h>

int main(int argc,char ** argv)
{
    initscr();
    if(has_colors()==FALSE)
    {
        endwin();
        printf("Color can't be used.");
    }

    start_color();

    init_pair(1,COLOR_YELLOW,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);

    attr_t emphasis = A_REVERSE | COLOR_PAIR(2);
    attron(emphasis);
    mvaddch(5,5,'a');
    mvaddch(5,6,'b');
    mvaddch(5,7,'c');

    attron(A_REVERSE | COLOR_PAIR(2));

//    char c = 'a' | A_REVERSE | COLOR_PAIR(2);
    chartype c = 'a' | A_REVERSE | COLOR_PAIR(2);

    mvaddch(9,5,c);

    getch();
    getch();
    endwin();
}
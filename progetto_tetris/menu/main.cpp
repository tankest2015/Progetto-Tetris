#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "page_save.h"

using namespace std;

int main(int argc, char ** argv)
{
    int x,y,xMax,yMax;
    
    
    initscr(); //initializeed the screen
    noecho(); 
    cbreak();

    if(!has_colors())
    {
        printw("Terminal doesn't support the color");
        getch();
        return -1;
    }

    getmaxyx(stdscr, yMax,xMax);


    WINDOW * win = newwin(yMax/6,xMax/2,yMax/2,xMax/4);
    refresh();

    box(win,0,0);//initialized my boards of menu
    wrefresh(win);
    
    keypad(win,true);

    char *choices[3] = {"Play","Rank","options"};
    bool pass = true;
    int select;
    int highlight = 0;

    for(int i = 0;i<3;i++)
        {
            mvwprintw(win,i+1,1,choices[i]);
        }

    wrefresh(win);

    wattron(win,A_REVERSE);
    mvwprintw(win,1,1,choices[0]);
    wattroff(win,A_REVERSE);
    mvwprintw(win,2,1,choices[1]);
    mvwprintw(win,3,1,choices[2]);

    while(pass)
    {

        select = wgetch(win);

        if(select == KEY_UP)
        {
            highlight--;
            if(highlight == -1)
                highlight = 0;
        }
        else if(select==KEY_DOWN)
        {
            highlight++;
            if(highlight == 3)
                highlight = 2;
        }

        if(highlight==0)
        {
            wattron(win,A_REVERSE);
            mvwprintw(win,1,1,choices[0]);
            wattroff(win,A_REVERSE);
            mvwprintw(win,2,1,choices[1]);
            mvwprintw(win,3,1,choices[2]);
        }
        else if(highlight==1)
        {
            mvwprintw(win,1,1,choices[0]);
            wattron(win,A_REVERSE);
            mvwprintw(win,2,1,choices[1]);
            wattroff(win,A_REVERSE);
            mvwprintw(win,3,1,choices[2]);
        }
        else if(highlight==2)
        {
            mvwprintw(win,1,1,choices[0]);
            mvwprintw(win,2,1,choices[1]);
            wattron(win,A_REVERSE);
            mvwprintw(win,3,1,choices[2]);
            wattroff(win,A_REVERSE);
        }

        if(select==10) pass = false;
    }

    wclear(win);
    wrefresh(win);
    delwin(win);

    //if(highlight==0)
    //else 
    if(highlight==1)
    {
        scr();
    }
    //else if(highlight==2)
    

    getch();
    endwin();
    return 0;
}


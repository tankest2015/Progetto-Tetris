#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include "write_lead.h"

using namespace std;


int main(int argc, char **argv) 
{
    initscr();
    noecho();
    cbreak();
    refresh();

    int xMax,yMax;
    getmaxyx(stdscr, yMax,xMax);


    int i = 0;
    int k = 1;
    WINDOW *win;
    win = newwin(yMax/7,xMax/7,yMax/2,xMax/2);
    refresh();
    box(win,0,0);
    wrefresh(win);
    mvwprintw(win,1,1,"INSERT NAME:");
    wrefresh(win);
    
    keypad(win,true);
    int c;
    char text[10] = {0};
    char h[3] = {'0','5','\0'};
    char min[3] = {'1','2','\0'};
    char s[3] = {'1','4','\0'};
    char point[5] = {'2','3','4','5','\0'};
    char block[5] = {'9','0','8','5','\0'};


    while(c = wgetch(win))
    {
        if(c == 10) //22 = CTRL + V
        {
            write(h,min,s,point,text,block);
            wclear(win);
            werase(win);
            delwin(win);
            wrefresh(win);
            endwin();
        }
        else if(c ==KEY_BACKSPACE)
        {
            i--;
            text[i] = '\0';
            mvwdelch(win, 2, i+1);
            wrefresh(win);
            
           /* mvwprintw(win,3,k,"c");
            wrefresh(win);
            k++;
            */
        }
        else
        {
            if(i<sizeof(text)-1)
            {
                
                text[i]= (char) c;
                mvwprintw(win,2,1,"%s",text);
                wrefresh(win);
                i++;
            }
            //mvwprintw(win,3,1,"%s",text);
        }
    }

    endwin();
    return 0;
}

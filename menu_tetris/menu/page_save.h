#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#ifndef _PAGE_SAVE_H_
#define _PAGE_SAVE_H_

//#include "salvataggio_punteggio/read.h"

int scr()
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
    start_color();

    getmaxyx(stdscr, yMax,xMax);


    WINDOW * win = newwin(yMax-5,xMax-10,2,5);
    refresh();

    box(win,0,0);//initialized my boards of menu
    wrefresh(win);
    keypad(win,true);
    
    int c=4,r=1;
    int i=0;
    fstream file;
    file.open("salvataggio_punteggio/test1.txt", ios::in);
    char line[80];

    mvwprintw(win,1,1,"Name");
    mvwprintw(win,1,20,"Time[hh/mm/ss]");
    mvwprintw(win,1,40,"Point");
    mvwprintw(win,1,60,"Block");
    if(!file.is_open()) // is file doesn't exits i do an interrupt 
        cout<<"error to open file "<<endl;
    else
    {
        while(!file.eof())
        {
            file>>line;
            if(strcmp(line,"n")==0)
            {
                c++;
                r=1;
                i++;
            }
            else
            {
                if(i==0)
                {
                    wattron(win,A_REVERSE);
                    mvwprintw(win,c,r,line);
                    wattroff(win,A_REVERSE);
                }
                else
                {
                    mvwprintw(win,c,r,line);
                }
                
                r=r+20;
            }

        }
    }
    
    file.close();


    wrefresh(win);



    getch();
    endwin();
    return 0;
}

#endif 
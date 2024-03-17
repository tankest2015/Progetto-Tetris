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

    getmaxyx(stdscr, yMax,xMax);


    WINDOW * win = newwin(yMax-5,xMax-10,2,5);
    refresh();

    box(win,0,0);//initialized my boards of menu
    wrefresh(win);
    keypad(win,true);
    
    int c=1,r=1;
    fstream file;
    file.open("salvataggio_punteggio/test1.txt", ios::in);
    char line[80];


    if(!file.is_open()) // is file doesn't exits i do an interrupt 
        cout<<"error to open file "<<endl;
    else
    {
        while(!file.eof())
        {
            file>>line;
            if(strcmp(line,"n")==0)
            {
                //mvwprintw(win,j,1,"ORCODIO");
                c++;
                r=1;
            }
            else
            {
                mvwprintw(win,c,r,line);
                r=r+15;
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
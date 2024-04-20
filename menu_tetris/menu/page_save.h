#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#ifndef _PAGE_SAVE_H_
#define _PAGE_SAVE_H_



int scr()
{
    int x,y,xMax,yMax;
    bool flag = false;
    
    initscr(); //initializeed the screen
    noecho(); 
    cbreak();
    curs_set(0);

    if(!has_colors())
    {
        printw("Terminal doesn't support the color");
        getch();
        return -1;
    }
    start_color();

    getmaxyx(stdscr, yMax,xMax);


    WINDOW * win_rank = newwin(yMax-5,xMax-10,2,5);
    refresh();

    box(win_rank,0,0);//initialized my boards of menu
    wrefresh(win_rank);
    keypad(win_rank,true);
    
    int c=4,r=1;
    int i=0;
    fstream file;
    file.open("salvataggio_punteggio/test1.txt", ios::in);
    char line[80];

    mvwprintw(win_rank,1,1,"Name");
    mvwprintw(win_rank,1,20,"Time[hh/mm/ss]");
    mvwprintw(win_rank,1,40,"Point");
    mvwprintw(win_rank,1,60,"Block");
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
                    wattron(win_rank,A_REVERSE);
                    mvwprintw(win_rank,c,r,line);
                    wattroff(win_rank,A_REVERSE);
                }
                else
                {
                    mvwprintw(win_rank,c,r,line);
                }
                
                r=r+20;
            }

        }
    }
    
    file.close();


    wrefresh(win_rank);

    WINDOW *exit = newwin(yMax/10,xMax/14,yMax-10,xMax-20);
    box(exit,0,0);
    wrefresh(exit);


    wattron(exit,A_REVERSE);
    mvwprintw(exit,1,2,"EXIT");
    wattroff(exit,A_REVERSE);
    int car = wgetch(exit);

    while(!flag)
    {
        if(car == 10)
        {
            flag = true;
        }

        car = wgetch(exit);
    }

    wclear(exit);
    wrefresh(exit);
    delwin(exit);    

    wclear(win_rank);
    wrefresh(win_rank);
    delwin(win_rank);

    //getch();
    endwin();
    return 0;
}

#endif 
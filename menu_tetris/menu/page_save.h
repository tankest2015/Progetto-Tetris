#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#ifndef _PAGE_SAVE_H_
#define _PAGE_SAVE_H_

void delete_W(WINDOW * win);
int init();
//prototipi


int scr()
{
    int x,y,xMax,yMax;
    bool flag = false;

    init();

    getmaxyx(stdscr, yMax,xMax);


    WINDOW * win_rank = newwin(yMax-5,xMax-10,2,5);
    refresh();

    box(win_rank,0,0);//initialized my boards of menu
    wrefresh(win_rank);
    keypad(win_rank,true);
    
    int c=4,r=1;
    int i=0;
    bool fix=true; //flag per verificare se il file è stato modificato o no 
    fstream file;
    file.open("test1.txt", ios::in);
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
            
            if(strcmp(line,"flag: 0")==0)
            {
                c = 4;
                r = 1;
                i = 0;

            }
            else if(strcmp(line,"n")==0)
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
    
    
    delete_W(exit);
    delete_W(win_rank);

    endwin();
    return 0;
}

#endif 
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;

#ifndef _CLASS_MENU_H_
#define _CLASS_MENU_H_


class menu
{
    protected:
    int k;
    char *choices[4];
    WINDOW *win;
    int yMax;
    int xMax;

    public:

    menu(WINDOW *win,char *str[],int k,int y,int x)
    {
        this->win = win;
        this->k = k;
        this->win = win;
        this->yMax = y;
        this->xMax = x;

        for(int i=0;i<k;i++)
        {
            choices[i] = new char[strlen(str[i]) + 1];
            strcpy(choices[i],str[i]);
        }
    }
    
    int init()
    {
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
        else getmaxyx(stdscr, yMax,xMax);
    }


    int get_y()
    {
        return yMax;
    }

    int get_x()
    {
        return xMax;
    }

    void create_W()
    {
        init();

        // WINDOW * win = newwin(height,width,start_y,start_x);
        win = newwin(yMax/7,xMax/3,yMax/2,xMax/3);
        refresh();

        box(win,0,0);//initialized my boards of menu
        wrefresh(win);
        keypad(win,true);
    }
    
    void menu_start()
    {
        for(int i = 0;i<4;i++)
        {
            mvwprintw(win,i+1,1,choices[i]);
        }

        wrefresh(win);

        wattron(win,A_REVERSE);
        mvwprintw(win,1,1,choices[0]);
        wattroff(win,A_REVERSE);
        mvwprintw(win,2,1,choices[1]);
        mvwprintw(win,3,1,choices[2]);
        mvwprintw(win,4,1,choices[3]);
    }

    void menu_S(int k)
    {
        for(int i = 0;i<4;i++)
        {
            if(k==i)
            {
                wattron(win,A_REVERSE);
                mvwprintw(win,i+1,1,choices[i]);
                wattroff(win,A_REVERSE);
            }
            else mvwprintw(win,i+1,1,choices[i]);
        }
    }

    void delete_W(WINDOW * win)
    {
        wclear(win);
        wrefresh(win);
        delwin(win);
    }

    int get_wg()
    {
        return wgetch(win);
    }

};



class Read_menu: public menu
{

    protected:
    WINDOW * win_rank;
    WINDOW *exit;
    int c,r,i;
    public:
    Read_menu(WINDOW * win,char *str[],int k,int y,int x,WINDOW * win_rank,WINDOW * exit,int col,int righe,int i):menu(win,str,k,y,x)
    {
        this->win_rank = win_rank;
        this->exit = exit;
        this->c = col;
        this->r = righe;
        this->i = i;
    }

    void create_win_rank()
    {
        menu::init();

        win_rank = newwin(yMax-5,xMax-10,2,5);
        refresh();
        box(win_rank,0,0);//initialized my boards of menu
        wrefresh(win_rank);
        keypad(win_rank,true);
    
    }

    void create_win_exit()
    {
        //menu::init();

        exit = newwin(yMax/10,xMax/14,yMax-10,xMax-20);
        box(exit,0,0);
        wrefresh(exit);
    
    }

    
    void scr()
    {
        bool flag = false;

        create_win_rank();

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

        create_win_exit();

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
        
        menu::delete_W(exit);
        menu::delete_W(win_rank);

        endwin();
    }

};


#endif _CLASS_MENU_H_
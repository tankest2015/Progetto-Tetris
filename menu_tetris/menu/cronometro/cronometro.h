#include <ncurses.h>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
#include <time.h>
#include <unistd.h>

using namespace std;

#ifndef _CLASS_MENU_H_
#define _CLASS_MENU_H_


class cronometro
{
    protected:
    int h;
    int min;
    int s;
    time_t start_time;
    time_t current_time;
    int diff_time;
    bool flag;
    WINDOW * cr;


    public:
    cronometro(WINDOW *win,int h,int min,int s,time_t start,time_t curr,int diff,bool flag)
    {
        this->cr = win;

        this->h = h;
        this->min = min;
        this->s = s;

        this->start_time = start;
        this->current_time = curr;

        this->diff_time = diff;
        this->flag = flag;
    }


    void crono()
    {
        initscr();              // Inizializza lo schermo
        cbreak();               // Disabilita il buffering dell'input
        noecho();               // Non mostra i tasti premuti
        curs_set(0);            // Nasconde il cursore

        int yMax,xMax;
        getmaxyx(stdscr, yMax,xMax);

        
        cr = newwin(yMax/3,xMax/4,yMax/4,xMax/4);
        refresh();

        box(cr,0,0);//initialized my boards of menu
        wrefresh(cr);
        keypad(cr,true);
        wrefresh(cr);




        char hour[2];
        char minute[2];
        char second[2];


        start_time = time(NULL);  // Ottieni il tempo attuale all'inizio
        flag = true;
        
        while (flag) 
        {
            // Calcola il tempo trascorso
            current_time = time(NULL);
            diff_time = difftime(current_time, start_time);

            h = diff_time / 3600;
            min = (diff_time %3600) / 60;
            s = diff_time % 60;

            // Pulisce la schermata
            wclear(cr);

            
            sprintf(hour, "%d", h);
            sprintf(minute, "%d", min);
            sprintf(second, "%d", s);
    

            // Mostra il tempo trascorso
            mvwprintw(cr,1,1, hour); 
            mvwprintw(cr,2,1, minute);
            mvwprintw(cr,3,1, second);

            wrefresh(cr);          // Aggiorna la schermata
            mvwprintw(cr,4,1,"clicca invio per fermare");
    
            if(s>4)
            {
                flag = false;
            }
            
            sleep(1);           // Aspetta 1 secondo prima di aggiornare di nuovo
        }

        endwin();
    }

    bool get_flag()
    {
        return flag;
    }

    void set_flag(bool f)
    {
        flag = f;
    }

    int get_h()
    {
        return h;
    }

    int get_m()
    {
        return min;
    }

    int get_s()
    {
        return s;
    }
};

#endif _CLASS_MENU_H_
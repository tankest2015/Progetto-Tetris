#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "class_menu.h"


menu::menu(WINDOW *win,char *str[],int k,int y,int x){ //costruttore
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

void menu::init() //funziona che mi inizializza lo schermo
{
    initscr(); //initializeed the screen
    noecho(); 
    cbreak();
    curs_set(0);
    

    if(!has_colors())
    {
        printw("Terminal doesn't support the color");
        getch();
        
    }
    else
    {

        start_color();
        getmaxyx(stdscr, yMax,xMax);
    } 
        
}


int menu::get_y(){
    return yMax;
}

int menu::get_x(){
    return xMax;
}

void menu::create_W(){ //mi inizializza la finestra
    init();

    // WINDOW * win = newwin(height,width,start_y,start_x);
    win = newwin(yMax/5,xMax/3,yMax/2,xMax/2);
    refresh();

    box(win,0,0);//initialized my boards of menu
    wrefresh(win);
    keypad(win,true);
}

void menu::menu_start(){ //mi inizializza il menu
    for(int i = 0;i<4;i++)
    {
        mvwprintw(win,i+1,1,"%s",choices[i]);
    }

    wrefresh(win);
    menu_S(0,4);
    wrefresh(win);
}

void menu::menu_S(int k,int j){ //evidenzia il corretto campo in cui l'utente si trova 
    for(int i = 0;i<j;i++){
        if(k==i){
            wattron(win,A_REVERSE);
            mvwprintw(win,i+1,1,"%s",choices[i]);
            wattroff(win,A_REVERSE);
            wrefresh(win);
        }
        else
        {
            mvwprintw(win,i+1,1,"%s",choices[i]);
            wrefresh(win);
        } 
            
    }
}

void menu::delete_W(WINDOW *win){ //mi elimina la finestra 
    wclear(win);
    wrefresh(win);
    delwin(win); 
}

int menu::get_wg()
{
    return wgetch(win);
}

Read_menu::Read_menu(WINDOW * win,char *str[],int k,int y,int x,WINDOW * win_rank,WINDOW * exit,int col,int righe,int i):menu(win,str,k,y,x)
{
    this->win_rank = win_rank;
    this->exit = exit;
    this->c = col;
    this->r = righe;
    this->i = i;
}

void Read_menu::create_win_rank()
{
    menu::init();

    win_rank = newwin(yMax-5,xMax-10,2,5);
    wrefresh(win_rank);
    box(win_rank,0,0);//initialized my boards of menu
    wrefresh(win_rank);
    keypad(win_rank,true);

}

void Read_menu::create_win_exit()
{

    exit = newwin(yMax/10,xMax/14,yMax-10,xMax-20);
    box(exit,0,0);
    wrefresh(exit);

}

void Read_menu::scr()
{
    bool flag = false;
    bool fix=true; //flag per verificare se il file è stato modificato o no 

    create_win_rank();

    fstream file;
    file.open("salvataggio_punteggio/test1.txt", ios::in); //mi apre il file in lettura
    char line[80];

    //colonne
    mvwprintw(win_rank,1,1,"Pos:");
    mvwprintw(win_rank,1,20,"Name:");
    mvwprintw(win_rank,1,40,"Time[hh/mm/ss]:");
    mvwprintw(win_rank,1,60,"Point:");
    mvwprintw(win_rank,1,80,"Block:");


    if(!file.is_open()) // is file doesn't exits i do an interrupt 
        cout<<"error to open file "<<endl;
    else
    {
        while(!file.eof())//è vero fin tanto che il file non sia finito
        {
            file>>line;
            
            
            if(strcmp(line,"ff")==0)
            {
                c = 4;
                r = 1;
                i = 0;
                file>>line;
                fix = false;
            }
            else if(strcmp(line,"tt")==0)
            {
                c = 4;
                r = 1;
                i = 0;
                file>>line;
                fix = true;
            } 
            
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
    
    file.close();//chiude il file

    if(fix)// se vero allora nella prima riga c'è tt quindi il file in precendenza è stato modificato
    {    
        
        fstream fileR;
        fileR.open("salvataggio_punteggio/test1.txt", std::ios::in | std::ios::out);

        fileR<<"ff"<<endl;

        //file>>endl;

        fileR.close();
        fix = false;
    }

    wrefresh(win_rank);

    create_win_exit();

    wattron(exit,A_REVERSE);
    mvwprintw(exit,1,2,"EXIT");
    wattroff(exit,A_REVERSE);
    int car ;

    while(!flag)
    {
        car = wgetch(exit);
        if(car == 10)
        {
            flag = true;
        }
    }
    
    menu::delete_W(exit);
    menu::delete_W(win_rank);

    endwin();
}

Menu_pausa::Menu_pausa(WINDOW * win,char *ch[],int k,int y,int x,WINDOW *P,int xMax,int yMax,char* str[],int c):menu(win,ch,k,y,x)
{
    this->P = P;
    this->x =xMax;
    this->y =yMax;

    for(int i=0;i<c;i++)
    {
        choices[i] = new char[strlen(str[i]) + 1];
        strcpy(choices[i],str[i]);
    }
}

void Menu_pausa::create_W()
{
    menu::init();

    // WINDOW * win = newwin(height,width,start_y,start_x);
    P = newwin(yMax/6,xMax/4,yMax/2,xMax/2);
    refresh();

    box(P,0,0);//initialized my boards of menu
    wrefresh(P);
    keypad(P,true);
}

void Menu_pausa::menu_start()
{
    for(int i = 0;i<2;i++)
    {
        mvwprintw(P,i+1,1,choices[i]);
    }

    wrefresh(P);

    wattron(P,A_REVERSE);
    mvwprintw(P,1,1,choices[0]);
    wattroff(P,A_REVERSE);
    mvwprintw(P,2,1,choices[1]);
    
    //wrefresh(P);
}

void Menu_pausa::menu_S(int k,int j)
{
    for(int i = 0;i<j;i++)
    {
        if(k==i)
        {
            wattron(P,A_REVERSE);
            mvwprintw(P,i+1,1,choices[i]);
            wattroff(P,A_REVERSE);
        }
        else mvwprintw(P,i+1,1,choices[i]);
    }
}

void Menu_pausa::delete_W()
{
    wclear(P);
    wrefresh(P);
    delwin(P);
    P = NULL;
}

int Menu_pausa::get_wg()
{
    return wgetch(P);
}

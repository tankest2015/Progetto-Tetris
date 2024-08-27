#ifndef CLASS_MENU_H
#define CLASS_MENU_H

#include <ncurses.h>

using namespace std;

class menu {     //Classe Principale e padre di tutte le altre
    protected:
    int k;              //indice dell'array
    char *choices[4];
    WINDOW *win;
    int yMax;
    int xMax;

    public:
    menu(WINDOW *win,char *str[],int k,int y,int x); //Costruttore
    
    void init();                    //funziona che mi inizializza lo schermo
    int get_y();
    int get_x();
    void create_W();                //mi inizializza la finestra
    void menu_start();              //mi inizializza il menu
    void menu_S(int k,int j);       //evidenzia il corretto campo in cui l'utente si trova 
    void delete_W(WINDOW *win);     //mi elimina la finestra 
};


class Read_menu: public menu {      // Classe derivata dalla classe menu: MENU_DI_GIOCO
    protected:
    WINDOW * win_rank;
    WINDOW *exit;
    int c,r,i;

    public:
    Read_menu(WINDOW * win,char *str[],int k,int y,int x,WINDOW * win_rank,WINDOW * exit,int col,int righe,int i);

    void create_win_rank();
    void create_win_exit();
    void scr();
};

class Menu_pausa : public menu {     //Classe derivata dalla classe menu: MENU_DI_PAUSA
    protected:
    WINDOW *P;
    char *choices[2];
    int x;
    int y;
    int k;

    public:
    Menu_pausa(WINDOW * win,char *ch[],int k,int y,int x,WINDOW *P,int xMax,int yMax,char* str[],int c);

    void create_W();

    void menu_start();

    void menu_S(int k,int j);

    void delete_W();

    int get_wg();
};

#endif
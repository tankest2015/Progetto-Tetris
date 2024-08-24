#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Class_menu.h"


using namespace std;



int main(int argc, char ** argv)
{

    bool pass = true; //flag falso: l'utente ha cliccato resume o exit vero: deve ancora scegliere l'opzione 
    int select;       //mi rivaca il getch() della finestra del menu di pausa
    int highlight = 0; //contatore per definire che cosa ha scelto l'utente

    initscr(); //initializeed the screen di gioco(prova per me)
    noecho(); 
    cbreak();
    curs_set(0);
    
    int yMax,xMax; // da questa mi ricavo le dimensioni dello schermo

    if(!has_colors())
    {
        printw("Terminal doesn't support the color"); 
        getch();
        return -1;
            
    }else getmaxyx(stdscr, yMax,xMax);

    WINDOW *win;
    WINDOW *P;
    char *choices[2] = {"Resume","Exit"}; //array di char* in cui mi ricavo le opzioni
    char*no_char[1]={" "};//array nullo, mi serve per il costruttore se no mi dava problemi

 
    Menu_pausa T(win,no_char,0,0,0,P,0,0,choices,2); // istanza della classe con costruttore, è una classe derivata dalla classe menu(vedi lib Class_menu.h).

    win = newwin(yMax/5,xMax/3,0,0); //costruzione finestra di "gioco"
    refresh();

    box(win,0,0);
    wrefresh(win);
    keypad(win,true);

    char c;
    int i=1;

    while(c =wgetch(win)) //continua fin tanto che l'utente mi da degli input
    {
        if(c == 'i') //se preme i mi stampa a nello schermo della finestra di gioco HELLO
        {
            mvwprintw(win,i,1,"HELLO :) !!");
            wrefresh(win);
            i++;
            if(i==6) //se lo clicca 6 volte mi pulisce la finestra, 
                     //devo fare una funzione che mi sostituisce i caratteri in spazi, se no mi elimina anche il bordo
            {
                i=0;
                werase(win); //mi pulisce il tutto
            }
        }
        else if(c == 27) // 27 = sta premendo esc
        {
            
            T.create_W(); //mi costruisco la finestra(nella libreria).
            T.menu_start();//inizializzo il menu(//).
                

            pass = true;
            highlight = 0;

            while(pass)//logica simile per il menu di gioco
            {
                select = T.get_wg();
        
                if(select == KEY_UP)
                {
                    highlight--;
                    if(highlight == -1)
                        highlight = 0;
                }
                else if(select==KEY_DOWN)
                {
                    highlight++;
                    if(highlight == 2)
                        highlight = 1;
                }
        
                if(highlight==0)
                {
                    T.menu_S(highlight,2); // il seconod parametro mi permette di far contnuare il for per tot elementi dell'array
                                           //prima dovevo modificarlo solo nella libreria.
                }
                else
                {
                    T.menu_S(highlight,2);
                }
        
                if(select==10)//10 = premo invio per selezionare il campo 
                {
                    pass = false; //così mi esce dal while in ogni caso;
                    if(highlight==0) //ha premuto "resume"
                    {
                        T.delete_W(); //mi elimina solo la finestra di pausa;
                    }
                    if(highlight==1)// ha premuto "exit"
                    {
                        T.delete_W();

                        wclear(win);
                        wrefresh(win);
                        delwin(win);                   
                        //mi elimina tutte le finestre;     
                    }
                }
                refresh();
        
            }
        }   
    }

    endwin();
    return 0;
}


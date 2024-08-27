#include <ncurses.h>
#include "class_menu.h"

using namespace std;

bool pause(WINDOW* Fut){
    bool pass = true; //flag falso: l'utente ha cliccato resume o exit vero: deve ancora scegliere l'opzione 
    int select;       //mi rivaca il getch() della finestra del menu di pausa
    int highlight = 0; //contatore per definire che cosa ha scelto l'utente

    WINDOW *win;
    WINDOW *P;

    char *choices[2] = {"Resume", "Exit"}; //array di char* in cui mi ricavo le opzioni
    char* no_char[1] = {" "};//array nullo, mi serve per il costruttore se no mi dava problemi

    Menu_pausa T(win, no_char, 0, 0, 0, P, 0, 0, choices, 2); // istanza della classe con costruttore, è una classe derivata dalla classe menu(vedi lib Class_menu.h).

    char c;
    int i = 1;

    T.create_W(); //mi costruisco la finestra(nella libreria).
    T.menu_start();//inizializzo il menu(//).

    pass = true;
    highlight = 0;

    while(pass){ //logica simile per il menu di gioco
        select = T.get_wg();

        if(select == KEY_UP){
            highlight--;
            if(highlight == -1) highlight = 0;
        }
        else if(select==KEY_DOWN){
            highlight++;
            if(highlight == 2) highlight = 1;
        }
        
        if(highlight==0){
            T.menu_S(highlight,2);  // il secondo parametro mi permette di far contnuare il for per tot elementi dell'array
                                    //prima dovevo modificarlo solo nella libreria.
        }
        else
            T.menu_S(highlight,2);
        
        if(select == 10){             //10 = premo invio per selezionare il campo
            pass = false;           //così mi esce dal while in ogni caso;
            if(highlight == 0)        //ha premuto "resume"
                T.delete_W();       //mi elimina solo la finestra di pausa;
            if(highlight == 1)        // ha premuto "exit"
                T.delete_W();

                // wclear(Fut);
                // wrefresh(Fut);
                // delwin(Fut);
                // Fut = NULL;

                //mi elimina tutte le finestre;
            }
        refresh();
    }

    if(highlight == 1)
        return true;
    else
        return false;
    //endwin();
}
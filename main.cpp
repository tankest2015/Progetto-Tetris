#include "class_menu.h"
#include "game_engine.h"
#include "salvataggio_punteggio/write_lead.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


int main(int argc, char ** argv) {

    WINDOW* win;
    WINDOW* win_rank;
    WINDOW* exit; //Che Davoli è?
    
    char *choices[4] = {"Play","Leaderboard","Options","Exit"}; //perché puntatore a char se sono stringhe
    
    menu M(win,choices,4,0,0);
    Read_menu R(win,choices,4,0,0,win_rank,exit,4,1,0);
    M.create_W();
    M.menu_start();

    bool pass = true;
    int select;
    int highlight = 0;

    while(pass){
        select = wgetch(win);

        if(select == KEY_UP){
            highlight--;
            if(highlight == -1) highlight = 0;
        }
        else if(select==KEY_DOWN){
            highlight++;
            if(highlight == 4) highlight = 3;
        }

        if(highlight==0){
           M.menu_S(highlight,4);
        }
        else if(highlight==1){
           M.menu_S(highlight,4);
        }
        else if(highlight==2){
           M.menu_S(highlight,4);
        }
        else if(highlight==3){
           M.menu_S(highlight,4);
        }

        if(select==10){ //10 = premo invio per selezionare il campo 
            if(highlight==0){
                M.delete_W(win); //Usare Ncurses?
                clear();
                refresh();

                play(); //chiamata a test_ata
                
                M.create_W();
                M.menu_start();
            
            }
            else if(highlight==1){
                M.delete_W(win);
                clear();
                refresh();
                
                R.scr();

                M.create_W();
                M.menu_start();
            }
            else if(highlight==3){
                pass = false;
            }

            highlight = 0;
            M.menu_S(highlight,4);
            //else if(highlight==2)
        }
        refresh();
    }

    M.delete_W(win);

    endwin();
    return 0;
}
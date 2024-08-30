#include "class_menu.h"
#include "game_engine.h"
#include "salvataggio_punteggio/write_lead.h"
#include "options.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


int main(int argc, char ** argv){

    WINDOW* win;
    WINDOW* win_rank;
    WINDOW* exit; //Che Davoli è?


    menu Menu(win,4,0,0);
    Read_menu R(win,4,0,0,win_rank,exit,4,1,0);
    Menu.create_W();
    Menu.menu_start();

    bool pass = true;
    int select;
    int highlight = 0;
    bool flag = true;

    while(pass){

        select = Menu.get_wg();

        if(select == KEY_UP){
            highlight--;
            if(highlight == -1) highlight = 3;
        }
        else if(select == KEY_DOWN){
            highlight++;
            if(highlight == 4) highlight = 0;
        }

        Menu.menu_S(highlight,4);
        
        if(select == 10){ //10 = premo invio per selezionare il campo
            if(highlight == 0){
                delwin(win);
                clear();
                refresh();

                play(flag); //chiamata a test_ata

                Menu.create_W();
                Menu.menu_start();
            }
            else if(highlight == 1){
                delwin(win);
                clear();
                refresh();

                R.scr();

                Menu.create_W();
                Menu.menu_start();
            }
            else if(highlight == 2){
                delwin(win);
                clear();
                refresh();

                flag = neon();
                Menu.create_W();
                Menu.menu_start();
            }
            else if(highlight == 3){
                pass = false;
            }

            highlight = 0;
            Menu.menu_S(highlight,4);
        }
        refresh();
    }
    delwin(win);

    endwin();
    return 0;
}
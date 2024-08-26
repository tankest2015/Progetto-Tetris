#include "class_menu.h"
#include "game_engine.h"
#include "salvataggio_punteggio/write_lead.h"
#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


int main(int argc, char ** argv) {

    bool pass = true;
    int select;
    int highlight = 0;

    while(pass){
        select = getch();

        if(select == KEY_UP){
            highlight--;
            if(highlight == -1)
                highlight = 0;
        }
        else if(select==KEY_DOWN){
            highlight++;
            if(highlight == 4)
                highlight = 3;
        }

        if(highlight==0){
           /*M.menu_S(highlight,4);     COMMENTAMENTO PROVVISORIO*/
        }
        else if(highlight==1){
           /*M.menu_S(highlight,4);     COMMENTAMENTO PROVVISORIO*/
        }
        else if(highlight==2){
           /*M.menu_S(highlight,4);     COMMENTAMENTO PROVVISORIO*/
        }
        else if(highlight==3){
           /*M.menu_S(highlight,4);     COMMENTAMENTO PROVVISORIO*/
        }

        if(select==10){ //10 = premo invio per selezionare il campo 
            if(highlight==0){
                /*M.delete_W(win);      COMMENTAMENTO PROVVISORIO*/
                clear();
                refresh();

                play(); //chiamata a test_ata
                
                /*M.create_W();      COMMENTAMENTO PROVVISORIO*/
                /*M.menu_start();     COMMENTAMENTO PROVVISORIO*/
            
            }
            else if(highlight==1){
                /*M.delete_W(win);     COMMENTAMENTO PROVVISORIO*/
                clear();
                refresh();
                
                /*R.scr();     COMMENTAMENTO PROVVISORIO*/

                /*M.create_W();     COMMENTAMENTO PROVVISORIO*/
                /*M.menu_start();     COMMENTAMENTO PROVVISORIO*/
            }
            else if(highlight==3){
                pass = false;
            }

            highlight = 0;
            /*M.menu_S(highlight,4);     COMMENTAMENTO PROVVISORIO*/
            //else if(highlight==2)
        }
        refresh();

    }


    /*M.delete_W(win);     COMMENTAMENTO PROVVISORIO*/

    endwin();
    return 0;
}
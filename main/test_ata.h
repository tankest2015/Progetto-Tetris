#include "tetramini.h"
#include "board.h"
#include "style_game.h"
#include <iostream>
#include <ncurses.h>
#include "pause.h"
#include "salvataggio_punteggio/write_lead.h"
#include <ctime>
#include <time.h>
#include <unistd.h>

using namespace std;

#ifndef _TEST_ATA__H_
#define _TEST_ATA__H_

void play(){

    initscr();
    noecho();
    curs_set(0);

    int close = 0;

    
    
    tetramino *pointer;
    Board griglia(0);
    pointer = gen_tetramino(griglia);
    WINDOW* win = set_win();
    if(!has_colors) mvwprintw(win, 40, 10, "Daltonico"); //DA CAMBIARE
    set_colors(true); //preso dal menu
    print_gamespace(win);

    keypad(win, true);
    int movement;
    int timer = 0, delay = 1000;   //in millisecondi
    while(!is_game_over(pointer, griglia) && close == 0){
        print_griglia(win, griglia);
        do{
                
            wtimeout(win, delay);
            movement = wgetch(win);
            switch (movement){
                case KEY_LEFT:
                    pointer->move_left(griglia);
                    timer = timer + 250;
                    break;

                case KEY_RIGHT:
                    pointer->move_right(griglia);
                    timer = timer + 250;
                    break;

                case 97:
                    pointer->left_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 100:
                    pointer->right_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 27:
                    close = Pause(win);
                    break;

                default:
                    if(movement == KEY_DOWN || movement == ERR) timer = timer + delay;
                    break;
                }
            }while (timer < delay && close == 0);
            if(close == 0)
            {
                if(!pointer->descend(griglia)){         //se descend è true fa la discesa, se è false crea una collisione  
                    clear_full_rows(pointer, griglia, win);
                    delete pointer;
                    pointer = gen_tetramino(griglia);
                    cout<<griglia.score<<endl; 
                }

                if(griglia.score < 1000) delay = 1000;
                else if(griglia.score < 3000) delay = 500;
                else if(griglia.score < 7000) delay = 300;
                else if(griglia.score >= 7000) delay = 150;
                timer = 0;
            } 
    }
    if(close == 0)
    {
        clear();
        refresh();
        insert(griglia.score);
    }
    else
    {
    cout<<close<<endl;
        wclear(win);
        wrefresh(win);
        delwin(win);
        clear();
        refresh();
    }
    
    /*
    tetramino *pointer;
    Board griglia(0);
    pointer = gen_tetramino(griglia);
    char c = 'k';
    while (c != 'q')
    {
        griglia.print_matrix();
        switch (c){
                case 'a':
                    pointer->move_left(griglia);
                    break;

                case 'd':
                    pointer->move_right(griglia);
                    break;
                
                case 'n':
                    pointer->left_rotation(griglia);
                    break;

                case 'm':
                    pointer->right_rotation(griglia);
                    break;

                default:
                    break;
            }
        cin >> c;
        if(!pointer->descend(griglia)){         //se descend è true fa la discesa, se è false crea una collisione  
            clear_full_rows(pointer, griglia);
            delete pointer;
            pointer = gen_tetramino(griglia); 
        }
    }*/

}

#endif _PAUSE_H_
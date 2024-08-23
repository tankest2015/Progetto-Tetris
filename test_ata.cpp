#include "tetramini.h"
#include "board.h"
#include "style_game.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

int main(){

    initscr();
    noecho();
    curs_set(0);

    
    tetramino *pointer;
    Board griglia(0);
    pointer = gen_tetramino(griglia);
    WINDOW* win = set_win();
    if(!has_colors) mvwprintw(win, 40, 10, "Daltonico"); //DA CAMBIARE
    set_colors(false); //preso dal menu
    print_gamespace(win);

    keypad(win, true);
    int movement;
    int timer = 0, delay = 1000;   //in millisecondi
    while(!is_game_over(pointer, griglia)){
        print_griglia(win, griglia);
        do{
            wtimeout(win, delay);
            movement = wgetch(win);
            switch (movement){
                case KEY_LEFT:
                    pointer->move_left(griglia);
                    timer = timer + 250;                    //150/200
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

                default:
                    if(movement == KEY_DOWN || movement == ERR) timer = timer + delay;
                    break;
            }
            print_griglia(win, griglia); 
        } while (timer < delay);

        if(!pointer->descend(griglia)){         //se descend è true fa la discesa, se è false crea una collisione  
            clear_full_rows(pointer, griglia, win);
            delete pointer;
            pointer = gen_tetramino(griglia); 
        }

        if(griglia.score < 1000) delay = 1000;
        else if(griglia.score < 3000) delay = 500;
        else if(griglia.score < 7000) delay = 300;
        else if(griglia.score >= 7000) delay = 150;
        timer = 0;
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
    endwin();
    cout << "Game Over [Rantegoso! Ti spacco la faccia!]" << endl; //DA TOGLIERE
    return 0;

}

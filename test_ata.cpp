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

    Board griglia(0);
    tetramino *pointer = gen_tetramino(griglia);
    pointer->board_delete_assign(true, griglia, pointer->get_colour());
    tetramino *next_pointer = gen_tetramino(griglia);

    WINDOW* win = set_win();
    WINDOW* win_info = set_info_window();
    WINDOW* win_predict = set_predict_window();

    if(!has_colors) mvwprintw(win, 40, 10, "Daltonico"); //DA CAMBIARE
    set_colors(false); //false per modalità neon
    print_gamespace(win);
    info_window(win_info, griglia);
    predict_window(win_predict, next_pointer);

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

                default:
                    if(movement == KEY_DOWN || movement == ERR) timer = timer + delay;
                    break;
            }
            print_griglia(win, griglia); 
        } while (timer < delay);

        if(!pointer->descend(griglia)){         //se descend è true fa la discesa, se è false crea una collisione  
            clear_full_rows(pointer, griglia, win);
            delete pointer;
            swap_tetramino_pointer(pointer, next_pointer, griglia);
        }

        if(griglia.score < 1000) delay = 1000;
        else if(griglia.score < 1500) delay = 800;
        else if(griglia.score < 2000) delay = 500;
        else if(griglia.score >= 2500) delay = 300;
        timer = 0;
        info_window(win_info, griglia);
        predict_window(win_predict, next_pointer);
    }

    delwin(win);
    delwin(win_info);
    delwin(win_predict);
    
    endwin();

    delete pointer;
    pointer = NULL;
    delete next_pointer;
    next_pointer = NULL;

    cout << "Game Over [Rantegoso! Ti spacco la faccia!]" << endl; //DA TOGLIERE
    return 0;

}

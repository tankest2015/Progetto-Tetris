<<<<<<< HEAD:main/game_engine.cpp
#include "game_engine.h"

using namespace std;

void play(bool mod){

    initscr();
    noecho();
    curs_set(0);
    bool close = false;

    Board griglia(0, 0);         //score iniziale e linee completate
    tetramino *pointer = gen_tetramino(griglia);
    pointer->board_delete_assign(true, griglia, pointer->get_colour());
    tetramino *next_pointer = gen_tetramino(griglia);

    int diff_time;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int h = 0, m = 0, s = 0;

    time_t start_time;
    time_t current_time;
    start_time = time(NULL);    // Ottieni il tempo attuale all'inizio del gioco

    WINDOW* win = set_win();
    WINDOW* win_info = set_info_window();
    WINDOW* win_predict = set_predict_window();
    WINDOW* win_crono = set_crono_window();

    bool flag = true;

    set_colors(mod);        //false per modalità neon
    print_gamespace(win);
    info_window(win_info, griglia);
    predict_window(win_predict, next_pointer);
    crono_window(win_crono, hours, minutes, seconds);

    keypad(win, true);
    int movement;
    int timer = 0, delay = 1000;   //in millisecondi
    while(!is_game_over(pointer, griglia) && close == false){
        current_time = time(NULL);
        diff_time = difftime(current_time, start_time);

        hours = h + diff_time / 3600;
        minutes = m + (diff_time % 3600) / 60;
        seconds = s + diff_time % 60;

        crono_tic_tac(hours, minutes, seconds);
        crono_window(win_crono, hours, minutes, seconds);
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

                case 97:    //a minuscola
                    pointer->left_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 65:    //A maiuscola
                    pointer->left_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 100:   //d minuscola
                    pointer->right_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 68:    //D minuscola
                    pointer->right_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 32:
                    while(flag) {
                        flag = pointer->descend(griglia);
                    }
                    flag = true;
                    timer = delay;
                    break;

                case 27:
                    h = hours;
                    m = minutes;
                    s = seconds;
                    close = pause(); //permette di fermare il tempo dentro il menu di pausa

                    info_window(win_info, griglia);
                    predict_window(win_predict, next_pointer);
                    crono_window(win_crono, h, m, s);
                    start_time = time(NULL);
                    break;

                default:
                    if(movement == KEY_DOWN || movement == ERR) timer = timer + delay;
                    else timer = timer + 250;
                    break;
            }
            print_griglia(win, griglia);
        } while (timer < delay && close == false);

        if(!pointer->descend(griglia)){         //se descend è true fa la discesa, se è false crea una collisione
            clear_full_rows(pointer, griglia, win);
            delete pointer;
            swap_tetramino_pointer(pointer, next_pointer, griglia);
        }

        if(griglia.score < 1000) delay = 1000;      //Soglie di punteggio
        else if(griglia.score < 1500) delay = 800;
        else if(griglia.score < 2000) delay = 500;
        else if(griglia.score >= 2500) delay = 300;
        timer = 0;
        info_window(win_info, griglia);
        predict_window(win_predict, next_pointer);
    }

    if(close == false){
        clear();
        refresh();
        insert(griglia.score, hours, minutes, seconds, griglia.completed_rows);
    }

    delwin(win);
    delwin(win_info);
    delwin(win_predict);
    delwin(win_crono);
    clear();

    endwin();

    delete pointer;
    pointer = NULL;
    delete next_pointer;
    next_pointer = NULL;
=======
#include "game_engine.h"

using namespace std;

void play(bool mod){

    initscr();
    noecho();
    curs_set(0);
    bool close = false;

    Board griglia(0, 0);         //score iniziale e linee completate
    tetramino *pointer = gen_tetramino(griglia);
    pointer->board_delete_assign(true, griglia, pointer->get_colour());
    tetramino *next_pointer = gen_tetramino(griglia);

    int diff_time;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int h = 0, m = 0, s = 0;

    time_t start_time;
    time_t current_time;
    start_time = time(NULL);    // Ottieni il tempo attuale all'inizio del gioco

    WINDOW* win = set_win();
    WINDOW* win_info = set_info_window();
    WINDOW* win_predict = set_predict_window();
    WINDOW* win_crono = set_crono_window();

    bool flag = true;

    set_colors(mod);        //false per modalità neon
    print_gamespace(win);
    info_window(win_info, griglia);
    predict_window(win_predict, next_pointer);
    crono_window(win_crono, hours, minutes, seconds);

    keypad(win, true);
    int movement;
    int timer = 0, delay = 1000;   //in millisecondi
    while(!is_game_over(pointer, griglia) && close == false){
        current_time = time(NULL);
        diff_time = difftime(current_time, start_time);

        hours = h + diff_time / 3600;
        minutes = m + (diff_time % 3600) / 60;
        seconds = s + diff_time % 60;

        crono_tic_tac(hours, minutes, seconds);
        crono_window(win_crono, hours, minutes, seconds);
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

                case 97:    //a minuscola
                    pointer->left_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 65:    //A maiuscola
                    pointer->left_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 100:   //d minuscola
                    pointer->right_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 68:    //D minuscola
                    pointer->right_rotation(griglia);
                    timer = timer + 250;
                    break;

                case 32:
                    while(flag) {
                        flag = pointer->descend(griglia);
                    }
                    flag = true;
                    timer = delay;
                    break;

                case 27:
                    h = hours;
                    m = minutes;
                    s = seconds;
                    close = pause(); //permette di fermare il tempo dentro il menu di pausa

                    info_window(win_info, griglia);
                    predict_window(win_predict, next_pointer);
                    crono_window(win_crono, h, m, s);
                    start_time = time(NULL);
                    break;

                default:
                    if(movement == KEY_DOWN || movement == ERR) timer = timer + delay;
                    else timer = timer + 250;
                    break;
            }
            print_griglia(win, griglia);
        } while (timer < delay && close == false);

        if(!pointer->descend(griglia)){         //se descend è true fa la discesa, se è false crea una collisione
            clear_full_rows(pointer, griglia, win);
            delete pointer;
            swap_tetramino_pointer(pointer, next_pointer, griglia);
        }

        if(griglia.score < 1000) delay = 1000;      //Soglie di punteggio
        else if(griglia.score < 1500) delay = 800;
        else if(griglia.score < 2000) delay = 500;
        else if(griglia.score >= 2500) delay = 300;
        timer = 0;
        info_window(win_info, griglia);
        predict_window(win_predict, next_pointer);
    }

    if(close == false){
        clear();
        refresh();
        insert(griglia.score, hours, minutes, seconds, griglia.completed_rows);
    }

    delwin(win);
    delwin(win_info);
    delwin(win_predict);
    delwin(win_crono);
    clear();

    endwin();

    delete pointer;
    pointer = NULL;
    delete next_pointer;
    next_pointer = NULL;
>>>>>>> 7a04445 (Aggiustamento dei clear sfarfallosi nei menu):game_engine.cpp
}
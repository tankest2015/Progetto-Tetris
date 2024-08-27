#include <ncurses.h>


using namespace std;

void play(){

    initscr();
    noecho();
    curs_set(0);

    WINDOW *stat;
    

    int close = 0;
    int diff_time;
    int h;
    int min;
    int s;
    int xMax,yMax;

    char time_tot[9] ;
    char score[15] ;




    //tempo della partita
    time_t start_time;
    time_t current_time;


    
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


    //##### INIZIO CONTEGGIO DEL TEMPO ####
    start_time = time(NULL);  // Ottieni il tempo attuale all'inizio

    getmaxyx(stdscr, yMax,xMax);    

    stat = newwin(yMax/6,xMax/6,yMax/8,xMax/5);
    box(stat,0,0);
    wrefresh(stat);
    
    
    while(!is_game_over(pointer, griglia) && close == 0){
        current_time = time(NULL);
        diff_time = difftime(current_time, start_time);
        h = diff_time / 3600;
        min = (diff_time %3600) / 60;
        s = diff_time % 60;
        
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
    
                }

                if(griglia.score < 1000) delay = 1000;
                else if(griglia.score < 3000) delay = 500;
                else if(griglia.score < 7000) delay = 300;
                else if(griglia.score >= 7000) delay = 150;

 

                
                // Formatta e stampa il tempo totale
                sprintf(time_tot, "time: %02d:%02d:%02d", h, min, s);
                mvwprintw(stat, 1, 1, "%s", time_tot);

                // Formatta e stampa il punteggio
                sprintf(score, "score: %d", griglia.score);
                mvwprintw(stat, 2, 1, "%s", score);
                wrefresh(stat);
            } 
    }
    if(close == 0)
    {
        clear();
        refresh();
        insert(griglia.score,h,min,s);
    }
    else
    {
    
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




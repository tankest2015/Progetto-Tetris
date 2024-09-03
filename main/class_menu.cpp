#include "class_menu.h"
#include <ncurses.h>

choiches Ch[4] = {
    {"Play"},
    {"Leaderboard"},
    {"Options"},
    {"Exit"}
};

choiches Ch_Menu_pausa[2] = {
    {"Resume"},
    {"Exit"}
};

menu::menu(WINDOW* win, int k, int y, int x){ //costruttore
    this->win = win;
    this->k = k;
    this->win = win;
    this->yMax = y;
    this->xMax = x;
}

void menu::init(){ //funziona che mi inizializza lo schermo
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    getmaxyx(stdscr, yMax, xMax);
}

int menu::get_y(){
    return yMax;
}

int menu::get_x(){
    return xMax;
}

void menu::create_W(){ //mi inizializza la finestra
    init();

    win = newwin(yMax/2, xMax/2, yMax/2 - yMax/4, xMax/2 - xMax/4);
    refresh();

    box(win, 0, 0);
    wrefresh(win);
    keypad(win, true);
}

void menu::menu_start(){ //mi inizializza il menu
    wattron(win, A_BOLD);
    mvwprintw(win, 3, 16, "%s", "_______   ____  _______   _____    _     _____");
    mvwprintw(win, 4, 15, "%s", "|__   __| |  __||__   __| |  __ \\  | |   / ____|");
    mvwprintw(win, 5, 18, "%s", "| |    | |__    | |    | |__) | | |  | (___");
    mvwprintw(win, 6, 18, "%s", "| |    |  __|   | |    |  _  /  | |   \\___ \\");
    mvwprintw(win, 7, 18, "%s", "| |    | |__    | |    | | \\ \\  | |   ____) |");
    mvwprintw(win, 8, 18, "%s", "|_|    |____|   |_|    |_|  \\_\\ |_|  |_____/");

    for(int i = 0; i < 4; i++){
        mvwprintw(win, i + 12, 34, "%s", Ch[i].field);
    }
    wattroff(win, A_BOLD);
    wrefresh(win);
    menu_S(0, 4);
    wrefresh(win);
}

void menu::menu_S(int k, int j){ //evidenzia il corretto campo in cui l'utente si trova
    wattron(win, A_BOLD);
    for(int i = 0; i < j; i++){
        if(k == i){
            wattron(win, A_REVERSE);
            mvwprintw(win, i + 12, 34, "%s", Ch[i].field);
            wattroff(win, A_REVERSE);
            wrefresh(win);
        }
        else{
            mvwprintw(win, i + 12, 34, "%s", Ch[i].field);
            wrefresh(win);
        }
    }
    wattroff(win, A_BOLD);
}

int menu::get_wg(){
    return wgetch(win);
}

Read_menu::Read_menu(WINDOW* win, int k, int y, int x, WINDOW* win_rank, WINDOW* exit, int col, int righe, int i):menu(win, k, y, x){
    this->win_rank = win_rank;
    this->exit = exit;
    this->c = col;
    this->r = righe;
    this->i = i;
}

void Read_menu::create_win_rank(){
    menu::init();

    win_rank = newwin(yMax, xMax - 4, 0, 2);
    wrefresh(win_rank);
    box(win_rank, 0, 0);
    wrefresh(win_rank);
    keypad(win_rank, true);
}

void Read_menu::create_win_exit(){

    exit = newwin(yMax/10, xMax/14, yMax - 4, xMax - 13);
    box(exit, 0, 0);
    wrefresh(exit);
}

void Read_menu::scr(){
    bool flag = false;
    bool fix = true; //flag per verificare se il file è stato modificato o no
    int pos_h;
    bool not_exist = false;

    create_win_rank();

    wattron(win_rank, A_BOLD);
    mvwprintw(win_rank, 1, 31, " _       _____           _____    _____  _____   ____    ____             _____   _____");
    mvwprintw(win_rank, 2, 31, "| |     |  __|    /\\    |  __ \\  |  __| |  __ \\ |  _ \\  / __ \\     /\\    |  __ \\ |  __ \\");
    mvwprintw(win_rank, 3, 31, "| |     | |__    /  \\   | |  | | | |__  | |__) || |_) || |  | |   /  \\   | |__) || |  | |");
    mvwprintw(win_rank, 4, 31, "| |     |  __|  / /\\ \\  | |  | | |  __| |  _  / |  _ < | |  | |  / /\\ \\  |  _  / | |  | |");
    mvwprintw(win_rank, 5, 31, "| |___  | |__  / ____ \\ | |__| | | |__  | | \\ \\ | |_) || |__| | / ____ \\ | | \\ \\ | |__| |");
    mvwprintw(win_rank, 6, 31, "|______||____|/_/    \\_\\|_____/  |____| |_|  \\_\\|____/  \\____/ /_/    \\_\\|_|  \\_\\|_____/");
    mvwprintw(win_rank, 7, 1, "______________________________________________________________________________________________________________________________________________________");
    mvwprintw(win_rank, 8, 31, "Position:");
    mvwprintw(win_rank, 8, 51, "Name:");
    mvwprintw(win_rank, 8, 71, "Time[hh/mm/ss]:");
    mvwprintw(win_rank, 8, 91, "Points:");
    mvwprintw(win_rank, 8, 111, "Completed rows:");
    wattroff(win_rank, A_BOLD);

    fstream file;
    file.open("salvataggio_punteggio/leaderboard.txt", ios::in); //mi apre il file in lettura

    char line[80];

    if(!file.is_open()){ // se il file non esiste eseguo un interrupt
        not_exist = true;
        ofstream f("salvataggio_punteggio/leaderboard.txt");
            f<<"new"<<endl;
        f.close();
        file.open("salvataggio_punteggio/leaderboard.txt", ios::in);
        if(!file.is_open())
        {
            cout<<"errore, file salvataggio non creato "<<endl;
            endwin();
        }
    }

    while(!file.eof()){          //è vero fin tanto che il file non sia finito
        file>>line;

        if(strcmp(line, "ff") ==0){
            c = 10;
            r = 31;
            i = 0;

            file>>line;
            pos_h = stoi(line);

            fix = false;
        }
        else if(strcmp(line, "tt") == 0){
            c = 10;
            r = 31;
            i = 0;

            file>>line;
            pos_h = stoi(line);

            fix = true;
        }
        else if(strcmp(line,"new")==0)
        {
            c = 10;
            r = 31;
            i = 0;

            fix = false;
        }
        else if(strcmp(line, "n") == 0){
            c++;
            r = 31;
            i++;
        }
        else{
            if(i<30){
            if(i == pos_h-1){
                    wattron(win_rank, A_REVERSE);
                    mvwprintw(win_rank, c, r, "%s", line);
                    wattroff(win_rank, A_REVERSE);
                }
                else mvwprintw(win_rank, c, r, "%s", line);
                r = r + 20;
            }
        }
    }


    file.close();//chiude il file

    if(fix){         // se vero allora nella prima riga c'è tt quindi il file in precendenza è stato modificato

        fstream fileR;
        fileR.open("salvataggio_punteggio/leaderboard.txt", std::ios::in | std::ios::out);

        fileR<<"ff"<<endl;

        fileR.close();
        fix = false;
    }

    wrefresh(win_rank);

    create_win_exit();

    wattron(exit, A_REVERSE | A_BOLD);
    mvwprintw(exit, 1, 3, "EXIT");
    wattroff(exit, A_REVERSE | A_BOLD);
    int car;

    while(!flag){
        car = wgetch(exit);
        if(car == 10) flag = true;
    }

    delwin(exit);
    delwin(win_rank);
    clear();

    endwin();
}

Menu_pausa::Menu_pausa(WINDOW* win, int k, int y, int x, WINDOW* P, int xMax,int yMax, int c):menu(win, k, y, x){
    this->P = P;
    this->x = xMax;
    this->y = yMax;

}

void Menu_pausa::create_W(){
    menu::init();

    P = newwin(yMax/2 + 3, xMax/2, yMax/2 - yMax/4 - 3, xMax/2 - xMax/4);

    wattron(P, A_BOLD);
    mvwprintw(P, 3, 18, " _____            _    _    _____   ____");
    mvwprintw(P, 4, 18, "|  __ \\    /\\    | |  | |  / ____| |  __|");
    mvwprintw(P, 5, 18, "| |__) |  /  \\   | |  | | | (___   | |__");
    mvwprintw(P, 6, 18, "|  ___/  / /\\ \\  | |  | |  \\___ \\  |  __|");
    mvwprintw(P, 7, 18, "| |     / ____ \\ | |__| |  ____) | | |__");
    mvwprintw(P, 8, 18, "|_|    /_/    \\_\\ \\____/  |_____/  |____|");
    wattroff(P, A_BOLD);

    box(P, 0, 0);
    wrefresh(P);
    keypad(P, true);
}

void Menu_pausa::menu_start(){
    wattron(P, A_BOLD);
    for(int i = 0; i < 2; i++){
        mvwprintw(P, i + i + 14, 35 + i, "%s",Ch_Menu_pausa[i].field);
    }
    wattroff(P, A_BOLD);
    wrefresh(P);

    Menu_pausa::menu_S(0, 2);
}

void Menu_pausa::menu_S(int k, int j){
    wattron(P, A_BOLD);
    for(int i = 0; i < j; i++){
        if(k == i){
            wattron(P, A_REVERSE);
            mvwprintw(P, i + i + 14, 35 + i, "%s", Ch_Menu_pausa[i].field);
            wattroff(P, A_REVERSE);
        }
        else mvwprintw(P, i + i + 14, 35 + i, "%s", Ch_Menu_pausa[i].field);
    }
    wattroff(P, A_BOLD);
}

void Menu_pausa::delete_W(){
    wclear(P);
    wrefresh(P);
    delwin(P);
    P = NULL;
}

int Menu_pausa::get_wg(){
    return wgetch(P);
}
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>


using namespace std;

void insert_line(fstream &newFile, int pos_prec, char pc[], char Nm[], char Tim[], char copy[], char B[]){
    char mess[80];
    //pos insert
    sprintf(pc, "%d", pos_prec);
    strcpy(mess, pc);
    strncat(mess,"      ",5);

    //name_insert
    strncat(mess, Nm, 24);
    strncat(mess,"      ",5);

    //time_insert
    strncat(mess,Tim,9);
    strncat(mess,"      ",5);

    //point_insert
    strncat(mess, copy, 6);
    strncat(mess,"      ",5);

    //line_insert
    strncat(mess, B, 6);

    newFile << mess << endl;
    newFile << "n" << endl;
}

void write(char h[], char min[], char s[], char point[], char name[], char line[]){

    //const int max_l_I = 25;
    const int length = 100;
    char input[length];

    char time[9];//time [9] = '\0'
    char mess[80];
    char mess_1[80];

    if (strlen(h) == 1) {
        // Sposta il carattere corrente alla fine e aggiungi '0' all'inizio
        h[1] = h[0]; // Sposta il numero che ho ora a destra
        h[0] = '0';    // Aggiungi '0' all'inizio
        h[2] = '\0';   // Aggiungi il terminatore nullo
    }
    if (strlen(min) == 1) {
        // Sposta il carattere corrente alla fine e aggiungi '0' all'inizio
        min[1] = min[0]; // Sposta il numero che ho ora a destra
        min[0] = '0';    // Aggiungi '0' all'inizio
        min[2] = '\0';   // Aggiungi il terminatore nullo
    }
    if (strlen(s) == 1) {
        // Sposta il carattere corrente alla fine e aggiungi '0' all'inizio
        s[1] = s[0]; // Sposta il numero che ho ora a destra
        s[0] = '0';    // Aggiungi '0' all'inizio
        s[2] = '\0';   // Aggiungi il terminatore nullo
    }

    strcpy(time,h);
    strcat(time,":");
    strncat(time,min,2);
    strcat(time,":");
    strncat(time,s,2);

    cout<<"tempo [hh:mm:ss]: "<< time <<endl;
    cout<<"score: "<< point <<endl;

    char file_tmp[] = {"salvataggio_punteggio/tmp.txt"};
    char file_final[] = {"salvataggio_punteggio/leaderboard.txt"};

    ofstream newF;
    newF.open(file_tmp, ofstream::out | ios::trunc); //"pulisco" il file dove salvo temporaneamente i dati ordinati

    newF.close();

    int j=1;
    fstream file;
    file.open(file_final, ios::in); //apro in lettura il file dove sono
                                    //salvati i miei dati ordinati tranne per quello che devo inserire

    fstream newFile;
    newFile.open(file_tmp, ios::app);//apro il file precedentemente pulito in append

    char line_pos[80]; //con questo leggo le righe del file text1.txt
    char copy[10];     //mi salvo il punteggio della riga corrente
    char pc[4];        //char per convertire da char ad intero
    bool flag = false;
    int i = 0;
    int pos_prec = 0;      //indice che mi salva la posizione del giocatore corrente
    bool flagI = false;

    char Nm[24];
    char Tim[9];
    char B[6];
    char P[6];

    if(!file.is_open()){ // is file doesn't exits i do an interrupt file = test1.txt
        cout<<"error to open file "<<endl;
    }
    else{
        while(!file.eof()){ //continuo fin tanto che il file non sia arrivato all'ultima riga
                            //mi ricavo se la prima riga del file il flag
                            // altrimenti la posizione del giocatore

            //pos
            file>>line_pos;
            strcpy(mess,line_pos);
            strncat(mess,"      ",5);

            if(!strcmp(line_pos,"") == 0 && !strcmp(line_pos,"ff") == 0 && !strcmp(line_pos,"tt") == 0){
                if(!strcmp(line_pos,"n") == 0){
                    //mi legge i dati della classifica nel file text1.txt
                    pos_prec = stoi(line_pos); //mi salva la posizione in cui sono ora

                    /*
                    posso ricavare solo ora la posizione perché
                    sono sicuro che sia la posizione e non un "\n" o un flag("ff","tt");
                    */

                    //name
                    file >> line_pos;
                    strncat(mess, line_pos, 24);
                    strncat(mess, "      ", 5);
                    strcpy(Nm, line_pos);

                    //time
                    file>>line_pos;
                    strncat(mess, line_pos,9);
                    strncat(mess, "      ", 5);
                    strcpy(Tim, line_pos);

                    //point
                    file >> line_pos;
                    strncat(mess, line_pos, 6);
                    strncat(mess, "      ", 5);
                    strcpy(copy, line_pos);

                    //completed rows
                    file >> line_pos;
                    strncat(mess, line_pos, 6);
                    strcpy(B, line_pos);

                    // mi ricavo tutti i dati che mi servono;

                    if(flag){
                        pos_prec++;
                        insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);     //se flag è attivo vuol dire che ho già inserito il nuovo giocatore
                    }                                                             //quindi inserisco nel file text_final.txt tutti glil altri con la posizione aggiornata,
                    else if(flagI){
                        //discorso molto simile per il flag ma in questo caso se è attivo flagI vuol dire che
                        //il punteggio e il tempo sono perfettamente equivalenti e mi tiene uguale la posizione.
                        insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                    }
                    /*
                    ci possono essere 3 casi:

                    1°: il punteggio del giocatore che devo inserire è minore di quello che sto leggendo in questo momento
                        quindi mi inserisce nel file il giocatore corrente.

                    2°: è maggiore quindi mi inscerisce prima il giocatore che devo inserire con la posizione di pos aggiornata(e di tutti gli altri)

                    3°: il punteggio è pari quindi confronto il tempo dei giocatori.
                    */
                    else if(stoi(copy) <= stoi(point) && !flag){

                        char ore[3] = {0};
                        char minuti[3] = {0};
                        char secondi[3] = {0};
                        if(stoi(copy)==stoi(point)){
                            if(stoi(s)==stoi(strncpy(secondi, Tim + 6, 2))){
                                if(stoi(min)==stoi(strncpy(minuti, Tim + 3, 2))){
                                    if(stoi(h)==stoi(strncpy(ore, Tim, 2))){
                                        insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B); //inserisco la linea che ho ricavato dal file
                                        insert_line(newFile, pos_prec, pc, name, time, point, line);//inserisco la linea che devo inserire
                                        flagI = true;
                                    }
                                    else if(stoi(h)>stoi(strncpy(ore, Tim, 2)))
                                        insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                                    else{
                                        flag = true;

                                        insert_line(newFile, pos_prec, pc, name, time, point, line);
                                        pos_prec++;
                                        insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                                    }
                                }
                                else if(stoi(min) > stoi(strncpy(minuti, Tim + 3, 2)))
                                    insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                                else{
                                    flag = true;

                                    insert_line(newFile, pos_prec, pc, name, time, point, line);
                                    pos_prec++;
                                    insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                                }
                            }
                            else if(stoi(s) > stoi(strncpy(secondi, Tim + 6, 2)))
                                insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                            else{
                                flag = true;

                                insert_line(newFile, pos_prec, pc, name, time, point, line);
                                pos_prec++;
                                insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                            }
                        }
                        else{
                            flag = true;
                            insert_line(newFile, pos_prec, pc, name, time, point, line);
                            pos_prec++;
                            insert_line(newFile, pos_prec, pc, Nm, Tim, copy, B);
                        }
                    }
                    else{
                        newFile << mess << endl;
                        newFile << "n" << endl;
                    }
                }
            }
        }
    }

    if(!flag && !flagI){ //se entrambi sono false deve ancora essere inserito nel file
        flag = true;
        flagI = true;

        pos_prec++;
        insert_line(newFile, pos_prec, pc, name, time, point, line);
    }

    file.close();
    newFile.close();
    // chiudo tutti i file;

    ofstream F;
    F.open(file_final, ofstream::out | ios::trunc); //pulisce tutto il file e mi aggiorna il flag della modifica

    F<<"tt"<<endl; // tt perché ho inserito un nuovo giocatore;

    F.close();

    fstream final;
    final.open(file_tmp, ios::in);

    fstream file_text;
    file_text.open(file_final, ios::app);
    char read[80];

    while(!final.eof()){ // ricopio i dati dal file test_final.txt a test1.txt + il relativo flag
        final >> read;
        strcpy(mess, read);
        strncat(mess, "      ", 5);

        if(!strcmp(read, "n") == 0){

            final >> read;
            strncat(mess, read, 24);
            strncat(mess, "      ", 5);

            final >> read;
            strncat(mess, read, 9);
            strncat(mess, "      ", 5);


            final >> read;
            strncat(mess, read, 6);
            strncat(mess, "      ", 5);

            final >> read;
            strncat(mess, read, 6);

            final >> read;
            file_text << mess << endl;
            file_text << "n" << endl;

        }
    }
    file_text.close();
    final.close();

    remove(file_tmp);

}


void del_ch(WINDOW* player, char text[], int i, int limit){
    text[i] = '\0';

    if(i > -1){
        
        mvwdelch(player, 13, i + 2);
        mvwprintw(player, 13, 2, "%-*s", limit, text);  // Ripulisce la riga e riscrive la stringa aggiornata
        box(player, 0, 0);
        wrefresh(player);
    }
}

bool check(char text[]){
    int i = 0;
    bool flag = false;
    if(text[i] == '\0')
        flag = true;
    else{
        while(text[i] != '\0' && !flag){
            if(text[i] == char(32))
                flag = true;
            i++;
        }
    }
    return flag;
}

void insert(int p,int h,int min,int s, int row){

    initscr();
    noecho();
    cbreak();
    refresh();


    bool flag = false;
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);

    int i = 0;

    WINDOW *player;
    player = newwin(yMax/2, xMax/2, yMax/2 - yMax/4, xMax/2 - xMax/4);
    box(player, 0, 0);
    mvwprintw(player, 3, 3, "%s", "_____              __  __   _____       ____   __      __  _____  _____");
    mvwprintw(player, 4, 2, "%s", "/ ____|     /\\     |  \\/  | |  __|      / __ \\  \\ \\    / / |  __| |  __ \\");
    mvwprintw(player, 5, 1, "%s", "| |  __     /  \\    | \\  / | | |__      | |  | |  \\ \\  / /  | |__  | |__) |");
    mvwprintw(player, 6, 1, "%s", "| | |_ |   / /\\ \\   | |\\/| | |  __|     | |  | |   \\ \\/ /   |  __| |  _  /");
    mvwprintw(player, 7, 1, "%s", "| |__| |  / ____ \\  | |  | | | |__      | |__| |    \\  /    | |__  | | \\ \\");
    mvwprintw(player, 8, 1, "%s", " \\_____| /_/    \\_\\ |_|  |_| |____|      \\____/      \\/     |____| |_|  \\_\\");
    mvwprintw(player, 12, 1, "INSERT NAME:");
    wrefresh(player);

    keypad(player, true);



    int ch;
    bool BSp = false;
    char text[24] = {'\0'};
    char hour[3] = {'\0'};
    char minute[3] = {'\0'};
    char second[3] = {'\0'};
    char point[6] = {'\0'};
    char completed_rows[6] = {'\0'};

    sprintf(point, "%d", p);
    sprintf(hour, "%d", h);
    sprintf(minute, "%d", min);
    sprintf(second, "%d", s);
    sprintf(completed_rows, "%d", row);

    getmaxyx(player, yMax, xMax);

    mvwprintw(player, 15, 50, "%s", "Score: ");
    mvwprintw(player, 15, 58,"%s", point);
    mvwprintw(player, 16, 50, "%s", "row: ");
    mvwprintw(player, 16, 56,"%s", completed_rows);

    mvwprintw(player, 17, 50, "%s", "time: ");
    mvwprintw(player, 17, 57, "%s", hour);
    wprintw(player,"%s", " : ");
    wprintw(player,"%s", minute);
    wprintw(player,"%s", " : ");
    wprintw(player,"%s", second);
    wrefresh(player);


    while(!flag){
        ch = wgetch(player);
        if(ch == 10){ //10 = invio
            BSp = check(text);

            if(BSp){
                mvwprintw(player, 14, 2, "%s", "è presente un carattere non valido");
                while(i > 0){
                    i--;
                    del_ch(player, text, i, xMax);
                }
            }
            else{
                write(hour, minute, second, point, text, completed_rows);

                wclear(player);
                wrefresh(player);
                delwin(player);

                flag = true;
            }
        }
        else if(ch == KEY_BACKSPACE){
            if(i > 0){
                i--;
                del_ch(player, text, i, xMax);
            }
        }
        else if(ch != KEY_UP && ch != KEY_DOWN && ch != KEY_LEFT && ch != KEY_RIGHT && ch != 27){
            if(i < sizeof(text) - 1){

                wmove(player, 14, 1);
                wclrtoeol(player);
                wrefresh(player);

                box(player, 0, 0);
                wrefresh(player);

                text[i] = (char) ch;
                mvwprintw(player, 13, 2, "%s", text);
                wrefresh(player);
                i++;
            }
        }
    }
    endwin();
}
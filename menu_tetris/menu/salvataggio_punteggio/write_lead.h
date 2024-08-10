    /*
    #####
    Is part of the std namespace and refers to a set of flags and constants used to control the behavior of input/output (I/O) streams. 
    These flags are used in conjunction with classes like std::ios_base
    #####

    std::ios::in: File open mode for reading.
    std::ios::out: File open mode for writing.
    std::ios::binary: File open mode for binary mode.
    std::ios::app: File open mode for appending to the end of the file.
    std::ios::ate: File open mode with the file pointer positioned at the end of the file.
    std::ios::trunc: If the file already exists, its contents are truncated upon opening.
    std::ios::ate: The file pointer is positioned at the end of the file after opening.
    std::ios::in | std::ios::out: File open mode for reading and writing simultaneously.
    */


    /*
    ofstream including ios::out
    ifstream including ios::in

    fstream including none 
    */


#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>


using namespace std;

#ifndef _WRITE_LEAD_H_
#define _WRITE_LEAD_H_


void insert_line(fstream &newFile,int pos_prec,char pc[],char Nm[],char Tim[],char copy[],char B[])
{
    char mess[80];
    //pos insert
    sprintf(pc, "%d", pos_prec);
    strcpy(mess,pc);
    strncat(mess,"      ",5);

    //name_insert
    strncat(mess,Nm,10);
    strncat(mess,"      ",5);

    //time_insert
    strncat(mess,Tim,9);
    strncat(mess,"      ",5);

    //point_insert
    strncat(mess,copy,6);
    strncat(mess,"      ",5);

    //line_insert
    strncat(mess,B,6);
                        
    newFile<<mess<<endl;
    newFile<<"n"<<endl;  
}


void write(char h[],char min[],char s[],char point[],char name[],char line[])
{

    
    //const int max_l_I = 25;
    const int length = 100;
    char input[length];
    
    char time[9];//time [9] = '\0'
    char mess[80];
    char mess_1[80];


    strcpy(time,h);
    strcat(time,":");
    strncat(time,min,2);
    strcat(time,":");
    strncat(time,s,2);
 

    ofstream newF;
    newF.open("salvataggio_punteggio/test_final.txt",ofstream::out | ios::trunc); //"pulisco" il file dove salvo temporaneamente i dati ordinati

    newF.close();

       
        int j=1;
        fstream file;
        file.open("salvataggio_punteggio/test1.txt", ios::in); //apro in lettura il file dove sono 
                                                               //salvati i miei dati ordinati tranne per quello che devo inserire
        
        fstream newFile;
        newFile.open("salvataggio_punteggio/test_final.txt", ios::app);//apro il file precedentemente pulito in append

        char line_pos[80]; //con questo leggo le righe del file text1.txt
        char copy[10];     //mi salvo il punteggio della riga corrente
        char pc[4];        //char per convertire da char ad intero 
        bool flag = false; 
        int i = 0;
        int pos_prec;      //indice che mi salva la posizione del giocatore corrente
        bool flagI = false;

        char Nm[20];       
        char Tim[9];
        char B[6];
        char P[6];

        if(!file.is_open()) // is file doesn't exits i do an interrupt file = test1.txt 
            cout<<"error to open file "<<endl;
        else
        {
            while(!file.eof())//continuo fin tanto che il file non sia arrivato all'ultima riga
            {
                //mi ricavo se la prima riga del file il flag
                // altrimenti la posizione le giocatore
                
                //pos
                file>>line_pos;
                strcpy(mess,line_pos);
                strncat(mess,"      ",5);
                
                if(!strcmp(line_pos,"")==0 && !strcmp(line_pos,"ff")==0 && !strcmp(line_pos,"tt")==0)
                {
                    if(!strcmp(line_pos,"n")==0)
                    {
                        //mi legge i dati della classifica nel file text1.txt
                        pos_prec = stoi(line_pos); //mi salva la posizione in cui sono ora 

                        /*
                        posso ricavare solo ora la posizione perché 
                        sono sicuro che sia la posizione e non un "\n" o un flag("ff","tt");
                        */
                        
                        //name
                        file>>line_pos;
                        strncat(mess,line_pos,10);
                        strncat(mess,"      ",5);
                        strcpy(Nm,line_pos);

                        //time
                        file>>line_pos;
                        strncat(mess,line_pos,9);
                        strncat(mess,"      ",5);
                        strcpy(Tim,line_pos);
                        
                        //point
                        file>>line_pos;
                        strncat(mess,line_pos,6);
                        strncat(mess,"      ",5);
                        strcpy(copy,line_pos);

                        //block
                        file>>line_pos;
                        strncat(mess,line_pos,6);
                        strncat(mess,"      ",5);
                        strcpy(B,line_pos);

                        // mi ricavo tutti i dati che mi servono;
                        
                        if(flag)
                        {
                        //se flag è attivo vuol dire che ho già inserito il nuovo giocatore
                        //quindi inserisco nel file text_final.txt tutti glil altri con la posizione aggiornata,
                            insert_line(newFile,pos_prec++,pc,Nm,Tim,copy,B);  
                        }
                        else if(flagI)
                        {  
                            //discorso molto simile per il flag ma in questo caso se è attivo flagI vuol dire che
                            //il punteggio e il tempo sono perfettamente equivalenti e mi tiene uguale la posizione.
                            insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                        }
                        /*
                        ci possono essere 3 casi:

                        1°: il punteggio del giocatore che devo inserire è minore di quello che sto leggendo in questo momento
                            quindi mi inserisce nel file il giocatore corrente.

                        2°: è maggiore quindi mi inscerisce prima il giocatore che devo inserire con la posizione di pos aggiornata(e di tutti gli altri)

                        3°: il ounteggio è pari quindi confronto il tempo dei giocatori. 
                        */
                        else if(stoi(copy)<=stoi(point) && !flag) 
                        {
                            
                            char ore[3] = {0};
                            char minuti[3] = {0};
                            char secondi[3] = {0};
                            if(stoi(copy)==stoi(point))
                            {         
                                if(stoi(h)==stoi(strncpy(ore,Tim,2)))
                                {
                                    if(stoi(min)==stoi(strncpy(minuti,Tim+3,2)))
                                    {
                                        if(stoi(s)==stoi(strncpy(secondi,Tim+6,2)))
                                        {
                                            insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B); //inserisco la linea che ho ricavato dal file  
                                            insert_line(newFile,pos_prec,pc,name,time,point,line);//inserisco la linea che devo inserire
                                            flagI = true;                                                        
                                        }
                                        else if(stoi(s)>stoi(strncpy(secondi,Tim+6,2)))
                                        {  
                                            insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                                        }
                                        else
                                        {
                                            flag = true;

                                            insert_line(newFile,pos_prec,pc,name,time,point,line);
                                            pos_prec++;
                                            insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                                        }
                                    }
                                    else if(stoi(min)>stoi(strncpy(minuti,Tim+3,2)))
                                    {
                                        insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);   
                                    }
                                    else
                                    {
                                        flag = true;

                                        insert_line(newFile,pos_prec,pc,name,time,point,line);
                                        pos_prec++;
                                        insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                                    }
                                }
                                else if(stoi(h)>stoi(strncpy(ore,Tim,2)))
                                {
                                    insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                                }
                                else 
                                {
                                    flag = true;
                                
                                    insert_line(newFile,pos_prec,pc,name,time,point,line);
                                    pos_prec++;
                                    insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                                }
                            }
                            else
                            {
                                flag = true;
                                pos_prec++;  
                                insert_line(newFile,pos_prec,pc,name,time,point,line);
                                insert_line(newFile,pos_prec,pc,Nm,Tim,copy,B);
                                    
                            }
                        }
                        else
                        {
                            newFile<<mess<<endl;
                            newFile<<"n"<<endl;        
                        }
                    }
            }        
        }
    }

    if(!flag && !flagI) //se entrambi sono false deve ancora essere inserito nel file
    {
        flag = true;
        flagI = true;
        
        pos_prec++;
        insert_line(newFile,pos_prec,pc,name,time,point,line);
    }
        
    file.close();
    newFile.close();
    // chiudo tutti i file;

    ofstream F;
    F.open("salvataggio_punteggio/test1.txt",ofstream::out | ios::trunc); //pulisce tutto il file e mi aggiorna il flag della modifica

    F<<"tt"<<endl; // tt perché ho inserito un nuovo giocatore;

    F.close();

    fstream final;
    final.open("salvataggio_punteggio/test_final.txt", ios::in);
    
    fstream file_text;
    file_text.open("salvataggio_punteggio/test1.txt", ios::app);
    char read[80];

    while(!final.eof()) // ricopio i dati dal file test_final.txt a test1.txt + il relativo flag
    {
        final>>read;
        strcpy(mess,read);
        strncat(mess,"      ",5);
        
        if(!strcmp(read,"n")==0)
        {
            
            final>>read;
            strncat(mess,read,10);
            strncat(mess,"      ",5);

            final>>read;
            strncat(mess,read,9);
            strncat(mess,"      ",5);


            final>>read;
            strncat(mess,read,6);
            strncat(mess,"      ",5);

            final>>read;
            strncat(mess,read,6);
            strncat(mess,"      ",5);

            final>>read;
            file_text<<mess<<endl;
            file_text<<"n"<<endl;

        }
    }
    file_text.close();
    final.close();

}


void del_ch(WINDOW *player,char text[],int i)
{
    text[i] = '\0';
    mvwdelch(player, 2, i+1);
    wrefresh(player);

}

bool check(char text[])
{
    int i = 0;
    bool flag = false;
    if(text[i]=='\0')
    {
        flag = true;
    }
    else
    {
        while(text[i]!='\0' && !flag)
        {
            if(text[i]==char(32))
                flag = true;
            i++;
        }
    }
    return flag;
}

void insert() 
{

    initscr();
    noecho();
    cbreak();
    refresh();

 
    bool flag = false;
    int xMax,yMax;
    getmaxyx(stdscr, yMax,xMax);



    int i = 0;


    WINDOW *player;
    player = newwin(yMax/7,xMax/7,yMax/2,xMax/2);
    refresh();
    box(player,0,0);
    wrefresh(player);
    mvwprintw(player,1,1,"INSERT NAME:");
    wrefresh(player);
    
    keypad(player,true);


    //nel in questo momento li inserisco a mano però li devo ricavare quando il giocatore fa game over W.I.P.

    int ch;
    bool BSp = false;
    char text[10] = {0};
    char h[3] = {'0','7','\0'};
    char min[3] = {'4','3','\0'};
    char s[3] = {'0','4','\0'};
    char point[5] = {'2','1','4','5','\0'};
    char block[5] = {'9','0','8','5','\0'};


    while(!flag)
    {
        ch = wgetch(player);
        if(ch == 10) //10 = invio
        {
            BSp = check(text);

            if(BSp)
            {
                mvwprintw(player,3,1,"%s","è presente un carattere non valido");
                while(i>0)
                {
                    i--;
                    del_ch(player,text,i);
                }
            }
            else
            {    
                write(h,min,s,point,text,block);

                wclear(player);
                wrefresh(player);
                delwin(player);

                flag = true;
            }

        }
        else if(ch == KEY_BACKSPACE)
        {
            i--;
            del_ch(player,text,i);
            
        }
        else
        {
            if(i<sizeof(text)-1)
            {
                
                text[i]= (char) ch;
                mvwprintw(player,2,1,"%s",text);
                wrefresh(player);
                i++;
            }


        }
    }

    endwin();
    
}

#endif _WRITE_LEAD_H_
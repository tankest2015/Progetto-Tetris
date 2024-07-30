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
#include <ncurses.h>


using namespace std;

#ifndef _WRITE_LEAD_H_
#define _WRITE_LEAD_H_


int write(char h[],char min[],char s[],char point[],char name[],char line[])
{

    
    //const int max_l_I = 25;
    const int length = 100;
    char input[length];
    
    char time[9];//time [9] = '\0'
    char mess[40];
    char mess_1[40];
    char end[2] = "\n";


    strcpy(time,h);
    strcat(time,":");
    strncat(time,min,2);
    strcat(time,":");
    strncat(time,s,2);
 

    ofstream newF;
    newF.open("salvataggio_punteggio/test_final.txt",ofstream::out | ios::trunc);

    newF.close();

       
        int j=1;
        fstream file;
        file.open("salvataggio_punteggio/test1.txt", ios::in);
        
        fstream newFile;
        newFile.open("salvataggio_punteggio/test_final.txt", ios::app);

        char line_pos[80];
        char copy[10];
        bool flag = false;
        int i = 0;

        if(!file.is_open()) // is file doesn't exits i do an interrupt 
            cout<<"error to open file "<<endl;
        else
        {
            while(!file.eof())
            {
                
                //name
                file>>line_pos;
                strcpy(mess,line_pos);
                strncat(mess,"      ",5);
                
                if(!strcmp(line_pos,"")==0 && !strcmp(line_pos,"ff")==0 && !strcmp(line_pos,"tt")==0)
                {
                 if(!strcmp(line_pos,"n")==0)
                {

                    //time
                    file>>line_pos;
                    strncat(mess,line_pos,9);
                    strncat(mess,"      ",5);



                    //point
                    file>>line_pos;
                    strncat(mess,line_pos,6);
                    strncat(mess,"      ",5);
                    strcpy(copy,line_pos);





                    //block
                    file>>line_pos;
                    strncat(mess,line_pos,6);
                    strncat(mess,"      ",5);
                    strcpy(mess_1,mess);
                

                    if(stoi(copy)<=stoi(point) && !flag)
                    {
                        flag = true;
                        //name_insert
                        strcpy(mess,name);
                        strncat(mess,"      ",5);
                      

                        //time_insert                       
                        strncat(mess,time,9);
                        strncat(mess,"      ",5);
                        
                        //point_insert
                        strncat(mess,point,6);
                        strncat(mess,"      ",5);

                        //line_insert
                        strncat(mess,line,6);

                        newFile<<mess<<endl;
                        newFile<<"n"<<endl;  

                        newFile<<mess_1<<endl;
                        newFile<<"n"<<endl;


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

      if(!flag)
            {
                flag = true;
                //name_insert
                strcpy(mess,name);
                strncat(mess,"      ",5);
                
                //time_insert                       
                strncat(mess,time,9);
                strncat(mess,"      ",5);
                
                //point_insert
                strncat(mess,point,6);
                strncat(mess,"      ",5);
                //line_insert
                strncat(mess,line,6);
                newFile<<mess<<endl;
                newFile<<"n"<<endl;
            }
        
        file.close();
        newFile.close();
    

    ofstream F;
    F.open("salvataggio_punteggio/test1.txt",ofstream::out | ios::trunc); //pulisce tutto il file e mi aggiorna il flag della modifica

    F<<"tt"<<endl;

    F.close();

    fstream final;
    final.open("salvataggio_punteggio/test_final.txt", ios::in);
    
    fstream file_text;
    file_text.open("salvataggio_punteggio/test1.txt", ios::app);
    char read[80];

    while(!final.eof())
    {
        final>>read;
        strcpy(mess,read);
        strncat(mess,"      ",5);
        
        if(!strcmp(read,"n")==0)
        {

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

    return 0;
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

    int ch;
    char text[10] = {0};
    char h[3] = {'0','5','\0'};
    char min[3] = {'1','2','\0'};
    char s[3] = {'1','4','\0'};
    char point[5] = {'2','3','4','5','\0'};
    char block[5] = {'9','0','8','5','\0'};


    while(!flag)
    {
        ch = wgetch(player);
        if(ch == 10) //10 = invio
        {
            write(h,min,s,point,text,block);

            wclear(player);
            wrefresh(player);
            delwin(player);

            flag = true;

        }
        else if(ch == KEY_BACKSPACE)
        {
            i--;
            text[i] = '\0';
            mvwdelch(player, 2, i+1);
            wrefresh(player);

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
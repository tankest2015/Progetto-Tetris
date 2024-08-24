#include <ncurses.h>
#include <iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <cstring>
#include "cronometro.h"


using namespace std;

int main()
{

    char h[2];
    char m[2];
    char s[2];

    int hour;
    int min;
    int second;
    WINDOW *cr;
    cronometro C(cr,0,0,0,NULL,NULL,0,false);



    C.crono();


    hour = C.get_h();
    min = C.get_m();
    second = C.get_s();


    sprintf(h, "%d", hour);
    sprintf(m, "%d", min);
    sprintf(s, "%d", second);
    
    cout<<"hh: "<<h<<endl;
    cout<<"mm: "<<m<<endl;
    cout<<"ss: "<<s<<endl;


    endwin();   
    return 0;
}
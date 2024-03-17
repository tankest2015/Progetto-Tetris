#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int main()
{
    //const int max_l_I = 25;
    const int length = 100;
    char input[length];
    
    char time[9];//time [9] = '\0'
    char point[6] = "1234";
    char name[25] = "Giuorgiuo";
    char line[6] = "124";
    char mess[40];
    char s[2];
    char min[2];
    char h[2];
    char end[2] = "\n";

    cout<<"inserire secondi:"<<endl;
    cin>>s;
    cout<<"inserire minuti:"<<endl;
    cin>>min;
    cout<<"inserire ore:"<<endl;
    cin>>h;

    strcpy(time,h);
    strcat(time,":");
    strncat(time,min,2);
    strcat(time,":");
    strncat(time,s,2);
 

    //cout<<time<<endl;



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
    fstream file;
    file.open("test1.txt", ios::app);


    if(!file.is_open()) // is file doesn't exits i do an interrupt 
        cout<<"error to open file "<<endl;
    else
    {
        cout<<"scrivi qualcosa nel file:"<<endl;
        //cin.getline(input,length);
        strcpy(mess,name);
        strcat(mess," | ");
        strncat(mess,time,9);
        strcat(mess," | ");
        strncat(mess,point,6);
        strcat(mess," | ");
        strncat(mess,line,6);

        file<<mess<<endl;
        file<<"n"<<endl;
    }

    
    file.close();

    return 0;
}
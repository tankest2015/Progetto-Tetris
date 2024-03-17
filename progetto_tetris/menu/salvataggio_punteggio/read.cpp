#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int main()
{
   


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
    file.open("test1.txt", ios::in);
    char line[80];

    if(!file.is_open()) // is file doesn't exits i do an interrupt 
        cout<<"error to open file "<<endl;
    else
    {
        while(!file.eof())
        {
            file>>line;
            if(strcmp(line,"n")==0)
            {
                cout<<endl;
            }
            else
            {
                cout<<line;
            } 
        }
    }

    
    file.close();

    return 0;
}
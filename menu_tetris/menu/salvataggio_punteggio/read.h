#ifndef _READ_H_
#define _READ_H_

void read_file()
{
    int j=1;
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
            if(!strcmp(line,"n")==0)
            {
                mvwprintw(win,j,1,line);
                j++;
            } 
        }
    }

    
    file.close();
}
#endif 

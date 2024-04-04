#ifndef _ORDINAMENTO_H_
#define _ORDINAMENTO_H_

int find_pos(char line)
{
    int j=1;
    fstream file;
    file.open("test1.txt", ios::in);
    char line_pos[80];
    char copy[6];
    bool flag = false;
    int i = 0;

    if(!file.is_open()) // is file doesn't exits i do an interrupt 
        cout<<"error to open file "<<endl;
    else
    {
        while(!file.eof() && !flag)
        {

            file>>line_pos;


            strcpy(copy,line_pos[22]);
            strncat(copy,line_pos[23],1);
            strncat(copy,line_pos[24],1);
            strncat(copy,line_pos[25],1);
            strncat(copy,line_pos[26],1);
            strncat(copy,line_pos[27],1);

            cout<<"point: "<<copy<<endl;

            if((int)copy<(int)line) flag = true;
            else i++;
    
        }
    }

    
    file.close();
}

#endif 

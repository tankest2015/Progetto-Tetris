#include<ncurses.h>
#include<stdlib.h>
#include<stdio.h>



#define ctrl(x) (x & 0x1F)
using namespace std;

int main(int argc,char **argv)
{
    initscr();
    cbreak();
    noecho();


    char c;

    while(c = getch())
    {
        /*
        function is used to get a printable string representation of a keycode. 
        It takes a keycode as an argument and returns a string representing the key's name.
        */
        /*
        function call is used to convert the value of the character c into 
        a hexadecimal code representing its ASCII value as a string. 

        0x: This part of the format specifier indicates that the number should be displayed in hexadecimal format, 
        with the prefix "0x" added before the hexadecimal digits. 

        %02x: This part specifies that the integer should be displayed with a minimum width of 2 characters. 
        If the hexadecimal representation of the number is less than 2 characters wide, 
        it will be padded with leading zeros to reach the specified width.
       */
        refresh();
        mvprintw(1,0,"KEY NAME : %s - 0x%02x\n", keyname(c),c);
        //0x1F to Ctrl + ' ' in this case id 'f'
        // so we can define ctrl look up for how to use :)
        if(c ==ctrl('f'))
        {
            mvprintw(0,0,"Detected Ctrl + f");   
        }
    }

    endwin();

    return 0;
}
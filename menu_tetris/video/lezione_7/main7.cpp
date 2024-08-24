#include <ncurses.h>
#include <string>

using namespace std;

/*void start_ncurses(bool useRaw,bool useNoecho);
void printMenu(WINDOW * menu,string choices[],int size,int highlight);
*/

int main(int argc, char ** argv)
{
    int y,x,yBeg,xBeg,yMax,xMax;
    
    initscr();
    noecho();
    cbreak();

    getmaxyx(stdscr,yMax,xMax);

    WINDOW * menuwin = newwin(6,xMax-12,yMax-8,5);
    box(menuwin,0,0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin,true);

    char *choices[3] = {"Forza Bologna","Forza BFC","Forza RossoBlu"};
    bool pass = true;
    int select;
    int highlight = 0;

    while(pass)
    {
        for(int i = 0;i<3;i++)
        {
            if(i==highlight)
            {
                wattron(menuwin,A_REVERSE);
                mvwprintw(menuwin,i+1,1,choices[i]);
                wattroff(menuwin,A_REVERSE);
            }
        }
        select = wgetch(menuwin);


       /* switch(select)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                {
                    highlight = 0;
                }
            break;

            case KEY_DOWN:
                highlight++;
                if(highlight == 3) highlight = 2;
            break;
            default: 
            break;
        }*/
        if(select == KEY_UP)
        {
            highlight--;
            if(highlight == -1)
            {
                highlight = 0;
            }
        }
        else if(select==KEY_DOWN)
        {
            highlight++;
            if(highlight == 3)
                highlight = 2;
        }

        if(select==10) pass = false;
    }

    
    printw("Your Choices was: %s", choices[highlight]);

    //close the program :)
    getch();
	endwin();

    return(0);
}

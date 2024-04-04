#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
    protected:
        int xLoc,yLoc,yMax,xMax;
        char character;
        WINDOW * curwin;
        char c = '.';

    public:
    Player(WINDOW * win,int y,int x,char c)
    {
        curwin = win;
        yLoc = y;
        xLoc = x;
        getmaxyx(curwin,yMax,xMax);
        keypad(curwin,true);
        character = c;
    }

    void mvup()
    {
        mvwaddch(curwin,yLoc,xLoc,c);
        yLoc--;
        if(yLoc <1)
            yLoc = 1;
    }

    void mvdown()
    {
        mvwaddch(curwin,yLoc,xLoc,c);
        yLoc++;
        if(yLoc >yMax-2)
            yLoc =yMax-2;
    }

    void mvrigth()
    {
        mvwaddch(curwin,yLoc,xLoc,c);
        xLoc++;
        if(yLoc >xMax-2)
            xLoc = xMax-2;
    }

    void mvleft()
    {
        mvwaddch(curwin,yLoc,xLoc,c);
        xLoc--;
        if(xLoc <1)
            xLoc = 1;
    }

    int getmv()
    {
        int choice = wgetch(curwin);

        /*if (choice = KEY_UP)
            mvup();
        else if(choice = KEY_DOWN)
            mvdown();
        else if(choice = KEY_RIGHT)
            mvrigth();
        else if(choice = KEY_LEFT)
            mvleft();*/

        switch (choice)
        {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_RIGHT:
            mvrigth();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        default:
            break;
        }
        return(choice);
    }

    void display()
    {
        mvwaddch(curwin,yLoc,xLoc,character);
    }

};

#endif 






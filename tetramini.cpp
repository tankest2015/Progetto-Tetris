#include <iostream>
#include <ctime>
#include <cstdlib>
#include "board.h"

using namespace std;
#define rows 4
#define cols 4

struct Position {
    int x;
    int y;
};


class tetramino {
    protected:
        int colour;
        int rot_id;
        /*int data[rows][cols];*/
   
        /*void set_matrix() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = 0;
                }
            }
        }*/


    public:
        Position p1, p2, p3, p4;

        tetramino(int colour) {
            this->colour = colour;
            rot_id = 1;

            switch (colour){
            
            case 1:     // Z : Red(1)
                        //  [][]
                        //    [][]

                p1.x = 5; //posizione blocco 1
                p1.y = 1;

                p2.x = 6; //posizione blocco 2
                p2.y = 1;

                p3.x = 6; //posizione blocco 3
                p3.y = 2;

                p4.x = 7; //posizione blocco 4
                p4.y = 2;
                break;

             case 2:    // S : Green(2)
                        //    [][]
                        //  [][]

                p1.x = 6; //posizione blocco 1
                p1.y = 1;

                p2.x = 7; //posizione blocco 2
                p2.y = 1;

                p3.x = 5; //posizione blocco 3
                p3.y = 2;

                p4.x = 6; //posizione blocco 4
                p4.y = 2;
                break;

            case 3:     // O : Yellow(3)
                        //  [][]
                        //  [][]             
                
                p1.x = 5; //posizione blocco 1
                p1.y = 1;

                p2.x = 6; //posizione blocco 2
                p2.y = 1;

                p3.x = 5; //posizione blocco 3
                p3.y = 2;

                p4.x = 6; //posizione blocco 4
                p4.y = 2;
                break;

            case 4:     // J : Blue(4)
                        //  []
                        //  [][][]

                p1.x = 5; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 2;

                p3.x = 6; //posizione blocco 3
                p3.y = 2;

                p4.x = 7; //posizione blocco 4
                p4.y = 2;
                break;

            case 5:     // T : Magenta(5)
                        //    []
                        //  [][][]

                p1.x = 6; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 2;

                p3.x = 6; //posizione blocco 3
                p3.y = 2;

                p4.x = 7; //posizione blocco 4
                p4.y = 2;
                break;

            case 6:     // I : Cyan(6)
                        //  [][][][]

                p1.x = 4; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 1;

                p3.x = 6; //posizione blocco 3
                p3.y = 1;

                p4.x = 7; //posizione blocco 4
                p4.y = 1;
                break;

            case 7:     // L : Orange(7) {DA CREARE SU NCURSES}
                        //      []
                        //  [][][]

                p1.x = 7; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 2;

                p3.x = 6; //posizione blocco 3
                p3.y = 2;

                p4.x = 7; //posizione blocco 4
                p4.y = 2;
                break;
            
            default:
                break;
            }
        }

        /*void print_matrix(){
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if(data[i][j] == 1){
                        cout<<"[]";
                    }
                    else cout<<"  ";
                }
                cout<<endl;
            }
        }*/

        int get_colour(){
            return colour;
        }

        void print_colour(){
            switch (colour)
            {
            case 1:
                cout<<"Red (ID: 1)";
                break;

            case 2:
                cout<<"Green (ID: 2)";
                break;
            
            case 3:
                cout<<"Yellow (ID: 3)";
                break;

            case 4:
                cout<<"Blue (ID: 4)";
                break;

            case 5:
                cout<<"Magenta (ID: 5)";
                break;

            case 6:
                cout<<"Cyan (ID: 6)";
                break;

            case 7:
                cout<<"Orange (ID: 7)";
                break;
            
            default:
                cout<<"Undefined (ID: ?)";
                break;
            }
        }
        /*Codice di tankest2015*/

        bool control_rot(char C){       // l: for left
            Position P1, P2, P3, P4;    // r: for right
            //Blocks position relative to p2
            P1 = p2;
            P2 = p2;
            P3 = p2;
            P4 = p2;
            

            if(C == 'r'){
                switch (colour){
                case 1:                 //Tetramino: Z
                    if(rot_id == 1){
                        P1.y --;
                        P3.x --;
                        P4.y ++;
                        P4.x --;
                        rot_id = 2;
                    } else if(rot_id == 2){
                        P1.x --;
                        P3.y ++;
                        P4.x ++;
                        P4.y ++;
                        rot_id = 1;
                    }
                    break;

                case 2:                 //Tetramino: S
                    if(rot_id == 1){
                        P1.y --;
                        P3.x ++;
                        P4.y ++;
                        P4.x ++;
                        rot_id = 2;
                    } else if(rot_id == 2){
                        P1.x --;
                        P3.y --;
                        P4.x ++;
                        P4.y --;
                        rot_id = 1;
                    }
                    break;

                case 3:                 //Tetramino: O
                //Do nothing
                    break;

                case 4:                 //Tetramino: J
                    if(rot_id == 1){
                        P1.x ++;
                        P3.y --;
                        P4.y = P4.y - 2;
                        rot_id = 2;
                    } else if(rot_id == 2){
                        P1.y ++;
                        P3.x --;
                        P4.x = P4.x - 2;
                        rot_id = 3;
                    } else if(rot_id == 3){
                        P1.x --;
                        P3.y --;
                        P4.y = P4.y - 2;
                        rot_id = 4;
                    } else if(rot_id == 4){
                        P1.y --;
                        P3.x ++;
                        P4.x = P4.x + 2;
                        rot_id = 1;
                    }
                    break;

                case 5:                 //Tetramino: T
                    if(rot_id == 1){
                        P1.y --;
                        P3.x ++;
                        P4.y ++;
                        rot_id = 2;
                    } else if(rot_id == 2){
                        P1.x ++;
                        P3.y ++;
                        P4.y --;
                        rot_id = 3;
                    } else if(rot_id == 3){
                        P1.y ++;
                        P3.x --;
                        P4.y --;
                        rot_id = 4;
                    } else if(rot_id == 4){
                        P1.x --;
                        P3.y --;
                        P4.x ++;
                        rot_id = 1;
                    }
                    break;
                case 6:                 //Tetramino: I
                if(rot_id == 1){
                        P1.x ++;
                        P3.x --;
                        P4.x = P4.x - 2;
                        rot_id = 2;
                    } else if(rot_id == 2){
                        P1.y --;
                        P3.y ++;
                        P4.y = P4.y + 2;
                        rot_id = 1;
                    }
                    break;

                case 7:                 //Tetramino: L
                    if(rot_id == 1){
                        P1.x ++;
                        P3.y --;
                        P4.y = P4.y - 2;
                        rot_id = 2;
                    } else if(rot_id == 2){
                        P1.y ++;
                        P3.x ++;
                        P4.x = P4.x + 2;
                        rot_id = 3;
                    } else if(rot_id == 3){
                        P1.x --;
                        P3.y ++;
                        P4.y = P4.y + 2;
                        rot_id = 4;
                    } else if(rot_id == 4){
                        P1.y --;
                        P3.x --;
                        P4.x = P4.x - 2;
                        rot_id = 1;
                    }
                    break;
                
                default:

                    break;
                }
            }
            else if(C == 'l'){
                switch (colour){
                case 1:                 //Tetramino: Z
                    break;

                case 2:                 //Tetramino: S
                    break;

                case 3:                 //Tetramino: J
                    break;

                case 4:                 //Tetramino: O
                    break;

                case 5:                 //Tetramino: T
                    break;
                case 6:                 //Tetramino: I
                    break;

                case 7:                 //Tetramino: L
                    break;
                
                default:

                    break;
                }
            }
                
            /*Control if the blocks are in the grid and can rotate without collide*/
            if(P1.x < 10 && P2.x < 10 && P3.x < 10 && P4.x < 10 && P1.x > 0 && P2.x > 0 && P3.x > 0 && P4.x > 0 && P1.x < 21 && P2.x < 21 && P3.x < 21 && P4.x < 21){
                if(Board::matrix[p1.x][p1.y] != 1 && Board::matrix[p2.x][p2.y] != 1 && Board::matrix[p3.x][p3.y] != 1 && Board::matrix[p4.x][p4.y] != 1){
                    p1 = P1;
                    p2 = P2;
                    p3 = P3;
                    p4 = P4;
                    return true;
                }
            }
            return false;
        }

        bool rot_right (){
            board_delete_assign(false);

            control_rot('r');

            board_delete_assign(true);
            
            switch (colour){
            
            case 1:
                break;

             case 2:
                break;

            case 3: 
                break;

            case 4:
                break;

            case 5:
                break;
            case 6: //Pivot -> p2
                p1 = p2;
                p3 = p2;
                p4 = p2;

                if(rot.x == -1 && rot.y == -1){
                    rot.y = +2;
                    sign = +1;
                }
                else if(rot.x == -1 && rot.y == +1){
                    rot.x = +2;
                    rot.y = +1;
                    sign = -1;
                }
                else if(rot.x == +1 && rot.y == +1){
                    rot.y = -2;
                    sign = -1;
                }
                else if(rot.x == +1 && rot.y == -1){
                    rot.x = -2;
                    rot.y = -1;
                    sign = +1;
                }

                if((rot.x > 0 && rot.y > 0) || (rot.x < 0 && rot.y < 0)){
                    p1.x = p1.x + sign;
                    p3.y = p3.x + rot.y;
                    p4.x = p4.x + rot.x;
                    rot.x = rot.y;
                }
                else{
                    p1.y = p1.y + rot.x;
                    p3.y = p3.y + sign;
                    p4.y = p4.y + rot.y;
                    rot.y = sign;
                }
                break;

            case 7:     // Pivot -> p2
                p1 = p2;
                p3 = p2;
                p4 = p2;

                if(rot.x == -1 && rot.y == -1){
                    rot.x = +1;
                    rot.y = -2;
                    sign = -1;
                }
                else if(rot.x == +1 && rot.y == -1){
                    rot.x = +2;
                    rot.y = +1;
                    sign = +1;
                }
                else if(rot.x == +1 && rot.y == +1){
                    rot.x = -1;
                    rot.y = +2;
                    sign = +1;
                }
                else if(rot.x == -1 && rot.y == +1){
                    rot.x = -2;
                    rot.y = -1;
                    sign = -1;
                }

                if(ABS(rot.x) > ABS(rot.y)){
                    p1.y = p1.y + rot.y;
                    p3.x = p3.x + sign;
                    p4.x = p3.x + rot.x;
                    rot.x = sign;
                }
                else{
                    p1.x = p1.x + rot.x;
                    p3.y = p3.y + sign;
                    p4.y = p4.y + rot.y;
                    rot.y = sign;
                }
                break;
            
            default:

                break;
            }

            return true;
        }

        bool move_right(){
            bool flag = false;
            if(p1.x == 10 || p2.x == 10 || p3.x == 10 || p4.x == 10) return false;
            board_delete_assign(false);
            if(Board::matrix[p1.x + 1][p1.y] != 1 && Board::matrix[p2.x + 1][p2.y] != 1 && Board::matrix[p3.x + 1][p3.y] != 1 && Board::matrix[p4.x + 1][p4.y] != 1)
            {
                p1.x ++;
                p2.x ++;
                p3.x ++;
                p4.x ++;
                flag = true;
            }
            board_delete_assign(true);
            return(flag);
        }

        bool move_left(){
            bool flag = false;
            if(p1.x == 1 || p2.x == 1 || p3.x == 1 || p4.x == 1) return false;
            board_delete_assign(false);
            if(Board::matrix[p1.x - 1][p1.y] != 1 && Board::matrix[p2.x - 1][p2.y] != 1 && Board::matrix[p3.x - 1][p3.y] != 1 && Board::matrix[p4.x - 1][p4.y] != 1)
            {
                p1.x --;
                p2.x --;
                p3.x --;
                p4.x --;
                flag = true;
            }
            board_delete_assign(true);
            return(flag);
        }

};
   
       
        void print_griglia() {
        //funzione che stampa in ncurses
        };

tetramino* gen_tetramino(){
    int color;
    tetramino* point;
    srand(time(0));
    color = rand()%7+1;

    point = new tetramino(color);
    return point;
}

int ABS(int x){
    if(x<0) x = x*-1;
    return x;
}

void board_delete_assign (bool action){     // For delete use false
    if(action){                             // For assign use true
        Board::matrix[p1.x][p1.y] = 1;
        Board::matrix[p2.x][p2.y] = 1;
        Board::matrix[p3.x][p3.y] = 1;
        Board::matrix[p4.x][p4.y] = 1;
    }
    else{
        Board::matrix[p1.x][p1.y] = 0;
        Board::matrix[p2.x][p2.y] = 0;
        Board::matrix[p3.x][p3.y] = 0;
        Board::matrix[p4.x][p4.y] = 0;
    }
}


/*void move_left(tetramino* point){ //SERVE LA GRIGLIA
    if(point->p1.x == 1 || point->p2.x == 1 || point->p3.x == 1 || point->p4.x == 1) return;

}

bool check_move(char c, tetramino* point)
{
    switch (c)
    {
    case 'l':
        if(point->p1.x == 1 || point->p2.x == 1 || point->p3.x == 1 || point->p4.x == 1) return false;
        break;
    
    case 'r':
        if(point->p1.x == 10 || point->p2.x == 10 || point->p3.x == 10 || point->p4.x == 10) return false;

    default:
        break;
    }  
}*/


int main() {
    tetramino *pointer;
    pointer = gen_tetramino();
    cout<<endl;
    cout<<"Color: ";
    pointer->print_colour();
    cout<<endl;

   return 0;
}

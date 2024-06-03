#include "tetramini.h"
#include "board.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


tetramino::tetramino(int colour) {
    this->colour = colour;
    rot_id = 0;

    switch (colour){
            
        case 1:     // Z : Red(1)
                    //  [][]
                    //    [][]

            p1.x = 4; //posizione blocco 1
            p1.y = 1;

            p2.x = 5; //posizione blocco 2
            p2.y = 1;

            p3.x = 5; //posizione blocco 3
            p3.y = 2;

            p4.x = 6; //posizione blocco 4
            p4.y = 2;
            break;

        case 2:    // S : Green(2)
                   //    [][]
                   //  [][]

            p1.x = 4; //posizione blocco 1
            p1.y = 2;

            p2.x = 5; //posizione blocco 2
            p2.y = 2;

            p3.x = 5; //posizione blocco 3
            p3.y = 1;

            p4.x = 6; //posizione blocco 4
            p4.y = 1;
            break;

        case 3:     // O : Yellow(3)
                    //  [][]
                    //  [][]             
            
            p1.x = 4; //posizione blocco 1
            p1.y = 1;

            p2.x = 5; //posizione blocco 2
            p2.y = 1;

            p3.x = 4; //posizione blocco 3
            p3.y = 2;

            p4.x = 5; //posizione blocco 4
            p4.y = 2;
            break;

        case 4:     // J : Blue(4)
                    //  []
                    //  [][][]

            p1.x = 4; //posizione blocco 1
            p1.y = 1;

            p2.x = 4; //posizione blocco 2
            p2.y = 2;

            p3.x = 5; //posizione blocco 3
            p3.y = 2;

            p4.x = 6; //posizione blocco 4
            p4.y = 2;
            break;

        case 5:     // T : Magenta(5)
                    //  [][][]
                    //    []

            p1.x = 4; //posizione blocco 1
            p1.y = 1;

            p2.x = 5; //posizione blocco 2
            p2.y = 1;

            p3.x = 6; //posizione blocco 3
            p3.y = 1;

            p4.x = 5; //posizione blocco 4
            p4.y = 2;
            break;

        case 6:     // I : Cyan(6)
                    //  [][][][]

            p1.x = 3; //posizione blocco 1
            p1.y = 1;

            p2.x = 4; //posizione blocco 2
            p2.y = 1;

            p3.x = 5; //posizione blocco 3
            p3.y = 1;

            p4.x = 6; //posizione blocco 4
            p4.y = 1;
            break;

        case 7:     // L : Orange(7) {DA CREARE SU NCURSES}
                    //      []
                    //  [][][]

            p1.x = 6; //posizione blocco 1
            p1.y = 1;

            p2.x = 6; //posizione blocco 2
            p2.y = 2;

            p3.x = 5; //posizione blocco 3
            p3.y = 2;

            p4.x = 4; //posizione blocco 4
            p4.y = 2;
            break;
        
        default:
            break;
        }
}

int tetramino::get_colour(){
    return colour;
}

void tetramino::print_colour(){
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

bool tetramino::control_rot(char C, Board &griglia){       // l: for left
    Position P1, P2, P3, P4;                               // r: for right
    //Blocks position relative to p2
    P1 = p2;
    P2 = p2;
    P3 = p2;
    P4 = p2;
            

    if(C == 'r'){
        switch (colour){
        case 1:                 //Tetramino: Z
            if(rot_id == 0){
                P1.y --;
                P3.x --;
                P4.y ++;
                P4.x --;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.x --;
                P3.y ++;
                P4.x ++;
                P4.y ++;
                rot_id = 0;
            }
            break;

        case 2:                 //Tetramino: S
            if(rot_id == 0){
                P1.y --;
                P3.x ++;
                P4.y ++;
                P4.x ++;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.x --;
                P3.y --;
                P4.x ++;
                P4.y --;
                rot_id = 0;
            }
            break;

        case 3:                 //Tetramino: O
        P1 = p1;
        P3 = p3;
        P4 = p4;
            break;

        case 4:                 //Tetramino: J
            if(rot_id == 0){
                P1.x ++;
                P3.y ++;
                P4.y += 2;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.y ++;
                P3.x --;
                P4.x -= 2;
                rot_id = 2;
            } else if(rot_id == 2){
                P1.x --;
                P3.y --;
                P4.y -= 2;
                rot_id = 3;
            } else if(rot_id == 3){
                P1.y --;
                P3.x ++;
                P4.x += 2;
                rot_id = 0;
            }
            break;

        case 5:                 //Tetramino: T
            if(rot_id == 0){
                P1.y ++;
                P3.y --;
                P4.x --;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.x ++;
                P3.x --;
                P4.y --;
                rot_id = 2;
            } else if(rot_id == 2){
                P1.y ++;
                P3.y --;
                P4.x ++;
                rot_id = 3;
            } else if(rot_id == 3){
                P1.x --;
                P3.x ++;
                P4.y ++;
                rot_id = 0;
            }
            break;
        case 6:                 //Tetramino: I
        if(rot_id == 0){
                P1.x ++;
                P3.x --;
                P4.x -= 2;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.y --;
                P3.y ++;
                P4.y += 2;
                rot_id = 0;
            }
            break;

        case 7:                 //Tetramino: L
            if(rot_id == 0){
                P1.x ++;
                P3.y --;
                P4.y -= 2;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.y ++;
                P3.x ++;
                P4.x += 2;
                rot_id = 2;
            } else if(rot_id == 2){
                P1.x --;
                P3.y ++;
                P4.y += 2;
                rot_id = 3;
            } else if(rot_id == 3){
                P1.y --;
                P3.x --;
                P4.x -= 2;
                rot_id = 0;
            }
            break;
        
        default:

            break;
        }
    }
    else if(C == 'l'){
        switch (colour){
        case 1:                 //Tetramino: Z
            if(rot_id == 0){
                P1.y --;
                P3.x --;
                P4.y ++;
                P4.x --;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.x --;
                P3.y ++;
                P4.x ++;
                P4.y ++;
                rot_id = 0;
            }
            break;

        case 2:                 //Tetramino: S
            if(rot_id == 0){
                P1.y --;
                P3.x ++;
                P4.y ++;
                P4.x ++;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.x --;
                P3.y --;
                P4.x ++;
                P4.y --;
                rot_id = 0;
            }
            break;

        case 3:                 //Tetramino: O
            P1 = p1;
            P3 = p3;
            P4 = p4;
            break;

        case 4:                 //Tetramino: J
            if(rot_id == 0) {		    //			              [p4]
                P1.x--;			        //[p1]			      	  [p3]
                P3.y--;			        //[p2][p3][p4]   ->   [p1][p2]
                P4.y-=2;
                rot_id = 3;
            }
            else if(rot_id == 1) {		//[p2][p1]
                P1.y--;			        //[p3]		      [p1]
                P3.x++;		            //[p4]		 ->   [p2][p3][p4]
                P4.x+=2;
                rot_id = 0;
            }
            else if(rot_id == 2) {		//[p4][p3][p2]	      [p2][p1]
                P1.x++;			        //        [p1]   ->   [p3]
                P3.y++;		            //		              [p4]
                P4.y+=2;
                rot_id = 1;
            }
            else if(rot_id == 3) {		//    [p4]
                P1.y++;			        //    [p3]	        [p4][p3][p2]
                P3.x--;			        //[p1][p2]       ->         [p1]
                P4.x-=2;
                rot_id = 2;
            }
            break;

        case 5:                 //Tetramino: T
            if(rot_id == 0) {
                P1.y++;                 //                  [p3]
                P3.y--;                 //[p1][p2][p3]  ->  [p2][p4]
                P4.x++;                 //    [p4]          [p1]
                rot_id = 3;
            }
            else if(rot_id == 1) {
                P1.x--;                 //    [p1]
                P3.x++;                 //[p4][p2]      ->  [p1][p2][p3]
                P4.y++;                 //    [p3]              [p4]
                rot_id = 0;
            }
            else if(rot_id == 2) {
                P1.y--;                 //    [p4]            [p1]
                P3.y++;                 //[p3][p2][p1]  ->[p4][p2]
                P4.x--;                 //                    [p3]
                rot_id = 1;
            }
            else if(rot_id == 3) {
                P1.x++;                 //[p3]                 [p4]
                P3.x--;                 //[p2][p4]      -> [p3][p2][p1]
                P4.y--;                 //[p1]
                rot_id = 2;
            }
            break;

        case 6:                 //Tetramino: I
            if(rot_id == 0){
                P1.x ++;
                P3.x --;
                P4.x -= 2;
                rot_id = 1;
            } else if(rot_id == 1){
                P1.y --;
                P3.y ++;
                P4.y += 2;
                rot_id = 0;
            }
            break;

        case 7:                 //Tetramino: L
            if(rot_id == 0) {           //        [p1]
                P1.x--;                 //[p4][p3][p2]   ->   [p1][p2]
                P3.y++;                 //                        [p3]
                P4.y+=2;                //                        [p4]
                rot_id = 3;
            }
            else if(rot_id == 1) {
                P1.y--;                 //[p4]                      [p1]
                P3.x--;                 //[p3]          ->  [p4][p3][p2]
                P4.x-=2;                //[p2][p1]
                rot_id = 0;
            }
            else if(rot_id == 2) {           //                  [p4]
                P1.x++;                 //                  [p3]
                P3.y--;                 //[p2][p3][p4]  ->  [p2][p1]
                P4.y-=2;                //[p1]
                rot_id = 1;
            }
            else if(rot_id == 3) {
                P1.y++;                 //[p1][p2]      ->  [p2][p3][p4]
                P3.x++;                 //    [p3]          [p1]
                P4.x+=2;                //    [p4]
                rot_id = 2;
            }
            break;
        
        default:
            break;
        }
    }
    
    /*Control if the blocks are in the grid and can rotate without collide*/
    if(P1.x < 10 && P2.x < 10 && P3.x < 10 && P4.x < 10 && P1.x >= 0 && P2.x >= 0 && P3.x >= 0 && P4.x >= 0 && P1.y < 20 && P2.y < 20 && P3.y < 20 && P4.y < 20 && 
       griglia.matrix[p1.x][p1.y] != 1 && griglia.matrix[p2.x][p2.y] != 1 && griglia.matrix[p3.x][p3.y] != 1 && griglia.matrix[p4.x][p4.y] != 1){
            p1 = P1;
            p2 = P2;
            p3 = P3;
            p4 = P4;
            return true;
    }
    else{
        if(C == 'r'){
            if (rot_id == 0 && (colour == 1 || colour == 2 || colour == 6)) rot_id = 1;
            else if(rot_id == 0) rot_id = 3;
            else rot_id --;
        }else if(C == 'l'){
            if(rot_id == 3) rot_id = 0;
            else if(rot_id == 1 && (colour == 1 || colour == 2 || colour == 6)) rot_id = 0;
            else rot_id ++;
        }
    }
    return false;
}

void tetramino::left_rotation(Board &griglia) {		//ogni volta che si genera un tetramino si impone rot_id == 0
    board_delete_assign(false, griglia);

    control_rot('l', griglia);

    board_delete_assign(true, griglia);
}

void tetramino::right_rotation(Board &griglia){
    board_delete_assign(false, griglia);

    control_rot('r', griglia);

    board_delete_assign(true, griglia);
}

bool tetramino::move_right(Board &griglia){
    bool flag = false;
    if(p1.x == 9 || p2.x == 9 || p3.x == 9 || p4.x == 9) return false;
    board_delete_assign(false, griglia);
    if(griglia.matrix[p1.x + 1][p1.y] != 1 && griglia.matrix[p2.x + 1][p2.y] != 1 && griglia.matrix[p3.x + 1][p3.y] != 1 && griglia.matrix[p4.x + 1][p4.y] != 1)
    {
        p1.x ++;
        p2.x ++;
        p3.x ++;
        p4.x ++;
        flag = true;
    }
    board_delete_assign(true, griglia);
    return(flag);
}

bool tetramino::move_left(Board &griglia){
    bool flag = false;
    if(p1.x == 0 || p2.x == 0 || p3.x == 0 || p4.x == 0) return false;
    board_delete_assign(false, griglia);
    if(griglia.matrix[p1.x - 1][p1.y] != 1 && griglia.matrix[p2.x - 1][p2.y] != 1 && griglia.matrix[p3.x - 1][p3.y] != 1 && griglia.matrix[p4.x - 1][p4.y] != 1)
    {
        p1.x --;
        p2.x --;
        p3.x --;
        p4.x --;
        flag = true;
    }
    board_delete_assign(true, griglia);
    return(flag);
}

tetramino* gen_tetramino(){
    int color;
    tetramino* point;
    srand(time(0));
    color = rand()%7+1;

    point = new tetramino(color);
    return point;
}

void tetramino::board_delete_assign (bool action, Board &griglia){     // For delete use false
    if(action){                                                        // For assign use true
        griglia.matrix[p1.y][p1.x] = 1;
        griglia.matrix[p2.y][p2.x] = 1;
        griglia.matrix[p3.y][p3.x] = 1;
        griglia.matrix[p4.y][p4.x] = 1;
    }
    else{
        griglia.matrix[p1.y][p1.x] = 0;
        griglia.matrix[p2.y][p2.x] = 0;
        griglia.matrix[p3.y][p3.x] = 0;
        griglia.matrix[p4.y][p4.x] = 0;
    }
}
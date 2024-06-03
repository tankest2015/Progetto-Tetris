#include "tetramini.h"
#include "board.h"
#include <iostream>

using namespace std;

int main(){
    tetramino *pointer;
    pointer = gen_tetramino();
    Board griglia(0);
    pointer->board_delete_assign(true, griglia);
    griglia.print_matrix();
    cout<<endl;
    pointer->print_colour();
    cout << endl;

    char c;
    do{
    
        cin >> c;
        switch (c)
        {
        case 'a':
            pointer->move_left(griglia);
            break;
        
        case 'd':
            pointer->move_right(griglia);
            break;
        
        case 'k':
            pointer->left_rotation(griglia);
            break;

        case 'l':
            pointer->right_rotation(griglia);
            break;

        default:
            break;
        }
        griglia.print_matrix();
        cout<<endl;
    } while (c != 'q');
    return 0;
}
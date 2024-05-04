#include <iostream>
#include <ctime>
#include <cstdlib>

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
        int data[rows][cols];
        Position p1, p2, p3, p4;
   
        void set_matrix() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    data[i][j] = 0;
                }
            }
        }


    public:
        tetramino(int colour) {
            this->colour = colour;
            set_matrix();

            switch (colour){
            
            case 1:                         // Z : Red(1)
                data[1][1] = 1;             //  [][]
                data[1][2] = 1;             //    [][]
                data[2][2] = 1;
                data[2][3] = 1;

                p1.x = 5; //posizione blocco 1
                p1.y = 1;

                p2.x = 6; //posizione blocco 2
                p2.y = 1;

                p3.x = 6; //posizione blocco 3
                p3.y = 2;

                p4.x = 7; //posizione blocco 4
                p4.y = 2;
                break;

             case 2:                        // S : Green(2)
                data[1][2] = 1;             //    [][]
                data[1][3] = 1;             //  [][]
                data[2][1] = 1;
                data[2][2] = 1;

                p1.x = 6; //posizione blocco 1
                p1.y = 1;

                p2.x = 7; //posizione blocco 2
                p2.y = 1;

                p3.x = 5; //posizione blocco 3
                p3.y = 2;

                p4.x = 6; //posizione blocco 4
                p4.y = 2;
                break;

            case 3:                         // O : Yellow(3)
                data[1][1] = 1;             //  [][]
                data[1][2] = 1;             //  [][]
                data[2][1] = 1;
                data[2][2] = 1;             
                
                p1.x = 5; //posizione blocco 1
                p1.y = 1;

                p2.x = 6; //posizione blocco 2
                p2.y = 1;

                p3.x = 5; //posizione blocco 3
                p3.y = 2;

                p4.x = 6; //posizione blocco 4
                p4.y = 2;
                break;

            case 4:                         // J : Blue(4)
                data[1][1] = 1;             //  []
                data[2][1] = 1;             //  [][][]
                data[2][2] = 1;
                data[2][3] = 1;

                p1.x = 4; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 1;

                p3.x = 6; //posizione blocco 3
                p3.y = 1;

                p4.x = 7; //posizione blocco 4
                p4.y = 1;
                break;

            case 5:                         // T : Magenta(5)
                data[1][2] = 1;             //    []
                data[2][1] = 1;             //  [][][]
                data[2][2] = 1;
                data[2][3] = 1;

                p1.x = 6; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 2;

                p3.x = 6; //posizione blocco 3
                p3.y = 2;

                p4.x = 7; //posizione blocco 4
                p4.y = 2;
                break;

            case 6:                         // I : Cyan(6)
                data[1][0] = 1;             //  [][][][]
                data[1][1] = 1;
                data[1][2] = 1;
                data[1][3] = 1;

                p1.x = 4; //posizione blocco 1
                p1.y = 1;

                p2.x = 5; //posizione blocco 2
                p2.y = 1;

                p3.x = 6; //posizione blocco 3
                p3.y = 1;

                p4.x = 7; //posizione blocco 4
                p4.y = 1;
                break;

            case 7:                         // L : Orange(7) {DA CREARE SU NCURSES}
                data[1][3] = 1;             //  []
                data[2][1] = 1;             //  [][][]
                data[2][2] = 1;
                data[2][3] = 1;

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

        void print_matrix(){
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if(data[i][j] == 1){
                        cout<<"[]";
                    }
                    else cout<<"  ";
                }
                cout<<endl;
            }
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
};
   
    /*BArray get_matrix() {
        return matrix;
    };
       
        int get_colour_id() {
        return colour;
        };*/

       
        /*void print_tetramino(BArray matrix, griglia Griglia) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    griglia[i][j+8] = matrix.data[i][j];
                }
            }
        };*/
       
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


int main() {
    tetramino *pointer;
    pointer = gen_tetramino();

    pointer->print_matrix();
    cout<<endl;
    cout<<"Color: ";
    pointer->print_colour();
    cout<<endl;

   return 0;
}
#include <iostream>
using namespace std;
#define rows 4
#define cols 4

struct BArray {
    int data[rows][cols];
};

struct Position {
    int x;
    int y;
};


class tetramino {
    protected:
        int colour;
        BArray matrix;
        Position p1, p2, p3, p4;
   
        void set_matrix() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    matrix.data[i][j] = 0;
                }
            }
        }

    public:
        tetramino(int colour) {
            set_matrix();
            this->colour = colour;
        };
   
        BArray get_matrix() {
        return matrix;
        };
   
        void set_matrix_cell(int row, int col) {
        matrix.data[row][col] = 1;
        };
       
        int get_colour_id() {
        return colour;
        };

       
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
};

class tetramino_O: public tetramino{ //[][]
    private:                         //[][]    O yellow: 3
   
    public:
    tetramino_O(int colour = 3):tetramino(colour) {
        set_matrix_cell(1,1);
        set_matrix_cell(1,2);
        set_matrix_cell(2,1);
        set_matrix_cell(2,2);
        p1.x = 5; //posizione blocco 1
        p1.y = 1;

        p2.x = 6; //posizone blocco2
        p2.y = 1;

        p3.x = 5; //posizone blocco3
        p3.y = 2;

        p4.x = 6; //posizone blocco4
        p4.y = 2;

    }

};

class tetramino_I: public tetramino{ //[][][][]  I cyan: 6
    private:
   
    public:
    tetramino_I(int colour = 6):tetramino(colour) {
        set_matrix_cell(1,0);            set_matrix_cell(1,1);
        set_matrix_cell(1,2);
        set_matrix_cell(1,3);

        p1.x = 4; //posizione blocco 1
        p1.y = 1;

        p2.x = 5; //posizone blocco2
        p2.y = 1;

        p3.x = 6; //posizone blocco3
        p3.y = 1;

        p4.x = 7; //posizone blocco4
        p4.y = 1;
    }
};

class tetramino_J: public tetramino{ //[]
    private:                         //[][][]    J blue: 4
   
    public:
    tetramino_J(int colour = 4):tetramino(colour) {
        set_matrix_cell(1,1);
        set_matrix_cell(2,1);
        set_matrix_cell(2,2);
        set_matrix_cell(2,3);

        p1.x = 5; //posizione blocco 1
        p1.y = 1;

        p2.x = 5; //posizone blocco2
        p2.y = 2;

        p3.x = 6; //posizone blocco3
        p3.y = 2;

        p4.x = 7; //posizone blocco4
        p4.y = 2;
    }
};

class tetramino_L: public tetramino{ //    []
    private:                         //[][][]    L orange: --
   
    public:
    tetramino_L(int colour = 0):tetramino(colour) {
        set_matrix_cell(1,3);
        set_matrix_cell(2,1);            
        set_matrix_cell(2,2);
        set_matrix_cell(2,3);

        p1.x = 7; //posizione blocco 1
        p1.y = 1;

        p2.x = 5; //posizone blocco2
        p2.y = 2;

        p3.x = 6; //posizone blocco3
        p3.y = 2;

        p4.x = 7; //posizone blocco4
        p4.y = 2;
    }
};

class tetramino_S: public tetramino{ //  [][]
    private:                         //[][]      S green: 2
   
    public:
    tetramino_S(int colour = 2):tetramino(colour) {
        set_matrix_cell(1,2);            
        set_matrix_cell(1,3);
        set_matrix_cell(2,1);
        set_matrix_cell(2,2);

        p1.x = 6; //posizione blocco 1
        p1.y = 1;

        p2.x = 7; //posizone blocco2
        p2.y = 1;

        p3.x = 5; //posizone blocco3
        p3.y = 2;

        p4.x = 6; //posizone blocco4
        p4.y = 2;
    }
};

class tetramino_Z: public tetramino{ //[][]
    private:                         //  [][]    Z red: 1
   
    public:
    tetramino_Z(int colour = 1):tetramino(colour) {
        set_matrix_cell(1,1);            
        set_matrix_cell(1,2);
        set_matrix_cell(2,2);
        set_matrix_cell(2,3);

        p1.x = 5; //posizione blocco 1
        p1.y = 1;

        p2.x = 6; //posizone blocco2
        p2.y = 1;

        p3.x = 6; //posizone blocco3
        p3.y = 2;

        p4.x = 7; //posizone blocco4
        p4.y = 2;
    }
};

class tetramino_T: public tetramino{ //  []
    private:                         //[][][]    T magenta: 5
   
    public:
    tetramino_T(int colour = 5):tetramino(colour) {
        set_matrix_cell(1,2);
        set_matrix_cell(2,1);
        set_matrix_cell(2,2);
        set_matrix_cell(2,3);

        p1.x = 6; //posizione blocco 1
        p1.y = 1;

        p2.x = 5; //posizone blocco2
        p2.y = 2;

        p3.x = 6; //posizone blocco3
        p3.y = 2;

        p4.x = 7; //posizone blocco4
        p4.y = 2;
    }
};

int main() {
    tetramino_O O;
    BArray matrix = O.get_matrix();
   
    cout << "Printing tetramino: O" << endl;
    cout << "Colour ID: " << O.get_colour_id() << endl;
    cout << "Colour name: yellow" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    tetramino_I I;
    matrix = I.get_matrix();
   
    cout << "Printing tetramino: I" << endl;
    cout << "Colour ID: " << I.get_colour_id() << endl;
    cout << "Colour name: cyan" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    tetramino_J J;
    matrix = J.get_matrix();
   
    cout << "Printing tetramino: J" << endl;
    cout << "Colour ID: " << J.get_colour_id() << endl;
    cout << "Colour name: blue" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    tetramino_L L;
    matrix = L.get_matrix();
   
    cout << "Printing tetramino: L" << endl;
    cout << "Colour ID: " << L.get_colour_id() << endl;
    cout << "Colour name: orange" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    tetramino_S S;
    matrix = S.get_matrix();
   
    cout << "Printing tetramino: S" << endl;
    cout << "Colour ID: " << S.get_colour_id() << endl;
    cout << "Colour name: green" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    tetramino_Z Z;
    matrix = Z.get_matrix();
   
    cout << "Printing tetramino: Z" << endl;
    cout << "Colour ID: " << Z.get_colour_id() << endl;
    cout << "Colour name: red" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
    tetramino_T T;
    matrix = T.get_matrix();
   
    cout << "Printing tetramino: T" << endl;
    cout << "Colour ID: " << T.get_colour_id() << endl;
    cout << "Colour name: magenta" << endl;
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix.data[i][j] << " ";
        }
        cout << endl;
    }
   
   return 0;
}
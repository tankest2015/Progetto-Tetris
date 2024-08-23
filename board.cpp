#include "board.h"
#include "tetramini.h"
#include "style_game.h"
#include <iostream>
using namespace std;

Board::Board(int score){
    this->score = score;
    init_matrix();
}

void Board::init_matrix(){
    for(int i=0; i<col_size; i++){
        for(int j=0; j<row_size; j++){
            matrix[i][j] = 0;
        }
    }
}

void Board::print_matrix(){
    for(int i=0; i<col_size; i++){
        for(int j=0; j<row_size; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout<<endl;
}

bool Board::is_full(int row) {
    int i = 0;
    bool flag = true;
    while(i < row_size && flag) {
        if(matrix[row][i] == 0) flag = false;
        i++;
    }
    return flag;
} 

void Board::move_row_down(int row, int n_rows){ //n_rows: numero di spostamenti verso il basso da effettuare
    for(int i=0; i < row_size; i++){
        matrix[row+n_rows][i] = matrix[row][i];
        matrix[row][i] = 0; 
    }
}

bool Board::is_empty(int row) {
    int i = 0;
    bool flag = true;
    while(i < row_size && flag) {
        if(matrix[row][i] != 0) flag = false;
        i++;
    }
    return flag;
}

void Board::clear_row(int row){
    for(int i=0; i < row_size; i++){
        matrix[row][i] = 0;
    }
}

int max_y(tetramino* point) { //blocco più basso del tetramino, quindi il valore y più alto
    if(point->p1.y >= point->p2.y && point->p1.y >= point->p3.y && point->p1.y >= point->p4.y) return point->p1.y;
    else if(point->p2.y >= point->p1.y && point->p2.y >= point->p3.y && point->p2.y >= point->p4.y) return point->p2.y;
    else if(point->p3.y >= point->p1.y && point->p3.y >= point->p2.y && point->p3.y >= point->p4.y) return point->p3.y;
    else return point->p4.y;
}


void clear_full_rows(tetramino* point, Board &griglia, WINDOW* win) {
    int row_pos = max_y(point);
    int counter = 0;
    while(!griglia.is_empty(row_pos)) {
        if(griglia.is_full(row_pos)) {
            flicker_row(win, griglia, row_pos);
            griglia.clear_row(row_pos);
            counter++;
        }
        else if(counter > 0) {
            griglia.move_row_down(row_pos, counter);
        }
        row_pos--;
    }
    update_score(counter, griglia);
}

bool is_game_over(tetramino* point, Board &griglia) {
    point->board_delete_assign(false, griglia, point->get_colour());
    if(griglia.matrix[1][5] != 0 || griglia.matrix[2][5] != 0) return true;
    point->board_delete_assign(true, griglia, point->get_colour());
    return false;
}

void update_score(int l_cleared, Board &griglia){
    if(l_cleared == 1){
        griglia.score += 150;
    } else if (l_cleared == 2){
        griglia.score += 200;
    } else if(l_cleared == 3){
        griglia.score += 400;
    } else if(l_cleared == 4){
        griglia.score += 600;
    }
}

int Board::get_row_col_size(bool flag) {        //true per restituire row_size, false per col_size
    if(flag){
        return row_size;
    }
    else {
         return col_size;
    }
}

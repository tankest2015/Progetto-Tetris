#include "board.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

Board::Board(){
    init_matrix();
    print_matrix();
}

void Board::init_matrix(){
    for(int i=0; i<row_size; i++){
        for(int j=0; j<col_size; j++){
            matrix[i][j] = 0;
        }
    }
}

void Board::print_matrix(){
    for(int i=0; i<row_size; i++){
        for(int j=0; j<col_size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*bool Board::is_full(int row){
    for(int i=0; i<col_size; i++){
        if(matrix[row][i] == 0) return false;
    }
    return true;
}*/

bool Board::is_full(int row) {
    int i = 0;
    bool flag = true;
    while(matrix[row][i] < col_size && flag) {
        if(matrix[row][i] == 0) flag = false;
        i++;
    }
    return flag;
} 

void Board::move_down(int row, int n_rows){ //n_rows: numero di spostamenti verso il basso da effettuare
    for(int i=0; i<col_size; i++){          //Propoosta nome funzione: move_row_down
        matrix[row+n_rows][i] = matrix[row][i];
        matrix[row][i] = 0; 
    }
}

bool Board::is_empty(int row) {
    int i = 0;
    bool flag = true;
    while(matrix[row][i] < col_size && flag) {
        if(matrix[row][i] != 0) flag = false;
        i++;
    }
    return flag;
}

void Board::clear_row(int row){
    for(int i=0; i<col_size; i++){
        matrix[row][i] = 0;
    }
}

void Board::clear_full_rows(tetramino* point) {
    int row_pos = max_y(point);
    int counter = 0;
    while(!is_empty(row_pos)) {
        if(is_full(row_pos)) {
            clear_row(row_pos);
            counter++;
        }
        else if(counter > 0) {
            move_down(row_pos-1, counter);
            row_pos--;
        }
        row_pos--;
    }
} 

int Board::max_y(tetramino* point) { //y più bassa del tetramino
    if(point->p1.y >= point->p2.y && point->p1.y >= point->p3.y && point->p1.y >= point->p4.y) return point->p1.y;
    else if(point->p2.y >= point->p1.y && point->p2.y >= point->p3.y && point->p2.y >= point->p4.y) return point->p2.y;
    else if(point->p3.y >= point->p1.y && point->p3.y >= point->p2.y && point->p3.y >= point->p4.y) return point->p3.y;
    else if(point->p4.y >= point->p1.y && point->p4.y >= point->p2.y && point->p4.y >= point->p3.y) return point->p4.y;
}


bool Board::is_game_over() {
    if(matrix[5][1] != 0 || matrix[5][2] != 0) return true;
    return false;
}

void Board::update_score(int l_cleared, int m_points){
    if(l_cleared == 1){
        score += 100;
    } else if (l_cleared == 2){
        score += 300;
    } else if(l_cleared == 3){
        score += 500;
    } else {
        score += m_points;
    }
}
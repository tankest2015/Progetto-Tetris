#ifndef WRITE_LEAD_H
#define WRITE_LEAD_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>


using namespace std;

void insert_line(fstream &newFile, int pos_prec, char pc[], char Nm[], char Tim[], char copy[], char B[]);
void write(char h[], char min[], char s[], char point[], char name[], char line[]);
void del_ch(WINDOW* player, char text[], int i);
bool check(char text[]);
void insert(int p, int h, int min, int s);

#endif
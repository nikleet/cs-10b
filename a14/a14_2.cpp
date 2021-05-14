/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 5/14/2021
    Instructor: Dave Harden
    File: "a14_2.cpp"
    Assignment 14, Part 2

    This program implements Conway's Game of Life using the BoolMatrix class!
    Data for the initial state of the game must be placed in the working
    directory in a file titled "life.txt" [in accordance with the precondition
    of initialize()].
*/

#include "boolMatrix.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
using namespace cs_boolmatrix;

void initialize(BoolMatrix& matrix, ifstream& in);
bool checkLiving(const BoolMatrix& matrix, int row, int col);
void iterate(BoolMatrix& matrix);
void play(BoolMatrix& matrix, int generations);


int main() {
    BoolMatrix game;
    ifstream data("life.txt");
    initialize(game, data);
    int generations;
    cout << "Enter the number of generations: ";
    cin >> generations;
    play(game, generations);

}





/*
    Reads data from an ifstream into the BoolMatrix parameter matrix.
    
    pre: The data in the ifstream is a text file with data formatted with an
    integer for the row, followed by a tab, and an integer
    for the column that represent the coordinates each living cell. Each
    coordinate pair is seperated by a newline.

    post: Each value in BoolMatrix matrix specified at the coordinates in
    ifstream in has been set to true.
*/ 
void initialize(BoolMatrix& matrix, ifstream& in) {
    if(in.is_open()) {
        int row;
        int col;
        int out;
        while(!in.eof()) {
            in >> row;
            in >> col;
            matrix.set(row, col, true);
        }
        in.close();
    }
    else {
        cout << "DATA FILE FAILED TO OPEN." << endl;
    }
}





/*
    Sequentially prints a number of generations, specified by the parameter
    generations, of Conway's Game of Life with the seed/"Generation 0" state in
    the parameter BoolMatrix matrix. 

    post: A number of generations (int generations) of Conway's Game of Life
    have been printed to the console.  
*/
void play(BoolMatrix& matrix, int generations) {
    cout << "\noriginal grid:" << endl;
    matrix.print();
    for(int i = 1; i <= generations; i++) {
        iterate(matrix);
        cout << "\nThe grid after " << i << " generations have passed:" 
             << endl;
        matrix.print();
    }
}





/*
    Updates the values in the BoolMatrix matrix in accordance with the rules of
    Conway's Game of Life to iterate the grid to the next generation.

    post: The BoolMatrix matrix has been iterated to the next generation. 
*/
void iterate(BoolMatrix& matrix) {
    BoolMatrix nextGeneration;
    for(int row = 0; row < BoolMatrix::NUM_ROWS; row++) {
        for(int col = 0; col < BoolMatrix::NUM_COLS; col++) {
            nextGeneration.set(row, col, checkLiving(matrix, row, col));
        }
    }
    matrix = nextGeneration;
}   





/*
    Checks if the value at the row and column in BoolMatrix matrix should be
    living (true) or dead (false) based on the rules of Conway's Game of Life.

    post: The status (false = dead; true = living) of the value at
    matrix[row][col] in the next generation of Conway's Game of Life has been returned.   
*/
bool checkLiving(const BoolMatrix& matrix, int row, int col) {
    const int nCount = matrix.neighborCount(row, col);
    bool status = matrix.get(row, col);
    if(status) {
        if(nCount <= 1 || nCount >= 4) {
            status = false;
        }   
    }
    else {
        if(nCount == 3) {
            status = true;
        }
    }
    return status;
}

/* 
    OUTPUT (20r x 20c Grid; 5 Generations):

    The grid after 5 generations have passed:
     01234567890123456789
    0
    1         *        *
    2       *   * ***  *
    3       *   **** *
    4      *  * *    **
    5    *  *   *****  *
    6 ** *     *    *** *
    7    * ***       *  *
    8               ****
    9 *         ******
    10* *          *
    11   *  *      **   *
    12**    ****       ***
    13  *         *** ** *
    14      *  *   *   ***
    15 **   ***      ** **
    16      *         * **
    17
    18
    19


    OUTPUT (21r x 22c Grid; 8 Generations):

    The grid after 8 generations have passed:
     0123456789012345678901
    0
    1         **     *
    2         * *   ** *
    3       **        *
    4    **** * *   **
    5    **  * ** ** *
    6   *      ***
    7    **  *  * *
    8     ***   * *
    9 **        *  * *    *
    10* **        *    *  **
    11* ** ** **  ***  *  **
    12*   *   *** **  *    *
    13* *        **
    14 *      ***     *
    15        *
    16     * *         *
    17      *         *
    18
    19
    20
*/
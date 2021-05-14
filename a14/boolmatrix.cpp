/*
    Niklas Leet

    Class invariant: A BoolMatrix object has one private member variable,
    boolArray, which is a 2D array of bool values. The default constructor will
    make all values in the grid false. BoolMatrix has public static constants
    NUM_ROWS and NUM_COLS that represent the number of rows and columns in the grid.
*/


#include "boolMatrix.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace cs_boolmatrix {
    
    // constructs a BoolMatrix object
    BoolMatrix::BoolMatrix() {
        for(int row = 0; row < NUM_ROWS; row++) {
            for(int col = 0; col < NUM_COLS; col++) {
                boolArray[row][col] = false;
            }
        }
    }





    // accesses and returns boolArray[row][col] if row and col are in bounds 
    bool BoolMatrix::get(int row, int col) const {
        assert(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
        return boolArray[row][col];
    }





    // sets boolArray[row][col] to the value of val if row and col are in bounds
    void BoolMatrix::set(int row, int col, bool val) {
        assert(row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS);
        boolArray[row][col] = val;
    }
    




    // returns the count of true values in the row at index row in boolArray 
    int BoolMatrix::rowCount(int row) const {
        assert(row >= 0 && row < NUM_ROWS);
        int count = 0;
        for(int col = 0; col < NUM_COLS; col++) {
            if(get(row, col))
                count++;
        }
        return count;
    }





    // returns the count of true values in the column at index col in boolArray
    int BoolMatrix::colCount(int col) const {
        assert(col >= 0 && col < NUM_ROWS);
        int count = 0;
        for(int row = 0; row < NUM_ROWS; row++) {
            if(get(row, col))
                count++;
        }
        return count;
    }





    // returns the count of true values in boolArray
    int BoolMatrix::totalCount() const {
        int count = 0;
        for(int row = 0; row < NUM_ROWS; row++) {
            for(int col = 0; col < NUM_COLS; col++) {
                if(get(row, col))
                    count++;
            }
        }
        return count;
    }





    // returns the count of true values visualized as adjacent and diagonal to 
    // boolArray[rowIndex][colIndex] on a grid
    int BoolMatrix::neighborCount(int rowIndex, int colIndex) const {
        assert(rowIndex >= 0 && rowIndex < NUM_ROWS 
               && colIndex >= 0 && colIndex < NUM_COLS);
        int count = 0;
        for(int row = rowIndex - 1; row <= rowIndex + 1; row++) {
            for(int col = colIndex - 1; col <= colIndex + 1; col++) {
                if(!(row == rowIndex && col == colIndex) 
                    && (row >= 0 && row < NUM_ROWS 
                       && col >= 0 && col < NUM_COLS))
                        if(get(row, col))
                            count++;
            }
        }
        return count;
    }





    // prints the values of boolArray in a grid with column indices above
    // (cycling 1-9) and row indices to the left (right aligned). True values
    // are represented by a "*" and false values by a " ".
    void BoolMatrix::print() const {
        cout << setw(log10(NUM_ROWS) + 1) << " "; 
        for(int col = 0; col < NUM_COLS; col++)
            cout << col % 10;
        for(int row = 0; row < NUM_ROWS; row++) {
            for(int col = 0; col < NUM_COLS; col++) {
                if(col == 0)
                    cout << "\n" << setw(log10(NUM_ROWS) + 1) << row;
                if(get(row, col))
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

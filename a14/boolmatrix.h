/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 5/12/2021
    Instructor: Dave Harden
    File: "boolmatrix.h"
    Assignment 14

    The BoolMatrix class represents a two dimensional grid of bool values. It
    provides mutator and accesor functions, functions for counting true cells,
    and a funciton for printing a BoolMatrix object as a grid.

    BoolMatrix provides the following functions:

    BoolMatrix();
        post: A BoolMatrix object containing an empty 2D bool array has been
        created.

    bool get(int row, int col) const;
        post: The value at the specified row and column has been returned.
    
    void set(int row, int col, bool val);
        post: The value val has been assigned to the cell at the specified row
        and column.
    
    int rowCount(int row) const;
        post: The number of true values in boolArray[row][] has been returned.

    int colCount(int col) const;
        post: The number of true values in boolArray[][col] has been returned.
    
    int totalCount() const;
        post: The total number of true values in the grid has been returned.

    int neighborCount(int row, int col) const;
        post: The number of true values neighboring boolArray[row][col]
        (diagonal and adjacent) has been returned.

    void print() const;
        post: The BoolMatrix has been printed as a grid formatted with the
        column indices along the top and the row indices along the left side.
        True values have been represented by a "*" and false values by a " ".
*/

#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

namespace cs_boolmatrix
{
    class BoolMatrix {
        public:
            static const int NUM_ROWS = 20;
            static const int NUM_COLS = 20;
            BoolMatrix();
            bool get(int row, int col) const;
            void set(int row, int col, bool val);
            int rowCount(int row) const;
            int colCount(int col) const;
            int totalCount() const;
            int neighborCount(int row, int col) const;
            void print() const;
        private:
            bool boolArray[NUM_COLS][NUM_ROWS];
    };
}

#endif
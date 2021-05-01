/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a5_2.cpp
    Peers cited: None

    Description: Sorts and displays a list of scores and a list of associated 
    names.
    
    Input: The number of scores, the name of the scorer, and the score itself
    Output: A high score list of scores and scorers sorted in descending order 
*/

#include <iostream>
#include <utility> // for swap()
using namespace std;

void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void sort(int list[], int numItems);
int indexOfBiggest(const int list[], int startingIndex, int numItems);
void displayData(const string names[], const int scores[], int size);

int main() {
    int size;
    cout << "How many scores will you enter?: ";
    cin >> size;

    string* names = new string[size];
    int* scores = new int[size];

    readData(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    delete [] names;
    delete [] scores;

    return 0;
}






/*
    Using the int size of the array, prompts the user and reads the names of 
    scorers to names[] and the scores to scores[] 
*/
void readData(string names[], int scores[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> names[i];
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i];
    }
}






/*
    Displays a high score list in descending order using data from names[],
    scores[], and the size of the arrays
*/
void displayData(const string names[], const int scores[], int size) {
    cout << "\nTop scorers:" << endl;
    for(int i = 0; i < size; i++) {
        cout << names[i] << ": " << scores[i] << endl;
    } 
}






/*
    Sorts the data in scores[] in descending order using a selection sort and
    rearranges names[] so that the name of the scorer has the same index as his
    score 
*/
void sortData(string names[], int scores[], int size) {
    for (int i = 0; i < size; i++) {
        swap(names[indexOfBiggest(scores, i, size)], names[i]);
        swap(scores[indexOfBiggest(scores, i, size)], scores[i]);
    }
}






/* 
    Finds the largest int value in list[] with size numItems, starting from 
    startingIndex
*/
int indexOfBiggest(const int list[], int startingIndex, int numItems) {
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++){
        if (list[count] > list[targetIndex]){
            targetIndex = count;
        }
    }

    return targetIndex;
}

/* OUTPUT
    C:\Users\Niklas Leet\c++\cs-10b\assignment-5>.\a5_2.exe
    How many scores will you enter?: 5
    Enter the name for score #1: a
    Enter the score for score #1: 1
    Enter the name for score #2: b
    Enter the score for score #2: 2
    Enter the name for score #3: d
    Enter the score for score #3: 4
    Enter the name for score #4: c
    Enter the score for score #4: 3
    Enter the name for score #5: e
    Enter the score for score #5: 5

    Top scorers:
    e: 5
    d: 4
    c: 3
    b: 2
    a: 1

    C:\Users\Niklas Leet\c++\cs-10b\assignment-5>.\a5_2.exe
    How many scores will you enter?: 4
    Enter the name for score #1: Suzy
    Enter the score for score #1: 600
    Enter the name for score #2: Kim 9900
    Enter the score for score #2: Enter the name for score #3: Armando
    Enter the score for score #3: 8000
    Enter the name for score #4: Tim
    Enter the score for score #4: 514

    Top scorers:
    Kim: 9900
    Armando: 8000
    Suzy: 600
    Tim: 514
*/
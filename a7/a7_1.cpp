/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a7_1.cpp
    Peers consulted: None

    Description: Sorts and displays a list of scores and a list of associated 
    names.
    
    Input: The number of scores, the name of the scorer, and the score itself
    Output: A high score list of scores and scorers sorted in descending order 
*/

#include <iostream>

using namespace std;

struct Highscore {
    int score; 
    char name[24];
};
void readData(Highscore scores[], int size);
void sortData(Highscore scores[], int size);
void sort(int list[], int numItems);
int indexOfHighest(const Highscore list[], int startingIndex, int numItems);
void displayData(const Highscore scores[], int size);

int main() {
    int size;
    cout << "How many scores will you enter?: ";
    cin >> size;

    Highscore *scores = new Highscore[size];

    readData(scores, size);
    sortData(scores, size);
    displayData(scores, size);

    return 0;
}






/*
    Using the int size of the array, prompts the user and reads the names of 
    scorers their scores to an array of Highscore structs 
*/
void readData(Highscore scores[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> scores[i].name;
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> scores[i].score;
    }
}






/*
    Displays a high score list in descending order using data from Highscore.name
    and Highscore.score in an array of Highscore structs
*/
void displayData(const Highscore scores[], int size) {
    cout << "\nTop scorers:" << endl;
    for(int i = 0; i < size; i++) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    } 
}





/*
    Sorts the elements of Highscore scores[] in descending order by each value 
    of Highscore.score using a selection sort 
*/
void sortData(Highscore scores[], int size) {
    for (int i = 0; i < size; i++) {
        swap(scores[indexOfHighest(scores, i, size)], scores[i]);
    }
}







/* 
    Finds the largest int value in an array of Highscores with size numItems,
    starting from startingIndex
*/
int indexOfHighest(const Highscore list[], int startingIndex, int numItems) {
    int targetIndex = startingIndex;

    for (int count = startingIndex + 1; count < numItems; count++){
        if (list[count].score > list[targetIndex].score){
            targetIndex = count;
        }
    }

    return targetIndex;
}

/* OUTPUT
    C:\Users\Niklas Leet\c++\cs-10b\assignment-7>.\a7_1.exe
    How many scores will you enter?: 5
    Enter the name for score #1: Niklas
    Enter the score for score #1: 4
    Enter the name for score #2: Brandt
    Enter the score for score #2: 3
    Enter the name for score #3: Ryan
    Enter the score for score #3: 6
    Enter the name for score #4: India 
    Enter the score for score #4: 10
    Enter the name for score #5: Daniel  
    Enter the score for score #5: 2

    Top scorers:
    India: 10
    Ryan: 6
    Niklas: 4
    Brandt: 3
    Daniel: 2

    C:\Users\Niklas Leet\c++\cs-10b\assignment-7>.\a7_1.exe
    How many scores will you enter?: 4
    Enter the name for score #1: Suzy
    Enter the score for score #1: 600
    Enter the name for score #2: Kim
    Enter the score for score #2: 9900
    Enter the name for score #3: Armando
    Enter the score for score #3: 8000
    Enter the name for score #4: Tim
    Enter the score for score #4: 514

    Top scorers:
    Kim: 9900
    Armando: 8000
    Suzy: 600
    Tim: 514
*/
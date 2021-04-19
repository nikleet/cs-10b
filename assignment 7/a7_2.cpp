/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a7_2.cpp
    Peers consulted: None

    Description: Counts and displays the frequency of each char in a string
    terminated in a '.'
    
    Input:  A string terminated by a '.'
    Output: A table of frequencies of each alphabetical character in the string
*/

#include <iostream>

using namespace std;

struct Frequency {
    char letter;
    int count;
};
void getData(Frequency frequencies[]);
void printData(Frequency frequecies[]);
int indexOfHighest(const Frequency list[], int startingIndex, int numItems);
void sortData(Frequency frequencies[], int size);
const int NUM_ALPHA = 'z' - 'a' + 1;

int main() {
    Frequency *frequencies = new Frequency[NUM_ALPHA];
    for(int i = 0; i < NUM_ALPHA; i++) {
        frequencies[i].letter = (char) (i + 97);
        frequencies[i].count = 0;
    }
    
    getData(frequencies);
    sortData(frequencies, NUM_ALPHA);
    printData(frequencies);

    return 0;
}





/*
    Prompts the user, retrieves a string terminated in a period, and records 
    the frequency of each character to frequencies[].
*/  
void getData(Frequency frequencies[]) {
    cout << "Please enter a sequence of characters terminated with a period ('.'): ";
    char ch;
    cin >> ch;
    while (ch != '.') {
        if(isalpha(ch)) {
            ch = tolower(ch);
            frequencies[(int) ch - 97].count++;
        }
        cin >> ch;
    }
}





/*
    Sorts frequencies[] in descending order based on frequences.count
*/
void sortData(Frequency frequencies[], int size) {
    for (int i = 0; i < size; i++) {
        swap(frequencies[indexOfHighest(frequencies, i, size)], frequencies[i]);
    }
}







/* 
    Finds the highest value of frequency.count in an array of Frequencies with
    size numItems, starting from startingIndex
*/
int indexOfHighest(const Frequency list[], int startingIndex, int numItems) {
    int targetIndex = startingIndex;

    for (int i = startingIndex + 1; i < numItems; i++){
        if (list[i].count > list[targetIndex].count){
            targetIndex = i;
        }
    }

    return targetIndex;
}





// Prints the frequency data.
void printData(Frequency frequencies[]) {
    cout << "Letter:\tNumber of Occurences\n";

    for(int i = 0; i < NUM_ALPHA; i++) {
        if(frequencies[i].count > 0) {
            cout << "\t" << frequencies[i].letter 
                << "\t" << frequencies[i].count << endl;
        }
    }
}

/* OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-7>.\a7_2.exe
    Please enter a sequence of characters terminated with a period ('.'): Music is the silence of life, brother.
    Letter: Number of Occurences
            e       5
            i       4
            s       3
            f       2
            h       2
            l       2
            o       2
            r       2
            c       2
            t       2
            m       1
            n       1
            b       1
            u       1

    C:\Users\Niklas Leet\c++\cs-10b\assignment-7>.\a7_2.exe
    Please enter a sequence of characters terminated with a period ('.'): To be, or not
    to be -
    that is the question.
    Letter: Number of Occurences
            t       7
            o       5
            e       4
            h       2
            i       2
            n       2
            b       2
            s       2
            q       1
            r       1
            a       1
            u       1

*/
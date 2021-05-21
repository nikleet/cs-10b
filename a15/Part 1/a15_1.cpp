/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 5/19/2021
    Instructor: Dave Harden
    File: "a15_1.cpp"
    Assignment 15, Part 1

    This program implements and tests two recursive functions:
    reverseWithinBounds(), which reverses the order of elements in a char array
    within the given range and reverseCstring, which reverses a c-string.
*/

#include <iostream>
#include <cstring>

using namespace std;

void reverseWithinBounds(char array[], int first, int last);
void reverseCstring(char* str);
void testArray(char arr[], int lower, int upper, int size);

int main() {

    char sample[] = {'s', 'l', 'i', 'm', 'e', 'y'};
    int size = 6;
    int lower = 0;
    int upper = 5;
    testArray(sample, lower, upper, size);
    
    reverseWithinBounds(sample, lower, upper);
    upper = 4;
    testArray(sample, lower, upper, size);

    reverseWithinBounds(sample, lower, upper);
    lower = 1;
    testArray(sample, lower, upper, size);

    reverseWithinBounds(sample, lower, upper);
    upper = 0;
    lower = 0;
    testArray(sample, lower, upper, size);

    cout << "\nTesting c-string reversal..." << endl;
    char str[] = "Reverse me, please!";
    cout << "Original: " << str << endl;
    reverseCstring(str);
    cout << "Modified: " << str << endl;

    return 0;
}






/*
    Recursively reverses the order of elements in the paramteter char arr[] in
    the range of indices from the parameters first to last.

    pre: first <= last and both are within the bounds of arr.
    
    post: The elements between first and last have been reversed. 
*/
void reverseWithinBounds(char arr[], int first, int last) {
    if(first <last) {
        swap(arr[first], arr[last]);
        reverseWithinBounds(arr, first + 1, last - 1);
    }
}






/*
    Reverses a parameter char* str c-string by calling reverseWithinBounds().

    post: str has been reversed.
*/
void reverseCstring(char* str) {
    reverseWithinBounds(str, 0, strlen(str) - 1);
}







// A test function used in the driver
void testArray(char arr[], int lower, int upper, int size) {
    cout << "Testing with bounds " << lower << " to " << upper << endl;
    cout << "Original:" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    reverseWithinBounds(arr, lower, upper);
    cout << "Modified:" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

/*  OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\a15\Part 1>.\a15_1.exe
    Testing with bounds 0 to 5
    Original:
    s
    l
    i
    m
    e
    y
    Modified:
    y
    e
    m
    i
    l
    s
    Testing with bounds 0 to 4
    Original:
    s
    l
    i
    m
    e
    y
    Modified:
    e
    m
    i
    l
    s
    y
    Testing with bounds 1 to 4
    Original:
    s
    l
    i
    m
    e
    y
    Modified:
    s
    e
    m
    i
    l
    y
    Testing with bounds 0 to 0
    Original:
    s
    l
    i
    m
    e
    y
    Modified:
    s
    l
    i
    m
    e
    y

    Testing c-string reversal...
    Original: Reverse me, please!
    Modified: !esaelp ,em esreveR
*/
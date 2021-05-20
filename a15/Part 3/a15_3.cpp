/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 5/19/2021
    Instructor: Dave Harden
    File: "a15_3.cpp"
    Assignment 15, Part 3

    This program implements and tests a recursive function that detects if a
    MyString object is a palindome.
*/

#include <iostream>
#include <random> // for driver function
#include <ctime> // for use in srand()

using namespace std;

int* ascSelectSort(int arr[], int start, int end);
int findIofSmallest(const int arr[], int start, int end);
void testSelectSort(int numItems, int min, int max, int start, int end);

int main() {

    srand(time(0));

    testSelectSort(5, 1, 5, 0, 4);
    testSelectSort(5, 1, 5, 0, 4);
    testSelectSort(5, 1, 5, 0, 4);
    testSelectSort(10, 1, 20, 0, 9);
    testSelectSort(10, 1, 20, 2, 8);
    testSelectSort(20, -50, 50, 0, 19);
    testSelectSort(20, -50, 50, 5, 15);
    testSelectSort(20, -50, 50, 0, 0);
    
    return 0;
}






/*
    Employs a recursive selection sort to sort the elements between parameters
    start and end in the parameter int arr[] in *ascending order*.

    pre: start <= end and both are within the bounds of arr.

    post: The elements between start and end have been sorted in ascending order.
*/
int* ascSelectSort(int arr[], int start, int end) {
    if(start >= end)
        return arr;
    else {
        int minI = findIofSmallest(arr, start, end);
        if(start != minI)
            swap(arr[start], arr[minI]);
        ascSelectSort(arr, start + 1, end);
    }    
}






/*
    Returns the element of the smallest value of the parameter int arr[] between
    the indices start and end.

    pre: start <= end and both are within the bounds of arr

    post: The index of the smallest value in arr between start and end has been 
    returned.  
*/
int findIofSmallest(const int arr[], int start, int end) {
    if(start >= end) {
        return end;
    }
    else {
        int nextSmallest = findIofSmallest(arr, start + 1, end);
        if(arr[nextSmallest] < arr[start])
            return nextSmallest; 
        else
            return start;
    }
}






/* 
    A function used in the driver to test selection sort. 
    Usage:
        - numItems is the number of items in the int array
        - min is the minimum possible random value to populate the array
        - max is the maximum possible random value to populate the array
        - start is the start index of the domain to be sorted
        - end is the ending index of the domain to be sorted
*/
void testSelectSort(int numItems, int min, int max, int start, int end) {
    int arr[numItems];
    for(int i = 0; i < numItems; i++) {
        arr[i] = rand() % (max + 1) + min;
    }
    cout << "Original array (range of " << min << " to " << max << "):\n\t  [";
    for(int num: arr) {
        cout << num << ", ";
    }
    cout << "\b\b]\n";
    ascSelectSort(arr, start, end);
    cout << "Array sorted from index " << start << " to " << end << ":\n\t> [";
    for(int num: arr) {
        cout << num << ", ";
    }
    cout << "\b\b]\n" << endl;
}

/*
    C:\Users\Niklas Leet\c++\cs-10b\a15\Part 3>.\a15_3.exe
    Original array (range of 1 to 5):
            [4, 5, 5, 6, 5]
    Array sorted from index 0 to 4:
            > [4, 5, 5, 5, 6]

    Original array (range of 1 to 5):
            [4, 6, 3, 2, 2] 
    Array sorted from index 0 to 4:
            > [2, 2, 3, 4, 6]

    Original array (range of 1 to 5):
            [5, 3, 1, 5, 2]
    Array sorted from index 0 to 4:
            > [1, 2, 3, 5, 5]

    Original array (range of 1 to 20):
            [3, 17, 18, 17, 14, 13, 5, 15, 16, 6] 
    Array sorted from index 0 to 9:
            > [3, 5, 6, 13, 14, 15, 16, 17, 17, 18]

    Original array (range of 1 to 20):
            [17, 9, 10, 21, 17, 8, 19, 7, 3, 13]
    Array sorted from index 2 to 8:
            > [17, 9, 3, 7, 8, 10, 17, 19, 21, 13]

    Original array (range of -50 to 50):
            [-36, -2, -7, -42, -25, -28, -14, -41, -47, -10, -28, -32, -36, -49, -4, -46, -1, -20, -20, -36] 
    Array sorted from index 0 to 19:
            > [-49, -47, -46, -42, -41, -36, -36, -36, -32, -28, -28, -25, -20, -20, -14, -10, -7, -4, -2, -1] 

    Original array (range of -50 to 50):
            [-50, -13, -18, -48, -7, -48, -15, -26, -43, -35, -46, -26, -20, -16, -27, -50, -27, -17, -24, -1] 
    Array sorted from index 5 to 15:
            > [-50, -13, -18, -48, -7, -50, -48, -46, -43, -35, -27, -26, -26, -20, -16, -15, -27, -17, -24, -1] 

    Original array (range of -50 to 50):
            [-44, -47, -15, -42, -39, -4, -40, -34, -8, -29, -44, -43, -3, -1, -44, -18, -47, -25, -13, -6]
    Array sorted from index 0 to 0:
            > [-44, -47, -15, -42, -39, -4, -40, -34, -8, -29, -44, -43, -3, -1, -44, -18, -47, -25, -13, -6] 
*/
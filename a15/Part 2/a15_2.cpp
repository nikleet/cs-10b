/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 5/19/2021
    Instructor: Dave Harden
    File: "a15_2.cpp"
    Assignment 15, Part 2

    This program implements and tests a recursive function that detects if a
    MyString object is a palindome.

    Note: This program requires mystring.h and mystring.cpp to be in the current
    working directory.
*/

#include "mystring.h"
#include <iostream>
#include <cctype>

using namespace std;
using namespace cs_mystring;

bool isAPalindrome(MyString str, int lBound, int rBound);

int main() {

    cout << "Enter a string: ";
    MyString str;
    str.read(cin, '\n');

    while(str != "quit") {
        if(isAPalindrome(str, 0, str.length() - 1))
            cout << str << " is a palindome." << endl;
        else
            cout << str << " is not a palindrome." << endl;
        cout << "Enter a string: ";
        str.read(cin, '\n');
    }

    return 0;
}






/*
    Returns true if the "substring" of the parameter MyString str from index
    lBound to rBound is palindromic.

    pre: lBound < rBound and both are within the bounds of str

    post: The function has returned true if str is a palindrome and false if it
    is not.  
*/
bool isAPalindrome(MyString str, int lBound, int rBound) {
    bool endMatch = toupper(str[lBound]) == toupper(str[rBound]); 
    if(lBound == rBound) {
        return true;
    }
    else if(ispunct(str[lBound]) || isspace(str[lBound])) {
        return isAPalindrome(str, lBound + 1, rBound);
    }
    else if(ispunct(str[rBound]) || isspace(str[rBound])) {
        return isAPalindrome(str, lBound, rBound - 1);
    }
    else {
        return endMatch && isAPalindrome(str, lBound + 1, rBound - 1);
    }
}

/* OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\a15\Part 2>.\a15_2.exe
    Enter a string: Able was I, ere I saw Elba
    Able was I, ere I saw Elba is a palindome.
    Enter a string: peanut butter
    peanut butter is not a palindrome.
    Enter a string: quit

    C:\Users\Niklas Leet\c++\cs-10b\a15\Part 2>.\a15_2.exe
    Enter a string: racecar
    racecar is a palindome.
    Enter a string: r.aCe!CaR
    r.aCe!CaR is a palindome.
    Enter a string: 1234321
    1234321 is a palindome.
    Enter a string: redivider
    redivider is a palindome.
    Enter a string: redividers
    redividers is not a palindrome.
    Enter a string: roster      
    roster is not a palindrome.
    Enter a string: reader
    reader is not a palindrome.
    Enter a string: quit
*/
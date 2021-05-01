/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a1_1.cpp
    Peers cited: Nikolas Brandt; provided advice on the header and footer comments.

    Description: Determines if a certain date is a magic date. A date is magic when it's 
    month multiplied by it's day is equal to it's two-digit year. 
    
    Input: a date in the specified format (month/day/2-digit-year)
    Output: an indication of whether the date is "magical" or not
*/

#include <iostream>
using namespace std;

int main() {
    int month;
    int day;
    int year;
    char slash;
    
    cout << "Enter a date in the format month/day/2-digit-year: ";
    cin >> month >> slash >> day >> slash >> year;
    
    if(month * day == year) {
        cout << "That is a magic date!\n";
    }
    else {
        cout << "That is not a magic date.\n";
    }

    return 0;
}

/* Output:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-1.1>.\a1_1.exe
    Enter a date in the format month/day/2-digit-year: 2/24/03
    That is not a magic date.

    C:\Users\Niklas Leet\c++\cs-10b\assignment-1.1>.\a1_1.exe
    Enter a date in the format month/day/2-digit-year: 3/12/36
    That is a magic date!   
*/
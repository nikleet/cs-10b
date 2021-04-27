/*
    Niklas Leet

    Class invariant: A MyString object has one private member variable, str,
    which stores a null-terminated c-string. The default constructor will store
    an empty string in str. MyString has a public static constant,
    MAX_INPUT_SIZE, which is an int that specifies the maximum length string
    that MyString can read from the input stream. 

*/
#include "mystring.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cassert>

using namespace std;

namespace cs_mystring {
    
    // Constructs a MyString object containing an empty string.
    MyString::MyString() {
        str = new char[1];
        strcpy(str, "");
    }
    




    // Constructs a MyString object containing the string at inStr.
    MyString::MyString(const char *inStr) {
        str = new char[strlen(inStr) + 1];
        strcpy(str, inStr);
    }





    // Constructs a copy of the calling MyString object.
    MyString::MyString(const MyString& right) {
        str = new char[strlen(right.str) + 1];
        strcpy(str, right.str);
    }





    // Deallocates str and deconstructs the calling object. 
    MyString::~MyString() {
        delete [] str;
    }






    // Returns the length of str
    int MyString::length() const {
        return strlen(str);
    }





    // Stores the right parameter in the calling MyString object.
    MyString MyString::operator=(const MyString& right) {
        if(this != &right) {
            delete [] str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }
        return *this;
    }





    // Returns the memory address of the char specified by int index in str. 
    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }





    // Returns the char specified by int index in str.
    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }
    




    // Stores the c-string in the input stream (until the delimiting char delim)
    // and stores it in the calling object.
    void MyString::read(std::istream& in, char delim) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE + 1, delim);
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }





    // Concatenates the right parameter onto the str and stores the concatenated
    // string in the calling object.
    MyString MyString::operator+=(const MyString& right) {
        *this = *this + right;
        return *this;
    }






    // Concatenates the c-strings in the right and left parameters and returns
    // the concatenated string as a MyString object.
    MyString operator+(const MyString& left, const MyString& right) {
        MyString result;
        delete [] result.str;
        result.str = new char[strlen(left.str) + strlen(right.str) + 1];
        strcpy(result.str, left.str);
        strcat(result.str, right.str);
        return result;
    }





    // Returns true if the left parameter comes before the left parameter
    // alphabetically.
    bool operator<(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) < 0;
    }
    




    // Returns true if the left parameter comes after the right
    // parameter alphabetically.
    bool operator>(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) > 0;
    }





    // Returns true if the left parameter is equal to or comes before the
    // right parameter alphabetically.
    bool operator<=(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) <= 0;
    }





    // Returns true if the left parameter is equal to or comes after the
    // right parameter alphabetically.
    bool operator>=(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) >= 0;
    }





    // Returns true if the left parameter is equal to the right
    // parameter.
    bool operator==(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) == 0;

    }





    // Returns true if the parameters are not equal.
    bool operator!=(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) != 0;
    }





    // Inserts the c-string stored in source into the ostream out.
    ostream& operator<<(std::ostream& out, const MyString& source) {
        out << source.str; 
        return out;
    }





    // Reads the c-string (terminated by whitespace) from the istream in and
    // stores it in the target MyString object. 
    istream& operator>>(std::istream& in, MyString& target) {
        while(isspace(in.peek())) {
            in.ignore();
        }
            
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in >> temp;
        delete [] target.str;
        target.str = new char[strlen(temp) + 1];
        strcpy(target.str, temp);

        return in;
    }
}

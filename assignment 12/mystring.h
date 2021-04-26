/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 4/5/2021
    Instructor: Dave Harden
    File: "mystring.h"
    Assignment 11, Part 1

    The MyString class is a simple c-string class. It provides functions and operators for concatenation, comparison, storage and extraction of strings and characters stored in MyString objects. 

    MyString provides the following functions:

    MyString();
        post: A MyString object containing an empty string has been created. 

    MyString(const char *inStr);
        post: A MyString object containing the char array pointed to by inStr has been created.

    MyString(const MyString& right);
        post: A copy of the calling object has been created.

    ~MyString();
        post: The calling object has been deallocated.

    int length() const;
        post: The length of c-string stored in the calling object has been returned.

    MyString operator=(const MyString& right);
        post: 

    char& operator[](int index);
    char operator[](int index) const;
    void read(std::istream& in, char delim);
    MyString operator+=(const MyString& right);
    friend MyString operator+(const MyString& left, const MyString& right);
    friend bool operator<(const MyString& left, const MyString& right);
    friend bool operator>(const MyString& left, const MyString& right);
    friend bool operator<=(const MyString& left, const MyString& right);
    friend bool operator>=(const MyString& left, const MyString& right);
    friend bool operator==(const MyString& left, const MyString& right);
    friend bool operator!=(const MyString& left, const MyString& right);
    friend std::ostream& operator<<(std::ostream& out, const MyString& source);
    friend std::istream& operator>>(std::istream& in, MyString& source);    

*/

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

namespace cs_mystring {

    class MyString {
        public:
            static const int MAX_INPUT_SIZE = 127;
            
            MyString();
            MyString(const char *inStr);
            MyString(const MyString& right);
            ~MyString();
            int length() const;
            MyString operator=(const MyString& right);
            char& operator[](int index);
            char operator[](int index) const;
            void read(std::istream& in, char delim);
            MyString operator+=(const MyString& right);
            friend MyString operator+(const MyString& left,
                                      const MyString& right);
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);
            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);
            friend std::ostream& operator<<(std::ostream& out, 
                                            const MyString& source);
            friend std::istream& operator>>(std::istream& in, 
                                            MyString& source);
        private:
            char *str;
    };
}
#endif

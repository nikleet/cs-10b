/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 4/5/2021
    Instructor: Dave Harden
    Assignment 11, Part 1
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

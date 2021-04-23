// Niklas Leet

#include "mystring.h"
#include <iostream>
#include <cctype>
#include <cstring>
#include <cassert>

using namespace std;

namespace cs_mystring {
    
    MyString::MyString() {
        str = new char[1];
        strcpy(str, "");
    }
    





    MyString::MyString(const char *inStr) {
        str = new char[strlen(inStr) + 1];
        strcpy(str, inStr);
    }






    MyString::MyString(const MyString& right) {
        str = new char[strlen(right.str) + 1];
        strcpy(str, right.str);
    }






    MyString::~MyString() {
        delete [] str;
    }






    int MyString::length() const {
        return strlen(str);
    }






    MyString MyString::operator=(const MyString& right) {
        if(this != &right) {
            delete [] str;
            str = new char[strlen(right.str) + 1];
            strcpy(str, right.str);
        }
        return *this;
    }






    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }






    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(str));
        return str[index];
    }
    





    void MyString::read(std::istream& in, char delim) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE + 1, delim);
        str = new char[strlen(temp) + 1];
        strcpy(str, temp);
    }






    MyString MyString::operator+=(const MyString& right) {
        *this = *this + right;
        return *this;
    }







    MyString operator+(const MyString& left, const MyString& right) {
        MyString result;
        delete [] result.str;
        result.str = new char[strlen(left.str) + strlen(right.str) + 1];
        strcpy(result.str, left.str);
        strcat(result.str, right.str);
        return result;
    }






    bool operator<(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) < 0;
    }
    





    bool operator>(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) > 0;
    }






    bool operator<=(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) <= 0;
    }






    bool operator>=(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) >= 0;
    }






    bool operator==(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) == 0;

    }






    bool operator!=(const MyString& left, const MyString& right) {
        return strcmp(left.str, right.str) != 0;
    }






    ostream& operator<<(std::ostream& out, const MyString& source) {
        out << source.str; 
        return out;
    }






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

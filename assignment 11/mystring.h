#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

namespace cs_mystring {

    class MyString {
        public:
            MyString();
            MyString(const char *inStr);
            MyString(const MyString& right);
            ~MyString();
            int length() const;
            MyString operator=(const MyString& right);
            char& operator[](int index);
            char operator[](int index) const;
            friend bool operator<(const MyString& left, const MyString& right);
            friend bool operator>(const MyString& left, const MyString& right);
            friend bool operator<=(const MyString& left, const MyString& right);
            friend bool operator>=(const MyString& left, const MyString& right);
            friend bool operator==(const MyString& left, const MyString& right);
            friend bool operator!=(const MyString& left, const MyString& right);
            friend std::ostream& operator<<(std::ostream& out, 
                                            const MyString& source);
        private:
            char *str;
    };
}
#endif
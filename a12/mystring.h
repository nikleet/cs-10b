/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 4/5/2021
    Instructor: Dave Harden
    File: "mystring.h"
    Assignment 11, Part 1

    The MyString class is a simple c-string class. It provides functions and 
    operators for concatenation, comparison, storage and extraction of strings 
    and characters stored in MyString objects. 

    MyString provides the following functions:

    MyString();
        post: A MyString object containing an empty string has been created. 

    MyString(const char *inStr);
        post: A MyString object containing the char array pointed to by inStr 
        has been created.

    MyString(const MyString& right);
        post: The right parameter has been deep copied to the calling object.

    ~MyString();
        post: The calling object has been deallocated.

    int length() const;
        post: The length of c-string stored in the calling object has been 
        returned.

    MyString operator=(const MyString& right);
        post: The right parameter has been stored in the calling object.

    char& operator[](int index);
        post: The memory address of the c-string at the index [i] character 
        stored in the calling object has been returned.  

    char operator[](int index) const;
        post: The character at the index [i] of the c-string stored in the
        calling object has been returned.

    void read(std::istream& in, char delim);
        pre: There is a c-string terminated with the character delim in the
        parameter input stream. 
        post: The c-string in the input stream (until the delimiting character)
        has been stored in the calling object.

    MyString operator+=(const MyString& right);
        post: The c-string stored in the calling object and the right string
        have been concatenated and stored in the calling object. The calling
        object has been returned.

    friend MyString operator+(const MyString& left, const MyString& right);
        post: The c-strings in the left and right parameters have been
        concatenated and returned as a MyString object.

    friend bool operator<(const MyString& left, const MyString& right);
        post: Returns true if the left parameter comes before the left parameter
        alphabetically.
        
    friend bool operator>(const MyString& left, const MyString& right);
        post: Returns true if the left parameter comes after the right
        parameter alphabetically.
        
    friend bool operator<=(const MyString& left, const MyString& right);
        post: Returns true if the left parameter is equal to or comes before the
        right parameter alphabetically.
        
    friend bool operator>=(const MyString& left, const MyString& right);
        post: Returns true if the left parameter is equal to or comes after the
        right parameter alphabetically.

    friend bool operator==(const MyString& left, const MyString& right);
        post: Returns true if the left parameter is equal to the right
        parameter.
        
    friend bool operator!=(const MyString& left, const MyString& right);
        post: Returns true if the parameters are not equal.

    friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        post: The c-string in the source MyString object (null terminated) has
        been inserted into the parameter output stream and the output stream has
        been returned. 

    friend std::istream& operator>>(std::istream& in, MyString& source);
        pre: The c-string in the input stream is less than MAX_INPUT_SIZE
        characters in length and is terminated by whitespace.
        post: The c-string in the parameter input stream has been stored in the
        source MyString object.

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
                                            MyString& target);
        private:
            char *str;
    };
}
#endif

/* OUTPUT

    C:\Users\Niklas Leet\c++\cs-10b\assignment 12>.\stringtest.exe
    ----- Testing basic String creation & printing
    string [0] = Wow
    string [1] = C++ is neat!
    string [2] =
    string [3] = a-z

    ----- Now reading MyStrings from file

    ----- first, word by word
    Read string = The
    Read string = first
    Read string = time
    Read string = we
    Read string = will
    Read string = read
    Read string = individual
    Read string = words,
    Read string = next
    Read string = we
    Read string = read
    Read string = whole
    Read string = lines

    ----- now, line by line
    Read string = The  first  time  we  will
    Read string =     read individual words, next
    Read string = we read whole lines

    ----- Testing access to characters (using const)
    Whole string is abcdefghijklmnopqsrtuvwxyz
    now char by char: abcdefghijklmnopqsrtuvwxyz
    ----- Testing access to characters (using non-const)
    Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

    ----- Testing relational operators between MyStrings
    Comparing app to apple
            Is left < right? true
            Is left <= right? true
            Is left > right? false
            Is left >= right? false
            Does left == right? false
            Does left != right ? true
    Comparing apple to 
            Is left < right? false
            Is left <= right? false
            Is left > right? true
            Is left >= right? true
            Does left == right? false
            Does left != right ? true
    Comparing  to Banana
            Is left < right? true
            Is left <= right? true
            Is left > right? false
            Is left >= right? false
            Does left == right? false
            Does left != right ? true
    Comparing Banana to Banana
            Is left < right? false
            Is left <= right? true
            Is left > right? false
            Is left >= right? true
            Does left == right? true
            Does left != right ? false

    ----- Testing relations between MyStrings and char *
    Comparing he to hello
            Is left < right? true
            Is left <= right? true
            Is left > right? false
            Is left >= right? false
            Does left == right? false
            Does left != right ? true
    Comparing why to wackity
            Is left < right? false
            Is left <= right? false
            Is left > right? true
            Is left >= right? true
            Does left == right? false
            Does left != right ? true

    ----- Testing concatentation on MyStrings
    outrageous + milk = outrageousmilk
    milk +  = milk
    + cow = cow
    cow + bell = cowbell

    ----- Testing concatentation between MyString and char *
    abcde + XYZ = abcdeXYZ
    XYZ + abcde = XYZabcde

    ----- Testing shorthand concat/assign on MyStrings
    who += what = whowhatandwhowhat
    what += WHEN = whatWHENandwhatWHEN
    WHEN += Where = WHENWhereandWHENWhere
    Where += why = WherewhyandWherewhy

    ----- Testing shorthand concat/assign using char *
    I love  += programming = I love programming

    ----- Testing copy constructor and operator= on MyStrings
    original is cake, copy is fake
    original is cake, copy is fake
    after self assignment, copy is Copy Cat
    Testing pass & return MyStrings by value and ref
    after calling Append, sum is BinkyBoo
    val is winky
    after assign,  val is BinkyBoo
*/
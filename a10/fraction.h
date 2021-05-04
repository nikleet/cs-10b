/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 4/5/2021
    Instructor: Dave Harden

    The Fraction class can be used to create and manipulate objects that
    represent mathematical fractions, storing a numerator and denominator. 
    
    The following functions are available:
    Fraction(int n = 0, int d = 1);
        post: The calling object has been created and initialized so that the 
              numerator is n (defaults to 0) and the denominator is d (defaults 
              to 1) or with default values.
    int getN() const;
        post: The private member variable, numerator, has been returned. 
    int getD() const;
        post: The private member variable, denominator, has been returned.
    Fraction addedTo(const Fraction &addend) const;
        post: The calling object and the parameter Fraction object, passed by
              reference, have been added together and returned.
    Fraction subtract(const Fraction &subtrahend) const;
        post: The parameter Fraction object, passed by reference, has been 
              subtracted from the calling object and returned.  
    Fraction multipliedBy(const Fraction &factor) const;
        post: The calling object and the parameter Fraction object, passed by
              reference, have been multiplied and returned.
    Fraction dividedBy(const Fraction &divisor) const;
        post: The parameter Fraction object, passed by reference, has been 
              divided by the calling object and returned.  
    bool isEqualTo(const Fraction &comparator) const;
        post: Returns true if the calling object is equal to the parameter 
              Fraction object.
    void print() const;
        post: Prints the calling object in the format "N/D", where N is 
              the numerator and D is the denominator or in the mixed form
              "F+N/D", where F is the whole number factor with a leading sign 
              if it is negative.
    Fraction operator+=(const Fraction& right);
        pre:  A Fraction object appears on the left of the operator and a 
              Fraction object or an integer appears on the right side of the 
              operator.
        post: A Fraction object representing the sum of the calling Fraction   
              object and the parameter to the right of the operator has been 
              returned.
    Fraction operator-=(const Fraction& right);
        pre:  A Fraction object appears on the left of the operator and a 
              Fraction object or an integer appears on the right side of the 
              operator.
        post: A Fraction object representing the difference of the calling 
              Fraction object and the parameter to the right of the operator 
              has been returned.
    Fraction operator*=(const Fraction& right);
        pre:  A Fraction object appears on the left of the operator and a 
              Fraction object or an integer appears on the right side of the 
              operator.
        post: A Fraction object representing the product of the calling 
              Fraction object and the parameter to the right of the operator 
              has been returned.
    Fraction operator/=(const Fraction& right);
        pre:  A Fraction object appears on the left of the operator and a 
              Fraction object or an integer appears on the right side of the 
              operator.
        post: A Fraction object representing the quotient of the calling 
              Fraction object and the parameter to the right of the operator 
              has been returned.
    Fraction operator++();
        pre:  The operator appears as a pre-increment statement with a Fraction 
              object to the right.
        post: The calling Fraction has been assigned to the value of the sum of
              a Fraction object representing 1/1 and the calling Fraction 
              object; the modified calling Fraction object has been 
              returned.    
    Fraction operator++(int);
        pre:  The operator appears as a post-increment statement with a      
              Fraction object to the left.
        post: The calling Fraction has been assigned to the value of the sum of 
              a Fraction object representing 1/1 and the calling Fraction 
              object; the Fraction object containing the original state of the 
              calling Fraction object has been returned.
    Fraction operator--();
        pre:  The operator appears as a pre-decrement statement with a Fraction 
              object to the right.
        post: The calling Fraction has been assigned to the value of the 
              difference of the calling Fraction and a Fraction object 
              representing 1/1; the modified calling Fraction object has been 
              returned.
    Fraction operator--(int);
        pre:  The operator appears as a post-decrement statement with a      
              Fraction object to the left.
        post: The calling Fraction has been assigned to the value of the 
              difference of the calling Fraction and a Fraction object 
              representing 1/1; the Fraction object containing the original 
              state of the calling Fraction object has been returned.
    friend Fraction operator+(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: A Fraction object representing the sum of the right parameter and 
              left parameter has been returned.
    friend Fraction operator-(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: A Fraction object representing the difference of the right    
              parameter and left parameter has been returned.
    friend Fraction operator*(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: A Fraction object representing the product of the right parameter 
              and left parameter has been returned.
    friend Fraction operator/(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: A Fraction object representing the sum of the right parameter and 
              left parameter has been returned.
    friend bool operator<(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: Returns true if the left parameter is less than the right    
              parameter.
    friend bool operator>(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: Returns true if the left parameter is greater than the right    
              parameter.
    friend bool operator<=(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: Returns true if the left parameter is less than or equal to the 
              right parameter.
    friend bool operator>=(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: Returns true if the left parameter is greater than or equal to 
              the right parameter.
    friend bool operator==(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: Returns true if the left parameter is equal to the right 
              parameter.
    friend bool operator!=(const Fraction& left, const Fraction& right);
        pre:  The parameter on the left and right of the operator must be a 
              either Fraction object or an integer.
        post: Returns true if the left parameter is not equal to the right 
              parameter.
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
        pre: The parameter to the left of the operator represents an output 
             stream (ostream) object, and the parameter to the right represents 
             a Fraction object.
        post: The Fraction has been printed in reduced form. If it is a whole 
              number, it has been printed without a denominator. Otherwise, if 
              it is an improper fraction, it has been printed as a mixed number 
              with a '+' sign between the two parts and a leading minus sign if 
              it is negative. The output stream object has been returned.
    friend std::istream& operator>>(std::istream& in, Fraction& f);
        pre:  The parameter to the left of the operatator represents an input 
              stream (istream) object, and the parameter to the right 
              represents a Fraction object that will recieve the data from the 
              input stream. The data in the input stream must properly 
              formatted in the form of an improper fraction (N/D), mixed number 
              (F+N/D), or whole number (N), and each fraction must be 
              terminated with a newline character unless no characters proceed 
              it. 
        post: The data from the input stream has been processed and copied to 
              the member variables of the Fraction object parameter. The input 
              stream object has been returned.
*/

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

namespace cs_fraction {

    class Fraction {
        public:
            Fraction(int n = 0, int d = 1);
            int getN() const;
            int getD() const;
            Fraction addedTo(const Fraction &addend) const;
            Fraction subtract(const Fraction &subtrahend) const;
            Fraction multipliedBy(const Fraction &factor) const;
            Fraction dividedBy(const Fraction &divisor) const;
            bool isEqualTo(const Fraction &comparator) const;
            void print() const;
            Fraction operator+=(const Fraction& right);
            Fraction operator-=(const Fraction& right);
            Fraction operator*=(const Fraction& right);
            Fraction operator/=(const Fraction& right);
            Fraction operator++();
            Fraction operator++(int);
            Fraction operator--();
            Fraction operator--(int);
            friend Fraction operator+(const Fraction& left,
                                      const Fraction& right);
            friend Fraction operator-(const Fraction& left,
                                      const Fraction& right);
            friend Fraction operator*(const Fraction& left, 
                                      const Fraction& right);
            friend Fraction operator/(const Fraction& left, 
                                      const Fraction& right);
            friend bool operator<(const Fraction& left, const Fraction& right);
            friend bool operator>(const Fraction& left, const Fraction& right);
            friend bool operator<=(const Fraction& left, const Fraction& right);
            friend bool operator>=(const Fraction& left, const Fraction& right);
            friend bool operator==(const Fraction& left, const Fraction& right);
            friend bool operator!=(const Fraction& left, const Fraction& right);
            friend std::ostream& operator<<(std::ostream& out, 
                                            const Fraction& f);
            friend std::istream& operator>>(std::istream& in, 
                                            Fraction& f);
        private:
            int num;
            int denom;
            void simplify();
    };
}
#endif

/* OUTPUT
    C:\Users\Niklas Leet\c++\cs-10b\assignment 10>.\a10_1.exe

    ----- Testing basic Fraction creation & printing
    (Fractions should be in reduced form, and as mixed numbers.)
    Fraction [0] = 1/2
    Fraction [1] = -5/7
    Fraction [2] = 10
    Fraction [3] = -4
    Fraction [4] = 0
    Fraction [5] = 4+2/3
    Fraction [6] = 0

    ----- Now reading Fractions from file
    Read Fraction = 1/3
    Read Fraction = 1/2
    Read Fraction = 3/4
    Read Fraction = -4/5
    Read Fraction = 6
    Read Fraction = 5
    Read Fraction = -8
    Read Fraction = 1+2/5
    Read Fraction = -16+2/3
    Read Fraction = 1+1/4
    Read Fraction = 2
    Read Fraction = -4+1/4
    Read Fraction = -10+5/6

    ----- Testing relational operators between Fractions
    Comparing 1/2 to -1/2
            Is left < right? false
            Is left <= right? false
            Is left > right? true
            Is left >= right? true
            Does left == right? false
            Does left != right ? true
    Comparing -1/2 to 1/2
            Is left < right? true
            Is left <= right? true
            Is left > right? false
            Is left >= right? false
            Does left == right? false
            Does left != right ? true
    Comparing 1/2 to 1/10
            Is left < right? false
            Is left <= right? false
            Is left > right? true
            Is left >= right? true
            Does left == right? false
            Does left != right ? true
    Comparing 1/10 to 0
            Is left < right? false
            Is left <= right? false
            Is left > right? true
            Is left >= right? true
            Does left == right? false
            Does left != right ? true
    Comparing 0 to 0
            Is left < right? false
            Is left <= right? true
            Is left > right? false
            Is left >= right? true
            Does left == right? true
            Does left != right ? false

    ----- Testing relations between Fractions and integers
    Comparing -1/2 to 2
            Is left < right? true
            Is left <= right? true
            Is left > right? false
            Is left >= right? false
            Does left == right? false
            Does left != right ? true
    Comparing -3 to 1/4
            Is left < right? true
            Is left <= right? true
            Is left > right? false
            Is left >= right? false
            Does left == right? false
            Does left != right ? true

    ----- Testing binary arithmetic between Fractions
    1/6 + 1/3 = 1/2
    1/6 - 1/3 = -1/6
    1/6 * 1/3 = 1/18
    1/6 / 1/3 = 1/2
    1/3 + -2/3 = -1/3
    1/3 - -2/3 = 1
    1/3 * -2/3 = -2/9
    1/3 / -2/3 = -1/2
    -2/3 + 5 = 4+1/3
    -2/3 - 5 = -5+2/3
    -2/3 * 5 = -3+1/3
    -2/3 / 5 = -2/15
    5 + -1+1/3 = 3+2/3
    5 - -1+1/3 = 6+1/3
    5 * -1+1/3 = -6+2/3
    5 / -1+1/3 = -3+3/4

    ----- Testing arithmetic between Fractions and integers
    -1/2 + 4 = 3+1/2
    -1/2 - 4 = -4+1/2
    -1/2 * 4 = -2
    -1/2 / 4 = -1/8
    3 + -1/2 = 2+1/2
    3 - -1/2 = 3+1/2
    3 * -1/2 = -1+1/2
    3 / -1/2 = -6

    ----- Testing shorthand arithmetic assignment on Fractions
    1/6 += 4 = 4+1/6
    4+1/6 -= 4 = 1/6
    1/6 *= 4 = 2/3
    2/3 /= 4 = 1/6
    4 += -1/2 = 3+1/2
    3+1/2 -= -1/2 = 4
    4 *= -1/2 = -2
    -2 /= -1/2 = 4
    -1/2 += 5 = 4+1/2
    4+1/2 -= 5 = -1/2
    -1/2 *= 5 = -2+1/2
    -2+1/2 /= 5 = -1/2

    ----- Testing shorthand arithmetic assignment using integers
    -1/3 += 3 = 2+2/3
    2+2/3 -= 3 = -1/3
    -1/3 *= 3 = -1
    -1 /= 3 = -1/3

    ----- Testing increment/decrement prefix and postfix
    Now g = -1/3
    g++ = -1/3
    Now g = 2/3
    ++g = 1+2/3
    Now g = 1+2/3
    g-- = 1+2/3
    Now g = 2/3
    --g = -1/3
    Now g = -1/3
*/
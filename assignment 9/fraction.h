/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 4/5/2021
    Instructor: Dave Harden

    The Fraction class can be used to create and manipulate objects that
    represent mathematical fractions, storing a numerator and denominator. 
    The following functions are available:
    Fraction();
        post: The calling object has been created and initialized to 0/1.
    Fraction(int n, int d);
        post: The calling object has been created and initialized so that the 
              numerator is n and the denominator is d.
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
        post: Prints the calling object in the format "N / D", where N is 
              the numerator and D is the denominator.
*/

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    public:
        Fraction();
        Fraction(int n, int d);
        int getN() const;
        int getD() const;
        Fraction addedTo(const Fraction &addend) const;
        Fraction subtract(const Fraction &subtrahend) const;
        Fraction multipliedBy(const Fraction &factor) const;
        Fraction dividedBy(const Fraction &divisor) const;
        bool isEqualTo(const Fraction &comparator) const;
        void print() const;
    private:
        int numerator;
        int denominator;
        void simplify();
};

#endif
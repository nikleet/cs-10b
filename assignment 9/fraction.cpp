/*
    Niklas Leet

    Class Invariant: a Fraction object has 2 int data members: numerator, which
    stores the numerator of the fraction; and denominator, which stores the 
    denominator of the fraction. The default constructor will assign zero 
    to the numerator and one to the denominator. Fraction objects will always
    have a nonzero denominator, otherwise, the constructor will throw an error. 
    Fractions are always stored, returned, and printed in the lowest terms. 
*/

#include "fraction.h"
#include <iostream>
#include <cassert>

using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}






/*
    Constructs a Fraction object and stores the numerator, parameter n, and
    denominator, parameter d, in the lowest possible terms.
*/
Fraction::Fraction(int n, int d) {
    assert(d != 0);
    numerator = n;
    denominator = d;
    simplify();
}






int Fraction::getN() const {
    return numerator;
}






int Fraction::getD() const {
    return denominator;
}






/*
    Simplifies the calling Fraction object by dividing both the numerator and 
    denominator by their greatest common factor.
*/
void Fraction::simplify() {
    if(numerator > 1 && denominator > 1) {
        int gcf = 1;
        for(int i = 2; i <= min(numerator, denominator) / 2; ++i) {
            if(numerator % i == 0 && denominator % i == 0)
                gcf = i;
        } 
        numerator /= gcf;
        denominator /= gcf;
    }
    if(numerator == denominator) {
        numerator = 1;
        denominator = 1;
    }
}






/*
    Returns the sum of the calling Fraction object and parameter Fraction object
    as a Fraction object. 
*/
Fraction Fraction::addedTo(const Fraction &addend) const { 
    int n = (numerator * addend.getD()) + (addend.getN() * denominator);
    int d = denominator * addend.getD();
    Fraction sum(n, d);
    sum.simplify();
    return sum;
}






/*
    Returns the difference of the calling Fraction object and parameter Fraction
    object as a Fraction object. 
*/
Fraction Fraction::subtract(const Fraction &subtrahend) const {
    int n = (numerator * subtrahend.getD()) 
                - (subtrahend.getN() * denominator); 
    int d = denominator * subtrahend.getD();
    Fraction diff(n, d);
    diff.simplify();
    return diff;
}






/*
    Returns the product of the calling Fraction object and parameter Fraction
    object as a Fraction object. 
*/
Fraction Fraction::multipliedBy(const Fraction &factor) const { 
    int n = numerator * factor.getN();
    int d = denominator * factor.getD();
    Fraction product(n, d);
    product.simplify();
    return product;
}






/*
    Returns the quotient of the calling Fraction object and parameter Fraction
    object as a Fraction object. 
*/
Fraction Fraction::dividedBy(const Fraction &dividend) const {
    int n = numerator * dividend.getD();
    int d = denominator * dividend.getN();
    Fraction quotient(n, d);
    quotient.simplify();
    return quotient;
}






// Returns true if the parameter object and the calling object are equal
bool Fraction::isEqualTo(const Fraction &comparator) const {
    return numerator * comparator.getD() == denominator * comparator.getN();
}






// Prints the calling object.
void Fraction::print() const {
    cout << numerator << "/" << denominator;
} 

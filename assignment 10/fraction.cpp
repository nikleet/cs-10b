/*
    Niklas Leet

    Class Invariant: a Fraction object has 2 int data members: numerator, which
    stores the numerator of the fraction; and denominator, which stores the 
    denominator of the fraction. The default constructor will assign zero 
    to the numerator and one to the denominator. Fraction objects will always
    have a nonzero denominator, otherwise, the constructor will throw an error
    or the denominator will be changed to one if it becomes zero elsewhere. 
    Fractions are always stored, returned, and printed in the lowest terms.
    Fractions are stored in improper form, but are printed as a mixed number 
    with the format "F+N/D"--where F is the whole number factor, N is the
    numerator, and D is the denominator--if it is possible to do so. If the
    fraction is negative, it will be printed with a leading negative sign.
*/

#include "fraction.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cctype>

using namespace std;

namespace cs_fraction {

    /*
        Constructs a Fraction object and stores the numerator, parameter n, and
        denominator, parameter d, in the lowest possible terms.
    */
    Fraction::Fraction(int n, int d) {
        assert(d != 0);
        num = n;
        denom = d;
        simplify();
    }





    // Returns the numerator member variable
    int Fraction::getN() const {
        return num;
    }





    // Returns the denominator member variable
    int Fraction::getD() const {
        return denom;
    }






    /*
        Ensures the denominator is never zero or negative, converts the 
        fraction to 1/1 if the numerator equals the denominator, simplifies the 
        fraction by dividing by the GCF.
    */
    void Fraction::simplify() {
        if(denom == 0)
            denom = 1;
        if(abs(denom) == -denom) {
            num *= -1;
            denom *= -1;
        }
        if(abs(num) == denom) {
            num /= denom;
            denom = 1;
        }
        else if((num > 1 || num < -1) && (denom > 1 || denom < -1)) {
            int gcf = 1;
            for(int i = 2; i <= min(abs(num), abs(denom)); ++i) {
                if(num % i == 0 && denom % i == 0)
                    gcf = i;
            } 
            num /= gcf;
            denom /= gcf;
        }
    }






    /*
        Returns the sum of the calling Fraction object and parameter Fraction
        object as a Fraction object. 
    */
    Fraction Fraction::addedTo(const Fraction &addend) const { 
        int n = (num * addend.getD()) + (addend.getN() * denom);
        int d = denom * addend.getD();
        Fraction sum(n, d);
        sum.simplify();
        return sum;
    }






    /*
        Returns the difference of the calling Fraction object and parameter 
        Fraction object as a Fraction object. 
    */
    Fraction Fraction::subtract(const Fraction &subtrahend) const {
        int n = (num * subtrahend.getD()) 
                    - (subtrahend.getN() * denom); 
        int d = denom * subtrahend.getD();
        Fraction diff(n, d);
        diff.simplify();
        return diff;
    }






    /*
        Returns the product of the calling Fraction object and parameter 
        Fraction object as a Fraction object. 
    */
    Fraction Fraction::multipliedBy(const Fraction &factor) const { 
        int n = num * factor.getN();
        int d = denom * factor.getD();
        Fraction product(n, d);
        product.simplify();
        return product;
    }






    /*
        Returns the quotient of the calling Fraction object and parameter 
        Fraction object as a Fraction object. 
    */
    Fraction Fraction::dividedBy(const Fraction &dividend) const {
        int n = num * dividend.getD();
        int d = denom * dividend.getN();
        Fraction quotient(n, d);
        quotient.simplify();
        return quotient;
    }






    // Returns true if the parameter object and the calling object are equal
    bool Fraction::isEqualTo(const Fraction &comparator) const {
        return *this == comparator;  
    }






    // Prints the calling object.
    void Fraction::print() const {
        cout << *this;
    }






    // Returns the sum of the right and left parameters as a Fraction object
    Fraction operator+(const Fraction& left, const Fraction& right) {
        Fraction sum = left.addedTo(right);
        return sum;
    }   






    /*
        Returns the difference of the right and left parameters as a Fraction 
        object.
    */
    Fraction operator-(const Fraction& left, const Fraction& right) {
        Fraction diff = left.subtract(right);
        return diff;
    }






    /*
        Returns the product of the right and left parameters as a Fraction 
        object.
    */
    Fraction operator*(const Fraction& left, const Fraction& right) {
        Fraction product = left.multipliedBy(right);
        return product;
    }






    /*
        Returns the quotient of the right and left parameters as a Fraction 
        object.
    */
    Fraction operator/(const Fraction& left, const Fraction& right) {
        Fraction quotient = left.dividedBy(right);
        return quotient;
    }







    /*
        Returns the implicit (calling) Fraction object that has been added to 
        the right Fraction object parameter 
    */
    Fraction Fraction::operator+=(const Fraction& right) {
        *this = *this + right;
        return *this;
    }







    /*
        Returns the implicit (calling) Fraction object from which the right 
        Fraction object parameter has been subtracted.
    */
    Fraction Fraction::operator-=(const Fraction& right) {
        *this = *this - right;
        return *this;
    }






    /*
        Returns the implicit (calling) Fraction object that has been multiplied 
        by the right Fraction object parameter 
    */
    Fraction Fraction::operator*=(const Fraction& right) {
        *this = *this * right;
        return *this;
    }







    /*
        Returns the implicit (calling) Fraction object that has been divided by 
        the right Fraction object parameter 
    */
    Fraction Fraction::operator/=(const Fraction& right) {
        *this = *this / right;
        return *this;
    }






    // Increments the calling Fraction object and then returns it. 
    Fraction Fraction::operator++() {
        *this = this->addedTo(Fraction(1));
        return *this;
    }






    /*
        Increments the calling Fraction object and returns a Fraction object 
        representing its original state.
    */
    Fraction Fraction::operator++(int){
        Fraction f(num, denom);
        *this = this->addedTo(Fraction(1));
        return f;
    }





    // Decrements the calling Fraction object and then returns it. 
    Fraction Fraction::operator--() {
        *this = this->subtract(Fraction(1));
        return *this;
    }






    /*
        Decrements the calling Fraction object and returns a Fraction object 
        representing its original state.
    */
    Fraction Fraction::operator--(int){
        Fraction f(num, denom);
        *this = this->subtract(Fraction(1));
        return f;
    }






    /*
        Returns true if the left Fraction parameter is less than the right 
        Fraction parameter.
    */ 
    bool operator<(const Fraction& left, const Fraction& right) {
        return left.num * right.denom < right.num * left.denom;
    }






    /*
        Returns true if the left Fraction parameter is greater than the right 
        Fraction parameter.
    */
    bool operator>(const Fraction& left, const Fraction& right) {
        return left.num * right.denom > right.num * left.denom;
    }






    /*
        Returns true if the left Fraction parameter is less than or equal to 
        the right Fraction parameter.
    */
    bool operator<=(const Fraction& left, const Fraction& right) {
        return left.num * right.denom <= right.num * left.denom;
    }






    /*
        Returns true if the left Fraction parameter is greater than or equal to 
        the right Fraction parameter.
    */
    bool operator>=(const Fraction& left, const Fraction& right) {
        return left.num * right.denom >= right.num * left.denom;
    }






    // Returns true if the left and right parameters are equal
    bool operator==(const Fraction& left, const Fraction& right) {
        return left.num * right.denom == right.num * left.denom;
    }






    // Returns true if the left and right parameters are unequal
    bool operator!=(const Fraction& left, const Fraction& right) {
        return left.num * right.denom != right.num * left.denom;
    }






    /*
        Properly formats and places the Fraction object to the right of the 
        operator into the ostream to the left of the operator. 
    */
    ostream& operator<<(ostream& out, const Fraction& f) {
        if(f.denom == 1 || f.num == 0) {
            out << f.num;
        }
        else if(abs(f.num) > abs(f.denom)) {
            out << f.num / f.denom 
                << "+" << abs(f.num % f.denom)
                << "/" << f.denom;
        }
        else {
            out << f.num << "/" << f.denom;
        }
        return out;
    }







    /*
        Formats and copies the data from the istream to the left of the 
        operator into the member variables of the Fraction object to the right \
        of the operator. 
    */
    istream& operator>>(istream& in, Fraction& f) {
        int n, d, factor;
        bool hasSlash = false;
        bool found = false;
        n = factor = 0;
        d = 1;
        while(!found) {
            int temp;
            in >> temp;
            if(in.peek() == '+') {
                factor = temp;
            }
            else if(in.peek() == '/') { 
                n = temp;
                hasSlash = true;
            }
            else if(!isdigit(in.peek())) {
                if(!hasSlash) {
                    n = temp;
                }
                else {
                    d = temp;
                }
                found = true;
            }
            in.ignore();
        }
        if(abs(factor) == factor)
            f.num = factor * d + n;
        else   
            f.num = factor * d - n;
        f.denom = d;
        f.simplify();
        return in;
    }
}
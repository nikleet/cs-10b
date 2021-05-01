/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a8_1.cpp
    Peers consulted: None
*/

#include <iostream>
using namespace std;

class Fraction {
    public:
        void set(int numerator, int denominator);
        int getN();
        int getD();
        Fraction addedTo(Fraction addend);
        Fraction subtract(Fraction subtrahend);
        Fraction multipliedBy(Fraction factor);
        Fraction dividedBy(Fraction divisor);
        bool isEqualTo(Fraction comparator);
        void print();
    private:
        int numerator;
        int denominator;
};

void Fraction::set(int n, int d) {
    numerator = n;
    denominator = d;
}

int Fraction::getN() {
    return numerator;
}

int Fraction::getD() {
    return denominator;
}

Fraction Fraction::addedTo(Fraction addend) { 
    Fraction sum;
    sum.set((numerator * addend.getD()) + (addend.getN() * denominator),
            denominator * addend.getD());
    return sum;
}

Fraction Fraction::subtract(Fraction subtrahend) {
    Fraction difference;
    difference.set((numerator * subtrahend.getD()) - 
                (subtrahend.getN() * denominator), 
                denominator * subtrahend.getD());
    return difference;
}

Fraction Fraction::multipliedBy(Fraction factor) { 
    Fraction product;
    product.set(numerator * factor.getN(), denominator * factor.getD());
    return product;
}

Fraction Fraction::dividedBy(Fraction dividend) {
    Fraction quotient;
    quotient.set(numerator * dividend.getD(), dividend.getN() * denominator);
    return quotient;
}

bool Fraction::isEqualTo(Fraction comparator) {
    return numerator * comparator.getD() == denominator * comparator.getN();
}

void Fraction::print() {
    cout << numerator << "/" << denominator;
} 

int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}

/* OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-8>.\a8_1.exe
    The product of 9/8 and 2/3 is 18/24
    The quotient of 9/8 and 2/3 is 27/16
    The sum of 9/8 and 2/3 is 43/24
    The difference of 9/8 and 2/3 is 11/24
    The two Fractions are not equal.
*/
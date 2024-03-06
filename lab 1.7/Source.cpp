// Source.cpp
#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
    Fraction fraction1;
    Fraction fraction2;
    cout << "Enter the first fraction:" << endl;
    fraction1.Read();
    cout << "Enter the second fraction:" << endl;
    fraction2.Read();
    Fraction sum = fraction1 + fraction2;
    Fraction difference = fraction1 - fraction2;
    Fraction product = fraction1 * fraction2;

    cout << "Addition result: ";
    sum.Display();
    cout << endl;

    cout << "Subtraction result: ";
    difference.Display();
    cout << endl;

    cout << "Multiplication result: ";
    product.Display();
    cout << endl;

    if (fraction1 == fraction2) {
        cout << "Fractions are equal" << endl;
    }
    else {
        cout << "Fractions are not equal" << endl;
    }

    return 0;
}

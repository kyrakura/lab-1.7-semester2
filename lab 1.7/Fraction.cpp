// Fraction.cpp
#include "Fraction.h"
#include <iostream>

Fraction::Fraction() : wholePart(""), fractionalPart(0) {}

Fraction::Fraction(const DigitString& whole, unsigned short int fractional)
    : wholePart(whole), fractionalPart(fractional) {}

Fraction::Fraction(const std::string& wholeDigits, unsigned short int fractional)
    : wholePart(wholeDigits), fractionalPart(fractional) {}

Fraction::Fraction(int whole, unsigned short int fractional)
    : wholePart(std::to_string(whole)), fractionalPart(fractional) {}

DigitString Fraction::GetWholePart() const {
    return wholePart;
}

void Fraction::SetWholePart(const DigitString& value) {
    wholePart = value;
}

unsigned short int Fraction::GetFractionalPart() const {
    return fractionalPart;
}

void Fraction::SetFractionalPart(unsigned short int value) {
    fractionalPart = value;
}

Fraction Fraction::operator+(const Fraction& other) const {
    DigitString newWhole = wholePart + other.wholePart;
    unsigned short int newFractional = fractionalPart + other.fractionalPart;
    if (newFractional >= BASE) {
        newWhole = newWhole + DigitString(std::to_string(newFractional / BASE));
        newFractional %= BASE;
    }
    return Fraction(newWhole, newFractional);
}

Fraction Fraction::operator-(const Fraction& other) const {
    if (*this < other) {
        return Fraction();
    }

    DigitString newWhole = wholePart - other.wholePart;
    short int newFractional = fractionalPart - other.fractionalPart;
    if (newFractional < 0) {
        newFractional += BASE;
        newWhole = newWhole - DigitString("1");
    }
    return Fraction(newWhole, newFractional);
}

Fraction Fraction::operator*(const Fraction& other) const {
    DigitString newWhole = wholePart * other.wholePart;
    unsigned long int newFractional = fractionalPart * other.fractionalPart + wholePart.GetDigits().size() * other.fractionalPart + other.wholePart.GetDigits().size() * fractionalPart;
    newWhole = newWhole + DigitString(std::to_string(newFractional / BASE));
    newFractional %= BASE;

    return Fraction(newWhole, newFractional);
}


bool Fraction::operator==(const Fraction& other) const {
    return wholePart == other.wholePart && fractionalPart == other.fractionalPart;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    if (wholePart < other.wholePart) {
        return true;
    }
    else if (wholePart == other.wholePart) {
        return fractionalPart < other.fractionalPart;
    }
    return false;
}

bool Fraction::operator<=(const Fraction& other) const {
    return *this < other || *this == other;
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

void Fraction::Init(const DigitString& whole, unsigned short int fractional) {
    wholePart = whole;
    fractionalPart = fractional;
}

void Fraction::Read() {
    std::string wholeDigits;
    unsigned short int fractional;

    std::cout << "Enter the whole part digits: ";
    std::cin >> wholeDigits;
    std::cout << "Enter the fractional part: ";
    std::cin >> fractional;

    wholePart.Init(wholeDigits);
    fractionalPart = fractional;
}

void Fraction::Display() const {
    std::cout << wholePart.GetDigits() << " " << fractionalPart;
}

std::string Fraction::toString() const {
    return wholePart.GetDigits() + " " + std::to_string(fractionalPart);
}
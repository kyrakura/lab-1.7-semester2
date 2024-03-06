// Fraction.h
#pragma once
#include "DigitString.h"

class Fraction {
private:
    DigitString wholePart;
    unsigned short int fractionalPart;
    static const int BASE = 10;

public:
    Fraction();
    Fraction(const DigitString& whole, unsigned short int fractional);
    Fraction(const std::string& wholeDigits, unsigned short int fractional);
    Fraction(int whole, unsigned short int fractional);

    DigitString GetWholePart() const;
    void SetWholePart(const DigitString& value);

    unsigned short int GetFractionalPart() const;
    void SetFractionalPart(unsigned short int value);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    void Init(const DigitString& whole, unsigned short int fractional);
    void Read();
    void Display() const;
    std::string toString() const;
};
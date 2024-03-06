// DigitString.h
#pragma once
#include <string>

class DigitString {
private:
    std::string digits;

public:
    static const int BASE = 10;
    DigitString();
    DigitString(const std::string& digits);

    std::string GetDigits() const;
    void SetDigits(const std::string& digits);

    DigitString operator+(const DigitString& other) const;
    DigitString operator-(const DigitString& other) const;
    DigitString operator*(const DigitString& other) const;
    bool operator==(const DigitString& other) const;
    bool operator!=(const DigitString& other) const;
    bool operator<(const DigitString& other) const;
    bool operator<=(const DigitString& other) const;
    bool operator>(const DigitString& other) const;
    bool operator>=(const DigitString& other) const;

    void Init(const std::string& digits);
    void Read();
    void Display() const;
    std::string toString() const;
};

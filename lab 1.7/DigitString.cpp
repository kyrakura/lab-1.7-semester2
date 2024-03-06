// DigitString.cpp
#include "DigitString.h"
#include <iostream>
using namespace std;

DigitString::DigitString() : digits("") {}

DigitString::DigitString(const std::string& digits) : digits(digits) {}

std::string DigitString::GetDigits() const {
    return digits;
}

void DigitString::SetDigits(const std::string& digits) {
    this->digits = digits;
}

DigitString DigitString::operator+(const DigitString& other) const {
    return DigitString(digits + other.digits);
}

DigitString DigitString::operator-(const DigitString& other) const {
    if (*this < other) {
        return DigitString("0");
    }

    string result = "";
    int borrow = 0;
    int n1 = digits.size();
    int n2 = other.digits.size();
    for (int i = 0; i < n2; ++i) {
        int digit1 = digits[n1 - i - 1] - '0';
        int digit2 = other.digits[n2 - i - 1] - '0' - borrow;

        if (digit2 < digit1) {
            result += to_string(10 + digit2 - digit1);
            borrow = 1;
        }
        else {
            result += to_string(digit2 - digit1);
            borrow = 0;
        }
    }
    for (int i = n2; i < n1; ++i) {
        int digit = digits[n1 - i - 1] - '0' - borrow;
        if (digit < 0) {
            result += to_string(10 + digit);
            borrow = 1;
        }
        else {
            result += to_string(digit);
            borrow = 0;
        }
    }
    reverse(result.begin(), result.end());

    return DigitString(result);
}

DigitString DigitString::operator*(const DigitString& other) const {
    string result(digits.size() + other.digits.size(), '0');

    for (int i = digits.size() - 1; i >= 0; --i) {
        int carry = 0;
        int digit1 = digits[i] - '0';

        for (int j = other.digits.size() - 1; j >= 0; --j) {
            int digit2 = other.digits[j] - '0';
            int product = digit1 * digit2 + carry + result[i + j + 1] - '0';

            result[i + j + 1] = product % 10 + '0';
            carry = product / 10;
        }

        result[i] += carry;
    }
    int start = result.find_first_not_of('0');
    if (start != string::npos) {
        return DigitString(result.substr(start));
    }
    else {
        return DigitString("0");
    }
}

bool DigitString::operator==(const DigitString& other) const {
    return digits == other.digits;
}

bool DigitString::operator!=(const DigitString& other) const {
    return digits != other.digits;
}

bool DigitString::operator<(const DigitString& other) const {
    return digits < other.digits;
}

bool DigitString::operator<=(const DigitString& other) const {
    return digits <= other.digits;
}

bool DigitString::operator>(const DigitString& other) const {
    return !(*this <= other);
}

bool DigitString::operator>=(const DigitString& other) const {
    return !(*this < other);
}

void DigitString::Init(const std::string& digits) {
    this->digits = digits;
}

void DigitString::Read() {
    std::cout << "Enter the digits: ";
    std::cin >> digits;
}

void DigitString::Display() const {
    std::cout << digits;
}

std::string DigitString::toString() const {
    return digits;
}
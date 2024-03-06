#include "pch.h"
#include "CppUnitTest.h"
#include "D:\project C++ 2\lab 1.7\lab 1.7\Fraction.h"
#include "D:\project C++ 2\lab 1.7\lab 1.7\Fraction.cpp"
#include "D:\project C++ 2\lab 1.7\lab 1.7\DigitString.h"
#include "D:\project C++ 2\lab 1.7\lab 1.7\DigitString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(FractionTest)
    {
    public:

        TEST_METHOD(InitTest)
        {
            DigitString digitStr;
            digitStr.Init("12345");
            std::string expectedDigits = "12345";
            Assert::AreEqual(expectedDigits, digitStr.GetDigits());
        }
    };
}

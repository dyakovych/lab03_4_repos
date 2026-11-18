// Test9.1A.cpp
// unit-тест для функцій term() та calc() із завдання 9.1 (варіант 9)

#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>

// підключаємо модулі проєкту 9.1A
#include "../9.1A/globals.cpp"
#include "../9.1A/term.cpp"
#include "../9.1A/series.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test9_1A
{
    TEST_CLASS(Test9_1A)
    {
    public:

        // коефіцієнт рекурентності: x = 2, a0 = 2, n = 1  =>  a1 = -8/3
        TEST_METHOD(TestTerm)
        {
            nsGlobals::x = 2;
            nsGlobals::n = 1;
            nsGlobals::a = 2;

            nsTerm::term();

            Assert::AreEqual(-8.0 / 3.0, nsGlobals::a, 1e-12);
        }

        // сума ряду для x = 0.5
        TEST_METHOD(TestSeriesSum)
        {
            nsGlobals::x = 0.5;
            nsGlobals::e = 0.00001;

            nsSeries::calc();

            Assert::AreEqual(atan(0.5), nsGlobals::s, 0.0001);
        }

        // сума ряду для x = -0.3
        TEST_METHOD(TestSeriesNegativeX)
        {
            nsGlobals::x = -0.3;
            nsGlobals::e = 0.00001;

            nsSeries::calc();

            Assert::AreEqual(atan(-0.3), nsGlobals::s, 0.0001);
        }

        // x = 0: сума 0, один доданок
        TEST_METHOD(TestSeriesZero)
        {
            nsGlobals::x = 0;
            nsGlobals::e = 0.001;

            nsSeries::calc();

            Assert::AreEqual(0.0, nsGlobals::s, 1e-12);
            Assert::AreEqual(1, nsGlobals::n);
        }
    };
}
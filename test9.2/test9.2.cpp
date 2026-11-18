// Test9.2A.cpp
// unit-тест макросів та формули із завдання 9.2.1 (варіант 9)

#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ті самі макроси, що й у main92.cpp
#define SQR(x) ((x)*(x))
#define CUBE(x) ((x)*(x)*(x))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

// гілка z > 5:  w = max^2(x*y^3, x+z)
double wGreater(double x, double y, double z)
{
    return SQR(MAX(x * CUBE(y), x + z));
}

// гілка z <= 5:  w = min(x - y*z, x*y + z)
double wLess(double x, double y, double z)
{
    return MIN(x - y * z, x * y + z);
}

namespace Test9_2A
{
    TEST_CLASS(Test9_2A)
    {
    public:

        TEST_METHOD(TestSqr)
        {
            Assert::AreEqual(9.0, (double)SQR(3), 1e-12);
            Assert::AreEqual(9.0, (double)SQR(1 + 2), 1e-12);   // перевірка дужок
        }

        TEST_METHOD(TestCube)
        {
            Assert::AreEqual(8.0, (double)CUBE(2), 1e-12);
            Assert::AreEqual(-8.0, (double)CUBE(-2), 1e-12);
        }

        TEST_METHOD(TestMaxMin)
        {
            Assert::AreEqual(5.0, (double)MAX(3, 5), 1e-12);
            Assert::AreEqual(5.0, (double)MAX(5, 3), 1e-12);
            Assert::AreEqual(3.0, (double)MIN(3, 5), 1e-12);
            Assert::AreEqual(3.0, (double)MIN(5, 3), 1e-12);
        }

        // вкладені макроси: квадрат максимуму
        TEST_METHOD(TestSqrOfMax)
        {
            Assert::AreEqual(4.0, (double)SQR(MAX(1, 2)), 1e-12);
        }

        // z = 7: x=1, y=2 => max(8, 8)^2 = 64
        TEST_METHOD(TestFormulaGreater1)
        {
            Assert::AreEqual(64.0, wGreater(1, 2, 7), 1e-12);
        }

        // z = 7: x=2, y=1 => max(2, 9)^2 = 81
        TEST_METHOD(TestFormulaGreater2)
        {
            Assert::AreEqual(81.0, wGreater(2, 1, 7), 1e-12);
        }

        // z = 3: x=1, y=2 => min(-5, 5) = -5
        TEST_METHOD(TestFormulaLess1)
        {
            Assert::AreEqual(-5.0, wLess(1, 2, 3), 1e-12);
        }

        // z = 3: x=2, y=1 => min(-1, 5) = -1
        TEST_METHOD(TestFormulaLess2)
        {
            Assert::AreEqual(-1.0, wLess(2, 1, 3), 1e-12);
        }
    };
}
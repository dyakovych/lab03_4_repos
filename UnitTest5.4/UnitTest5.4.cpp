#include "pch.h"
#include "CppUnitTest.h"
#include "../5.4/5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
    TEST_CLASS(UnitTest54)
    {
    public:

        TEST_METHOD(TestS1)
        {
            Assert::AreEqual(S0(1, 15), S1(15, 1), 1e-9);
        }

        TEST_METHOD(TestS2)
        {
            Assert::AreEqual(S0(1, 15), S2(1, 15), 1e-9);
        }

        TEST_METHOD(TestS3)
        {
            Assert::AreEqual(S0(1, 15), S3(15, 1, 0), 1e-9);
        }

        TEST_METHOD(TestS4)
        {
            Assert::AreEqual(S0(1, 15), S4(1, 15, 0), 1e-9);
        }

        TEST_METHOD(TestValue)
        {
            Assert::AreEqual(-0.649174, S0(1, 15), 1e-6);
        }
    };
}
#include "pch.h"
#include "CppUnitTest.h"
#include "../10.2A/10.2A.cpp"     // шлях змініть на свій

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10_2A
{
    TEST_CLASS(UnitTest10_2A)
    {
    public:
        TEST_METHOD(TestAverage)
        {
            Student s;
            s.fizyka = 90;
            s.matematyka = 80;
            s.informatyka = 70;

            Assert::AreEqual(80.0, Average(s), 0.0001);
        }
    };
}
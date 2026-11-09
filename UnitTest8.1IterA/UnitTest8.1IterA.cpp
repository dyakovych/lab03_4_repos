#include "pch.h"
#include "CppUnitTest.h"
#pragma warning(disable : 4996)   // strcat, strcpy, strncat у підключеному коді
#include "../8.1iterA/8.1iterA.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab81IterTests
{
	TEST_CLASS(Lab81IterTests)
	{
	public:

		// Кількість четвірок: "aaaabbbcccc" -> 2
		TEST_METHOD(TestCount)
		{
			char str[] = "aaaabbbcccc";

			Assert::AreEqual(2, Count(str));
		}

		// Заміна четвірок: "aaaabbbcccc" -> "**bbb**"
		TEST_METHOD(TestChange)
		{
			char str[101] = "aaaabbbcccc";

			char* res = Change(str);

			Assert::AreEqual("**bbb**", str);   // змінений параметр
			Assert::AreEqual("**bbb**", res);   // результат функції
		}
	};
}
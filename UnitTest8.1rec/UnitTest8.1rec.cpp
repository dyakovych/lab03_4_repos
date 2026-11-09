#include "pch.h"
#include "CppUnitTest.h"
#pragma warning(disable : 4996)   // strcat, strcpy, strncat у підключеному коді
#include "../8.1rec/8.1rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab81RecTests
{
	TEST_CLASS(Lab81RecTests)
	{
	public:

		// Кількість четвірок: "aaaabbbcccc" -> 2
		TEST_METHOD(TestCount)
		{
			char str[] = "aaaabbbcccc";

			Assert::AreEqual(2, Count(str, 0));
		}

		// Заміна четвірок: "aaaabbbcccc" -> "**bbb**"
		TEST_METHOD(TestChange)
		{
			char str[] = "aaaabbbcccc";
			char dest[101];
			dest[0] = '\0';

			char* res = Change(dest, str, dest, 0);

			Assert::AreEqual("**bbb**", dest);  // вихідний рядок-параметр
			Assert::AreEqual("**bbb**", res);   // результат функції
		}
	};
}
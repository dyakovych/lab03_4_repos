// test.cpp
// unit-тест для функцій term() та calc() із завдання 9.1 (варіант 9)

#include <iostream>
#include <math.h>

// підключаємо модулі проєкту 9.1A
#include "../9.1A/globals.cpp"
#include "../9.1A/term.cpp"
#include "../9.1A/series.cpp"

using namespace std;

// перевірка рівності двох дійсних чисел із заданою точністю
bool check(const char* name, double expected, double actual, double eps)
{
    bool ok = fabs(expected - actual) <= eps;
    cout << (ok ? "PASSED: " : "FAILED: ") << name
        << " (expected " << expected << ", got " << actual << ")" << endl;
    return ok;
}

int main()
{
    int failed = 0;

    // коефіцієнт рекурентності: x = 2, a0 = 2, n = 1  =>  a1 = -8/3
    nsGlobals::x = 2;
    nsGlobals::n = 1;
    nsGlobals::a = 2;
    nsTerm::term();
    if (!check("term: x=2, n=1", -8.0 / 3.0, nsGlobals::a, 1e-12)) failed++;

    // сума ряду для x = 0.5
    nsGlobals::x = 0.5;
    nsGlobals::e = 0.00001;
    nsSeries::calc();
    if (!check("calc: x=0.5", atan(0.5), nsGlobals::s, 0.0001)) failed++;

    // сума ряду для x = -0.3
    nsGlobals::x = -0.3;
    nsGlobals::e = 0.00001;
    nsSeries::calc();
    if (!check("calc: x=-0.3", atan(-0.3), nsGlobals::s, 0.0001)) failed++;

    // x = 0: сума 0, один доданок
    nsGlobals::x = 0;
    nsGlobals::e = 0.001;
    nsSeries::calc();
    if (!check("calc: x=0, sum", 0.0, nsGlobals::s, 1e-12)) failed++;
    if (!check("calc: x=0, n", 1.0, nsGlobals::n, 0)) failed++;

    cout << endl << (failed == 0 ? "All tests passed." : "Some tests failed.") << endl;

    cin.get();
    return 0;
}
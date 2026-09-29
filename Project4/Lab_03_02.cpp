// Lab_03_2.cpp
// Дякович Іван
// Лабораторна робота № 3.2
// Розгалуження, задане формулою: функція з параметрами.
// Варіант 9

#include <iostream>
using namespace std;

int main()
{
    double a, b, c, x, F1, F2;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;

    cout << "x = ";
    cin >> x;

    // Скорочена форма
    if (a < 0 && x != 0)
        F1 = a * x * x + b * b * x;

    if (a > 0 && x == 0)
        F1 = x - a / (x - c);

    if (a == 0)
        F1 = 1 + x / c;

    // Повна форма
    if (a < 0 && x != 0)
        F2 = a * x * x + b * b * x;
    else if (a > 0 && x == 0)
        F2 = x - a / (x - c);
    else
        F2 = 1 + x / c;

    cout << "F1 = " << F1 << endl;
    cout << "F2 = " << F2 << endl;

    return 0;
}
// Lab_03_1.cpp
// Дякович Іван
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 9
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;

    cout << "x = ";
    cin >> x;

    // Скорочена форма
    if (x <= -0.1)
        y = 2 * pow(abs(x), 3) - 5 * cos(18 * x);

    if (x > -0.1 && x < 1.2)
        y = 2 * pow(abs(x), 3) - atan((x + 2) / 5);

    if (x >= 1.2)
        y = 2 * pow(abs(x), 3) - (1 / tan(x) + 18);

    cout << "1) y = " << y << endl;

    // Повна форма
    if (x <= -0.1)
        y = 2 * pow(abs(x), 3) - 5 * cos(18 * x);
    else if (x < 1.2)
        y = 2 * pow(abs(x), 3) - atan((x + 2) / 5);
    else
        y = 2 * pow(abs(x), 3) - (1 / tan(x) + 18);

    cout << "2) y = " << y << endl;

    return 0;
}
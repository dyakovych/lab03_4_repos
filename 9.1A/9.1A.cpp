// main91.cpp
// головний файл проекту – функція main

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

#include "term.h"
#include "series.h"
#include "globals.h"

using namespace std;

using namespace nsTerm;
using namespace nsSeries;
using namespace nsGlobals;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx  = "; cin >> dx;
    cout << "e   = "; cin >> e;
    cout << endl;

    string line(51, '-');           // горизонтальна лінія таблиці

    // заголовок та шапка таблиці
    cout << "Taylor series: arctg x" << endl;
    cout << line << endl;
    cout << "| " << setw(8) << "x"
        << " | " << setw(12) << "atan(x)"
        << " | " << setw(12) << "sum"
        << " | " << setw(6) << "n"
        << " |" << endl;
    cout << line << endl;

    x = x_p;
    while (x <= x_k) {
        calc();                     // виклик процедури обчислення суми

        cout << "| " << setw(8) << fixed << setprecision(3) << x
            << " | " << setw(12) << setprecision(6) << atan(x)
            << " | " << setw(12) << s
            << " | " << setw(6) << n
            << " |" << endl;

        x += dx;
    }
    cout << line << endl;

    cin.get(); cin.get();
    return 0;
}
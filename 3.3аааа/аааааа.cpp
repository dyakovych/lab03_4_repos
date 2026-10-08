#include <iostream>
using namespace std;

int main()
{
    double x; // вхідний аргумент
    double y; // результат обчислення

    cout << "x = "; cin >> x;

    if (x <= -7)
        y = 0;
    else if (x <= -3)
        y = x + 7;
    else if (x <= -2)
        y = 4;
    else if (x <= 2)
        y = x * x;
    else if (x <= 4)
        y = 8 - 2 * x;
    else
        y = 0;

    cout << "y = " << y << endl;

    cin.get();
    return 0;
}

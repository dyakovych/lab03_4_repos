#include <iostream>
using namespace std;

int main()
{
    double a, b, c, x;
    double F1 = 0, F2 = 0;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;

    cout << "x = ";
    cin >> x;

    // F1
    if (a < 0 && x != 0)
        F1 = a * x * x + b * b * x;
    else if (a > 0 && x == 0)
        F1 = x - a / (x - c);
    else
        F1 = 1 + x / c;

    // F2
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
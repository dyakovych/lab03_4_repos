#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x, xp, xk, dx, y;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "-----------------------------" << endl;
    cout << "|" << setw(8) << "x"
        << " |" << setw(12) << "y" << " |" << endl;
    cout << "-----------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        if (x <= -0.1)
            y = 2 * pow(abs(x), 3) - 5 * cos(18 * x);
        else if (x < 1.2)
            y = 2 * pow(abs(x), 3) - atan((x + 2) / 5);
        else
            y = 2 * pow(abs(x), 3) - (1 / tan(x) + 18);

        cout << "|" << setw(8) << setprecision(2) << x
            << " |" << setw(12) << setprecision(4) << y
            << " |" << endl;

        x += dx;
    }

    cout << "-----------------------------" << endl;

    return 0;
}
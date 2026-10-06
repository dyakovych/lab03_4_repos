#include <iostream>
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

    x = xp;

    while (x <= xk)
    {
        if (x < -7)
            y = 0;
        else if (x < -3)
            y = x + 7;
        else if (x < -2)
            y = 4;
        else if (x <= 2)
            y = x * x;
        else if (x <= 4)
            y = -2 * x + 8;
        else
            y = 0;

        cout << "x = " << x << "  y = " << y << endl;

        x = x + dx;
    }

    return 0;
}
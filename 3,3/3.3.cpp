#include <iostream>
using namespace std;

int main()
{
    double x, y;

    cout << "x = ";
    cin >> x;

    if (x <= -3)
        y = x + 7;
    else if (x <= -2)
        y = 4;
    else if (x <= -1)
        y = -3 * x - 2;
    else if (x <= 1)
        y = x * x;
    else if (x <= 2)
        y = 3 * x - 2;
    else
        y = -2 * x + 8;

    cout << "y = " << y << endl;

    return 0;
}
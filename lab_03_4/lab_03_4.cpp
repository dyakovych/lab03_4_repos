#include <iostream>
using namespace std;

int main()
{
    double x, y, R;

    cout << "R = ";
    cin >> R;

    cout << "x = ";
    cin >> x;

    cout << "y = ";
    cin >> y;

    if ((x * x + y * y <= R * R && x <= 0 && y <= 0) ||
        (x * x + y * y <= R * R && x >= 0 && y >= (x - 1) * (x - 1)))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
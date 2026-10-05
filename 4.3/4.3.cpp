#include <iostream>
#include <iomanip>
using namespace std;

double F(double a, double b, double c, double x)
{
    if (a < 0 && x != 0)
        return a * x * x + b * b * x;

    if (a > 0 && x == 0)
        return x - a / (x - c);

    return 1 + x / c;
}

int main()
{
    double a, b, c;
    double x_poch, x_kin, dx;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "c = ";
    cin >> c;

    cout << "X_poch = ";
    cin >> x_poch;

    cout << "X_kin = ";
    cin >> x_kin;

    cout << "dX = ";
    cin >> dx;

    cout << "\n";
    cout << setw(10) << "x"
        << setw(15) << "F(x)" << endl;

    while (x_poch <= x_kin)
    {
        cout << setw(10) << x_poch
            << setw(15) << F(a, b, c, x_poch)
            << endl;

        x_poch += dx;
    }

    return 0;
}
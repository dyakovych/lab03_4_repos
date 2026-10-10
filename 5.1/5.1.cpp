// Lab 5_1
#include <iostream>
using namespace std;

double h(const double x, const double y);

int main()
{
    double s, t;

    cout << "s = ";
    cin >> s;

    cout << "t = ";
    cin >> t;

    double c = h(1, s + t) + h(s, s - t) - h(t, s * s + t * t);

    cout << "c = " << c << endl;

    return 0;
}

double h(const double x, const double y)
{
    return (x * x + y * y) / (1 + x * x + x * x * y * y);
}

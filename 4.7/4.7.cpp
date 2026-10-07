#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp, xk, dx, eps, x, a, S, R;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed << setprecision(5);
    cout << "-------------------------------------------" << endl;
    cout << "|    x    |  atan(x)  |     S     |   n   |" << endl;
    cout << "-------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = x;      // перший доданок
        S = a;
        do
        {
            n++;
            R = -x * x * (2 * n - 1) / (2 * n + 1);   // коефіцієнт рекурентності
            a *= R;
            S += a;
        } while (fabs(a) >= eps);

        cout << "|" << setw(8) << x
            << " |" << setw(10) << atan(x)
            << " |" << setw(10) << S
            << " |" << setw(6) << n << " |" << endl;
        x += dx;
    }
    cout << "-------------------------------------------" << endl;

    return 0;
}
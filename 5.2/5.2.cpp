// Лабораторна робота № 5.2

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << "   |"
        << setw(11) << "atan(x)" << "   |"
        << setw(11) << "S" << "   |"
        << setw(6) << "n" << "   |"
        << endl;
    cout << "-----------------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);

        cout << "|" << setw(8) << setprecision(2) << x << "   |"
            << setw(11) << setprecision(5) << atan(x) << "   |"
            << setw(11) << setprecision(5) << s << "   |"
            << setw(6) << n << "   |"
            << endl;
        x += dx;
    }
    cout << "-----------------------------------------------------" << endl;

    return 0;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = x;         // перший доданок (n = 0): x
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R = -x * x * (2 * n - 1) / (2 * n + 1);   // коефіцієнт рекурентності
    a *= R;
    return a;
}

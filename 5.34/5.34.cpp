#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double p(const double x);

int main()
{
    double qp, qk, z;
    int n;

    cout << "qp = "; cin >> qp;
    cout << "qk = "; cin >> qk;
    cout << "n = "; cin >> n;

    double dq = (qk - qp) / n;

    double q = qp;

    cout << fixed << setprecision(6);
    cout << "------------------------------" << endl;
    cout << "|     Table of z(q) values   |" << endl;
    cout << "------------------------------" << endl;
    cout << "|" << setw(12) << "q" << " |" << setw(13) << "z" << " |" << endl;
    cout << "------------------------------" << endl;

    while (q <= qk + dq / 2)
    {
        z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(1));
        cout << "|" << setw(12) << q << " |" << setw(13) << z << " |" << endl;
        q += dq;
    }
    cout << "------------------------------" << endl;

    return 0;
}

double p(const double x)
{
    if (abs(x) >= 1)
        return (sin(x) + cos(x)) / (sin(x) * sin(x) + exp(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;
        S = a;
        do
        {
            j++;
            double R = -x * x / ((2 * j - 1) * 2 * j);
            a *= R;
            S += a;
        } while (j < 4);
        return S / cos(x);
    }
}
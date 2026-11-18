#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

// Спосіб 1: за рекурентним рівнянням a(n+2) = 4*a(n) + 8*n
long long byRecurrence(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    long long prev2 = 1, prev1 = 0, cur = 0;
    for (int i = 2; i <= n; i++) {
        cur = 4 * prev2 + 8LL * (i - 2);
        prev2 = prev1;
        prev1 = cur;
    }
    return cur;
}

// Спосіб 2: за формулою a(n) = (45*2^n + 5*(-2)^n - 48n - 32) / 18
long long byFormula(int n) {
    long long p = 1LL << n;               // 2^n
    long long q = (n % 2 == 0) ? p : -p;  // (-2)^n
    return (45 * p + 5 * q - 48LL * n - 32) / 18;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int in = 2;
    cout << "За рівнянням: a" << in << " = " << byRecurrence(in) << endl;
    cout << "За формулою:  a" << in << " = " << byFormula(in) << endl;

    cout << "\n n | за рівнянням | за формулою\n";
    for (int i = 0; i <= 10; i++)
        cout << setw(2) << i << " | " << setw(12) << byRecurrence(i)
        << " | " << setw(11) << byFormula(i) << endl;
    return 0;
}
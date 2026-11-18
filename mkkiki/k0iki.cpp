#include <iostream>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

long long power(long long base, int e) {
    long long result = 1;
    for (int i = 0; i < e; i++) result *= base;
    return result;
}

int main() {
    const int n = 8;                      // степінь многочлена
    const int m = 4;                      // кількість доданків
    long long coeffs[m] = { -3, 2, -3, 2 }; // числа перед змінними
    int powers[m] = { 3, 4, 3, 2 };   // степені змінних у доданках
    int target[m] = { 6, 12, 6, 2 };  // степені в шуканому члені

    int k[m];
    int s = 0;
    for (int i = 0; i < m; i++) {
        // якщо k не ціле, то такого члена немає
        if (target[i] % powers[i] != 0) {
            cout << "C = 0" << endl;
            return 0;
        }
        k[i] = target[i] / powers[i];
        cout << "k" << i + 1 << " = " << k[i] << endl;
        s += k[i];
    }
    // якщо сума не дорівнює степеню, то такого члена немає
    if (s != n) {
        cout << "C = 0" << endl;
        return 0;
    }

    long long numerator = factorial(n);#include <iostream>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

long long power(long long base, int e) {
    long long result = 1;
    for (int i = 0; i < e; i++) result *= base;
    return result;
}

int main() {
    const int n = 8;                      // степінь многочлена
    const int m = 4;                      // кількість доданків
    long long coeffs[m] = { -3, 2, -3, 2 }; // числа перед змінними
    int powers[m] = { 3, 4, 3, 2 };   // степені змінних у доданках
    int target[m] = { 6, 12, 6, 2 };  // степені в шуканому члені

    int k[m];
    int s = 0;
    for (int i = 0; i < m; i++) {
        // якщо k не ціле, то такого члена немає
        if (target[i] % powers[i] != 0) {
            cout << "C = 0" << endl;
            return 0;
        }
        k[i] = target[i] / powers[i];
        cout << "k" << i + 1 << " = " << k[i] << endl;
        s += k[i];
    }
    // якщо сума не дорівнює степеню, то такого члена немає
    if (s != n) {
        cout << "C = 0" << endl;
        return 0;
    }

    long long numerator = factorial(n);
    long long denominator = 1;
    long long rightPart = 1;
    for (int i = 0; i < m; i++) {
        denominator *= factorial(k[i]);
        rightPart *= power(coeffs[i], k[i]);
    }
    long long C = numerator / denominator * rightPart;
    cout << "C = " << C << endl;
    return 0;
}

    long long denominator = 1;
    long long rightPart = 1;
    for (int i = 0; i < m; i++) {
        denominator *= factorial(k[i]);
        rightPart *= power(coeffs[i], k[i]);
    }
    long long C = numerator / denominator * rightPart;
    cout << "C = " << C << endl;
    return 0;
}

// Лабораторна робота № 5.4, варіант 9

#include <iostream>
#include <cmath>

using namespace std;

// доданок суми
double f(const int i)
{
    return (sin(10.0 * i) + cos(10.0 / i)) / sqrt(1.0 * i);
}

// 0) ітераційний спосіб (для контролю)
double S0(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += f(i);
    return s;
}

// 1) рекурсивний спуск, параметр зростає
double S1(const int N, const int i)
{
    if (i > N)
        return 0;
    return f(i) + S1(N, i + 1);
}

// 2) рекурсивний спуск, параметр спадає
double S2(const int K, const int i)
{
    if (i < K)
        return 0;
    return f(i) + S2(K, i - 1);
}

// 3) рекурсивний підйом, параметр зростає
double S3(const int N, const int i, double t)
{
    t = t + f(i);
    if (i >= N)
        return t;
    return S3(N, i + 1, t);
}

// 4) рекурсивний підйом, параметр спадає
double S4(const int K, const int i, double t)
{
    t = t + f(i);
    if (i <= K)
        return t;
    return S4(K, i - 1, t);
}

int main()
{
    const int K = 1, N = 15;

    cout << "(iter)        S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(N, K) << endl;
    cout << "(rec up --)   S2 = " << S2(K, N) << endl;
    cout << "(rec down ++) S3 = " << S3(N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, 0) << endl;

    return 0;
}
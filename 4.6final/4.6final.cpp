#include <iostream>

using namespace std;

int main()
{
    double S, P;
    int j, i;

    // 1) while
    S = 0;
    j = 2;
    while (j <= 20)
    {
        P = 1;
        i = j * j;
        while (i <= 400)
        {
            P *= i;
            i++;
        }
        S += j / (j * j + P);
        j++;
    }
    cout << S << endl;

    // 2) do...while
    S = 0;
    j = 2;
    do
    {
        P = 1;
        i = j * j;
        do
        {
            P *= i;
            i++;
        } while (i <= 400);
        S += j / (j * j + P);
        j++;
    } while (j <= 20);
    cout << S << endl;

    // 3) for (збільшення)
    S = 0;
    for (j = 2; j <= 20; j++)
    {
        P = 1;
        for (i = j * j; i <= 400; i++)
        {
            P *= i;
        }
        S += j / (j * j + P);
    }
    cout << S << endl;

    // 4) for (зменшення)
    S = 0;
    for (j = 20; j >= 2; j--)
    {
        P = 1;
        for (i = 400; i >= j * j; i--)
        {
            P *= i;
        }
        S += j / (j * j + P);
    }
    cout << S << endl;

    return 0;
}
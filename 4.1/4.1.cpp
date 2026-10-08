#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int S;
    int i;

    // 1. while
    S = 0;
    i = 1;

    while (i <= 15)
    {
        S += (sin(10 * i) + cos(10.0 / i)) / sqrt(i);
        i++;
    }

    cout << "while: " << S << endl;

    // 2. do...while
    S = 0;
    i = 1;

    do
    {
        S += (sin(10 * i) + cos(10.0 / i)) / sqrt(i);
        i++;
    } while (i <= 15);

    cout << "do while: " << S << endl;

    // 3. for, i++
    S = 0;

    for (i = 1; i <= 15; i++)
    {
        S += (sin(10 * i) + cos(10.0 / i)) / sqrt(i);
    }

    cout << "for i++: " << S << endl;

    // 4. for, i--
    S = 0;

    for (i = 15; i >= 1; i--)
    {
        S += (sin(10 * i) + cos(10.0 / i)) / sqrt(i);
    }

    cout << "for i--: " << S << endl;

    return 0;
}
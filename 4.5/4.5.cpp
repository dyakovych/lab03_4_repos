#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    double x, y, R;

    cout << "R = ";
    cin >> R;

    // 10 точок вводимо вручну
    for (int i = 1; i <= 10; i++)
    {
        cout << "x = ";
        cin >> x;

        cout << "y = ";
        cin >> y;

        if ((x <= 0 && y <= 0 && x * x + y * y <= R * R) ||
            (y >= (x - 1) * (x - 1) && x * x + y * y <= R * R))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    // 10 точок генеруємо випадково
    srand(time(0));

    for (int i = 1; i <= 10; i++)
    {
        x = -R + 2 * R * rand() / RAND_MAX;
        y = -R + 2 * R * rand() / RAND_MAX;

        if ((x <= 0 && y <= 0 && x * x + y * y <= R * R) ||
            (y >= (x - 1) * (x - 1) && x * x + y * y <= R * R))
            cout << x << " " << y << " yes\n";
        else
            cout << x << " " << y << " no\n";
    }

    return 0;
}
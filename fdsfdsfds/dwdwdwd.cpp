#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int N = 7, INF = 1000000;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const char name[N] = { 'a','b','c','d','e','f','g' };
    int d[N][N], nxt[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            d[i][j] = (i == j) ? 0 : INF;
            nxt[i][j] = -1;
        }

    // дуги графа варіанта 9: {звідки, куди, вага}
    int E[][3] = { {0,1,21},{0,3,1},{1,2,2},{1,4,7},{2,4,3},{3,1,16},{3,5,10},
                   {4,3,9},{4,6,6},{5,4,30},{6,5,12} };
    for (auto& e : E) {
        d[e[0]][e[1]] = e[2];
        nxt[e[0]][e[1]] = e[1];
    }

    // алгоритм Флойда
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    cout << "Матриця найкоротших відстаней (алгоритм Флойда):\n    ";
    for (int j = 0; j < N; j++) cout << setw(4) << name[j];
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << setw(4) << name[i];
        for (int j = 0; j < N; j++) {
            if (d[i][j] >= INF) cout << setw(4) << "inf";
            else cout << setw(4) << d[i][j];
        }
        cout << "\n";
    }

    int s = 0, t = 6;
    cout << "\nНайкоротша відстань a -> g = " << d[s][t] << "\nШлях: ";
    for (int v = s; v != t; v = nxt[v][t]) cout << name[v] << " -> ";
    cout << name[t] << "\n";

    system("pause");
    return 0;
}
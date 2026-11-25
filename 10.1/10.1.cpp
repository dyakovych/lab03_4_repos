// Лабораторна робота № 10.1
// Послідовний пошук в масиві структур. Варіант 9. Рівень A
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>               // забезпечення відображення кирилиці
using namespace std;

enum Spec { KN, INF, ME, FI, TN };

string specStr[] = { "Комп'ютерні науки", "Інформатика",
                     "Математика та економіка", "Фізика та інформатика",
                     "Трудове навчання" };

string predmetStr[] = { "фізика", "математика", "інформатика" };

struct Student
{
    string   prizv;
    unsigned kurs;
    Spec     spec;
    int      fizyka;
    int      matematyka;
    int      informatyka;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void CountFives(Student* p, const int N, int k[]);
int  CountPhysMath5(Student* p, const int N);
string Pad(const string& s, const int w);

int main()
{                              // забезпечення відображення кирилиці (UTF-8):
    SetConsoleCP(65001);       // встановлення сторінки UTF-8 в потік вводу
    SetConsoleOutputCP(65001); // встановлення сторінки UTF-8 в потік виводу

    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    int k[3];                      // кількість оцінок "5" з кожного предмету
    CountFives(p, N, k);
    cout << "Кількість оцінок \"відмінно\" з кожного предмету:" << endl;
    for (int i = 0; i < 3; i++)
        cout << Pad(predmetStr[i], 12) << ": " << k[i] << endl;

    cout << "Кількість студентів, які отримали з фізики і математики оцінки \"5\": "
        << CountPhysMath5(p, N) << endl;

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int kurs, spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

        cout << "     прізвище: "; getline(cin, p[i].prizv);
        cout << "     курс: "; cin >> kurs;
        p[i].kurs = kurs;
        cout << "     спеціальність (0 - Комп'ютерні науки, 1 - Інформатика,"
            << endl
            << "                    2 - Математика та економіка, 3 - Фізика та інформатика,"
            << endl
            << "                    4 - Трудове навчання): ";
        cin >> spec;
        p[i].spec = (Spec)spec;
        cout << "     оцінка з фізики: "; cin >> p[i].fizyka;
        cout << "     оцінка з математики: "; cin >> p[i].matematyka;
        cout << "     оцінка з інформатики: "; cin >> p[i].informatyka;
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << string(94, '=') << endl;
    cout << "| " << Pad("№", 3)
        << " | " << Pad("Прізвище", 13)
        << " | " << Pad("Курс", 4)
        << " | " << Pad("Спеціальність", 24)
        << " | " << Pad("Фізика", 6)
        << " | " << Pad("Математика", 11)
        << " | " << Pad("Інформатика", 11)
        << " |" << endl;
    cout << string(94, '-') << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << Pad(p[i].prizv, 13)
            << " | " << setw(4) << right << p[i].kurs
            << " | " << Pad(specStr[p[i].spec], 24)
            << " | " << setw(6) << right << p[i].fizyka
            << " | " << setw(11) << right << p[i].matematyka
            << " | " << setw(11) << right << p[i].informatyka
            << " |" << endl;
    }
    cout << string(94, '=') << endl;
    cout << endl;
}

// обчислює кількість оцінок "5" з кожного предмету (результат – у масиві k)
void CountFives(Student* p, const int N, int k[])
{
    for (int j = 0; j < 3; j++)
        k[j] = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5)
            k[0]++;
        if (p[i].matematyka == 5)
            k[1]++;
        if (p[i].informatyka == 5)
            k[2]++;
    }
}

// обчислює кількість студентів, які отримали з фізики і математики "5"
int CountPhysMath5(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (p[i].fizyka == 5 && p[i].matematyka == 5)
            k++;
    return k;
}

// доповнює рядок s пробілами справа до w символів
// (в UTF-8 літера займає 2 байти, тому рахуємо символи, а не байти)
string Pad(const string& s, const int w)
{
    int len = 0;
    for (size_t i = 0; i < s.length(); i++)
        if ((s[i] & 0xC0) != 0x80)   // не рахуємо байти-продовження
            len++;
    string r = s;
    for (int i = len; i < w; i++)
        r += ' ';
    return r;
}
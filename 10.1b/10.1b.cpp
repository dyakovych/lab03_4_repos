// Лабораторна робота № 10.1
// Послідовний пошук в масиві структур. Варіант 9. Рівень B
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>               // забезпечення відображення кирилиці
using namespace std;

enum Spec { KN, INF, ME, FI, TN };

string specStr[] = { "Комп'ютерні науки", "Інформатика",
                     "Математика та економіка", "Фізика та інформатика",
                     "Трудове навчання" };

string predmetStr[] = { "фізика", "математика", "програмування",
                        "чисельні методи", "педагогіка" };

struct Student
{
    string   prizv;
    unsigned kurs;
    Spec     spec;
    int      fizyka;
    int      matematyka;
    union                          // третя оцінка залежить від спеціальності
    {
        int prog;                  // КН
        int chys_met;              // Інформатика
        int ped;                   // інші спеціальності
    };
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

    int k[5];                      // кількість оцінок "5" з кожного предмету
    CountFives(p, N, k);
    cout << "Кількість оцінок \"відмінно\" з кожного предмету:" << endl;
    for (int i = 0; i < 5; i++)
        cout << Pad(predmetStr[i], 16) << ": " << k[i] << endl;

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
        do
        {
            cout << "     спеціальність (0 - Комп'ютерні науки, 1 - Інформатика,"
                << endl
                << "                    2 - Математика та економіка, 3 - Фізика та інформатика,"
                << endl
                << "                    4 - Трудове навчання): ";
            cin >> spec;
        } while (spec < 0 || spec > 4);   // повторюємо, поки не введено 0..4
        p[i].spec = (Spec)spec;
        cout << "     оцінка з фізики: "; cin >> p[i].fizyka;
        cout << "     оцінка з математики: "; cin >> p[i].matematyka;
        switch (p[i].spec)
        {
        case KN:
            cout << "     оцінка з програмування: "; cin >> p[i].prog;
            break;
        case INF:
            cout << "     оцінка з чисельних методів: "; cin >> p[i].chys_met;
            break;
        case ME:
        case FI:
        case TN:
            cout << "     оцінка з педагогіки: "; cin >> p[i].ped;
            break;
        }
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << string(106, '=') << endl;
    cout << "| " << Pad("№", 3)
        << " | " << Pad("Прізвище", 12)
        << " | " << Pad("Курс", 4)
        << " | " << Pad("Спеціальність", 23)
        << " | " << Pad("Фізика", 6)
        << " | " << Pad("Матем.", 6)
        << " | " << Pad("Програм.", 8)
        << " | " << Pad("Чис.мет.", 8)
        << " | " << Pad("Педагог.", 8)
        << " |" << endl;
    cout << string(106, '-') << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << Pad(p[i].prizv, 12)
            << " | " << setw(4) << right << p[i].kurs
            << " | " << Pad(specStr[p[i].spec], 23)
            << " | " << setw(6) << right << p[i].fizyka
            << " | " << setw(6) << right << p[i].matematyka
            << " | ";
        switch (p[i].spec)
        {
        case KN:
            cout << setw(8) << right << p[i].prog
                << " | " << setw(8) << " "
                << " | " << setw(8) << " " << " |" << endl;
            break;
        case INF:
            cout << setw(8) << " "
                << " | " << setw(8) << right << p[i].chys_met
                << " | " << setw(8) << " " << " |" << endl;
            break;
        case ME:
        case FI:
        case TN:
            cout << setw(8) << " "
                << " | " << setw(8) << " "
                << " | " << setw(8) << right << p[i].ped << " |" << endl;
            break;
        }
    }
    cout << string(106, '=') << endl;
    cout << endl;
}

// обчислює кількість оцінок "5" з кожного предмету (результат – у масиві k)
void CountFives(Student* p, const int N, int k[])
{
    for (int j = 0; j < 5; j++)
        k[j] = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fizyka == 5)
            k[0]++;
        if (p[i].matematyka == 5)
            k[1]++;
        switch (p[i].spec)
        {
        case KN:
            if (p[i].prog == 5)
                k[2]++;
            break;
        case INF:
            if (p[i].chys_met == 5)
                k[3]++;
            break;
        case ME:
        case FI:
        case TN:
            if (p[i].ped == 5)
                k[4]++;
            break;
        }
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
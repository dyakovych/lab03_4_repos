// Lab_10_2_B.cpp
// <прізвище та ім'я студента>
// Лабораторна робота № 10.2
// Впорядкування та бінарний пошук в масиві структур з об'єднаннями
// Варіант 9, рівень В

#define NOMINMAX
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <cstdio>
#include <io.h>
#include <fcntl.h>      // для _setmode (Unicode-консоль)
#include <Windows.h>    // для MultiByteToWideChar
using namespace std;

wstring U(const char* s)
{ // перетворює рядок із тексту програми в Unicode незалежно від кодування файлу
  // (залежно від налаштувань Visual Studio літера "І" займає 2 байти в UTF-8 або 1 байт у 1251)
    const char test[] = "І";
    const UINT cp = (sizeof(test) == 3) ? CP_UTF8 : CP_ACP;
    int n = MultiByteToWideChar(cp, 0, s, -1, nullptr, 0);
    if (n <= 0)
        return L"";
    wstring w(n, L'\0');
    if (MultiByteToWideChar(cp, 0, s, -1, &w[0], n) == 0)
        return L"";
    w.resize(n - 1);
    return w;
}

// значення переліку йдуть в алфавітному порядку назв спеціальностей
enum Specialnist { INFORMATYKA, KOMP_NAUKY, MAT_EKONOMIKA, TRUDOVE_NAVCHANNIA, FIZ_INFORMATYKA };

struct Student
{
    wstring      prizv;
    int         kurs = 0;
    Specialnist spec = INFORMATYKA;
    int         fizyka = 0;
    int         matematyka = 0;
    union
    {
        int prohramuvannia = 0; // Комп'ютерні науки
        int chyselni_metody;    // Інформатика
        int pedahohika;         // всі інші спеціальності
    };
};

double InputNumber(const wstring prompt, const double minV, const double maxV);
wstring SpecName(const Specialnist spec);
double Average(const Student& s);
int    Compare(const double a1, const Specialnist s1, const wstring& p1,
    const double a2, const Specialnist s2, const wstring& p2);
void Create(Student* p, const int N);
void PrintHeader();
void PrintRow(const Student& s, const int number);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int  BinSearch(Student* p, const int N, const wstring prizv, const Specialnist spec, const double avg);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);

int main()
{
    (void)_setmode(_fileno(stdin), _O_U16TEXT);   // Unicode-введення (кирилиця)
    (void)_setmode(_fileno(stdout), _O_U16TEXT);  // Unicode-виведення (кирилиця)

    int N = (int)InputNumber(U("Введіть кількість студентів N: "), 1, 1000);
    Student* p = new Student[N];
    bool isSorted = false;     // чи масив фізично впорядкований

    wstring prizv;
    int* I;
    int found, menuItem;
    do {
        wcout << endl << endl << endl;
        wcout << U("Виберіть дію:") << endl << endl;
        wcout << U(" [1] - введення даних з клавіатури") << endl;
        wcout << U(" [2] - вивід даних на екран") << endl;
        wcout << U(" [3] - фізичне впорядкування даних") << endl;
        wcout << U(" [4] - індексне впорядкування та вивід даних") << endl;
        wcout << U(" [5] - бінарний пошук студента за прізвищем,") << endl;
        wcout << U("        спеціальністю та середнім балом") << endl << endl;
        wcout << U(" [0] - вихід та завершення роботи програми") << endl << endl;
        menuItem = (int)InputNumber(U("Введіть значення: "), 0, 5);
        wcout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            isSorted = false;
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            isSorted = true;
            break;
        case 4:
            I = IndexSort(p, N);
            PrintIndexSorted(p, I, N);
            delete[] I;
            break;
        case 5:
            if (!isSorted)
            {
                wcout << U("Спочатку впорядкуйте масив фізично (пункт 3)!") << endl;
                break;
            }
            do {
                wcout << U("Введіть прізвище: "); getline(wcin, prizv);
            } while (prizv.empty());
            Specialnist spec = (Specialnist)InputNumber(
                U("Введіть спеціальність (0 - Інформатика, 1 - Комп'ютерні науки,\n"
                    "   2 - Математика та економіка, 3 - Трудове навчання,\n"
                    "   4 - Фізика та інформатика): "), 0, 4);
            double avg = InputNumber(U("Введіть середній бал: "), 0, 100);

            found = BinSearch(p, N, prizv, spec, avg);
            if (found != -1)
            {
                wcout << U("Студента знайдено, його номер у масиві: ") << found + 1 << endl;
                PrintHeader();
                PrintRow(p[found], found + 1);
                wcout << wstring(128, L'=') << endl;
            }
            else
                wcout << U("Такого студента немає.") << endl;
            break;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}

double InputNumber(const wstring prompt, const double minV, const double maxV)
{ // вводить число з перевіркою на коректність та на належність діапазону
    double x;
    while (true)
    {
        wcout << prompt;
        if (wcin >> x && x >= minV && x <= maxV)
        {
            wcin.ignore((numeric_limits<streamsize>::max)(), L'\n');
            return x;
        }
        wcin.clear();
        wcin.ignore((numeric_limits<streamsize>::max)(), L'\n');
        wcout << U("Помилка! Слід ввести число від ") << minV << U(" до ") << maxV << U(".") << endl;
    }
}

wstring SpecName(const Specialnist spec)
{
    wstring names[] = { U("Інформатика"), U("Комп'ютерні науки"), U("Математика та економіка"),
                       U("Трудове навчання"), U("Фізика та інформатика") };
    return names[spec];
}

double Average(const Student& s)
{
    int third;                  // третя оцінка залежить від спеціальності
    switch (s.spec)
    {
    case KOMP_NAUKY: third = s.prohramuvannia;  break;
    case INFORMATYKA: third = s.chyselni_metody; break;
    default:          third = s.pedahohika;      break;
    }
    return (s.fizyka + s.matematyka + third) / 3.0;
}

int Compare(const double a1, const Specialnist s1, const wstring& p1,
    const double a2, const Specialnist s2, const wstring& p2)
{ // порівнює ключі (середній бал, спеціальність, прізвище): -1, 0 або 1
    if (fabs(a1 - a2) > 0.005) return a1 < a2 ? -1 : 1;
    if (s1 != s2)              return s1 < s2 ? -1 : 1;
    if (p1 != p2)              return p1 < p2 ? -1 : 1;
    return 0;
}

void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        wcout << U("Студент № ") << i + 1 << U(":") << endl;
        do {
            wcout << U("    прізвище: "); getline(wcin, p[i].prizv);
        } while (p[i].prizv.empty());
        p[i].kurs = (int)InputNumber(U("    курс (1-6): "), 1, 6);
        p[i].spec = (Specialnist)InputNumber(
            U("    спеціальність (0 - Інформатика, 1 - Комп'ютерні науки,\n"
                "       2 - Математика та економіка, 3 - Трудове навчання,\n"
                "       4 - Фізика та інформатика): "), 0, 4);
        p[i].fizyka = (int)InputNumber(U("    оцінка з фізики: "), 0, 100);
        p[i].matematyka = (int)InputNumber(U("    оцінка з математики: "), 0, 100);
        switch (p[i].spec)
        {
        case KOMP_NAUKY:
            p[i].prohramuvannia = (int)InputNumber(U("    оцінка з програмування: "), 0, 100);
            break;
        case INFORMATYKA:
            p[i].chyselni_metody = (int)InputNumber(U("    оцінка з чисельних методів: "), 0, 100);
            break;
        default:
            p[i].pedahohika = (int)InputNumber(U("    оцінка з педагогіки: "), 0, 100);
        }
        wcout << endl;
    }
}

void PrintHeader()
{
    wcout << wstring(128, L'=') << endl;
    wcout << U("| ") << setw(3) << right << U("№")
        << U(" | ") << setw(15) << left << U("Прізвище")
        << U(" | ") << setw(4) << right << U("Курс")
        << U(" | ") << setw(24) << left << U("Спеціальність")
        << U(" | ") << setw(6) << right << U("Фізика")
        << U(" | ") << setw(10) << right << U("Математика")
        << U(" | ") << setw(13) << right << U("Програмування")
        << U(" | ") << setw(15) << right << U("Чисельні методи")
        << U(" | ") << setw(10) << right << U("Педагогіка") << U(" |") << endl;
    wcout << wstring(128, L'-') << endl;
}

void PrintRow(const Student& s, const int number)
{
    wcout << U("| ") << setw(3) << right << number
        << U(" | ") << setw(15) << left << s.prizv
        << U(" | ") << setw(4) << right << s.kurs
        << U(" | ") << setw(24) << left << SpecName(s.spec)
        << U(" | ") << setw(6) << right << s.fizyka
        << U(" | ") << setw(10) << right << s.matematyka << U(" | ") << setw(13) << right;
    if (s.spec == KOMP_NAUKY) wcout << s.prohramuvannia; else wcout << U("");
    wcout << U(" | ") << setw(15) << right;
    if (s.spec == INFORMATYKA) wcout << s.chyselni_metody; else wcout << U("");
    wcout << U(" | ") << setw(10) << right;
    if (s.spec != KOMP_NAUKY && s.spec != INFORMATYKA) wcout << s.pedahohika; else wcout << U("");
    wcout << U(" |") << endl;
}

void Print(Student* p, const int N)
{
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[i], i + 1);
    wcout << wstring(128, L'=') << endl << endl;
}

void Sort(Student* p, const int N)
{ // фізичне впорядкування: середній бал, спеціальність, прізвище
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)        // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (Compare(Average(p[i1]), p[i1].spec, p[i1].prizv,
                Average(p[i1 + 1]), p[i1 + 1].spec, p[i1 + 1].prizv) > 0)
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

int BinSearch(Student* p, const int N, const wstring prizv, const Specialnist spec, const double avg)
{ // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
    int L = 0, R = N - 1, m, c;
    while (L <= R)
    {
        m = (L + R) / 2;
        c = Compare(Average(p[m]), p[m].spec, p[m].prizv, avg, spec, prizv);
        if (c == 0) return m;
        if (c < 0) L = m + 1;
        else       R = m - 1;
    }
    return -1;
}

int* IndexSort(Student* p, const int N)
{ // використовуємо метод вставки для формування індексного масиву
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    int i, j, value;
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && Compare(Average(p[I[j]]), p[I[j]].spec, p[I[j]].prizv,
                Average(p[value]), p[value].spec, p[value].prizv) > 0;
            j--)
            I[j + 1] = I[j];
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{ // як Print(), але доступ до елементів - через індексний масив I
    PrintHeader();
    for (int i = 0; i < N; i++)
        PrintRow(p[I[i]], i + 1);
    wcout << wstring(128, L'=') << endl << endl;
}
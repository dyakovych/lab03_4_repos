// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1.   Вияснити, чи є серед цих символів четвірка сусідніх однакових символів
//      та обчислити кількість таких четвірок.
// 2.   Замінити кожну четвірку сусідніх однакових символів парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str, int i)
{
    if (strlen(str) < 4)
        return 0;

    if (i + 3 < (int)strlen(str))
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
            return 1 + Count(str, i + 4);
        else
            return     Count(str, i + 1);
    else
        return 0;
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (i + 3 < (int)strlen(str))
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
        {
            strcat(t, "**");
            return Change(dest, str, t + 2, i + 4);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        strcpy(t, str + i);
        return dest;
    }
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str, 0) << " groups of 4 equal symbols" << endl;

    char* dest1 = new char[101];
    dest1[0] = '\0';

    char* dest2;

    dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    return 0;
}
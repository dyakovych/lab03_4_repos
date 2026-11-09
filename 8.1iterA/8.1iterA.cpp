// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1.   Вияснити, чи є серед цих символів четвірка сусідніх однакових символів
//      та обчислити кількість таких четвірок.
// 2.   Замінити кожну четвірку сусідніх однакових символів парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str)
{
    size_t len = strlen(str);

    if (len < 4)
        return 0;

    int k = 0;
    size_t i = 0;
    while (i + 3 < len)
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
        {
            k++;
            i += 4;
        }
        else
            i++;
    }
    return k;
}

char* Change(char* str)
{
    size_t len = strlen(str);

    if (len < 4)
        return str;

    char* tmp = new char[len + 1];
    char* t = tmp;

    tmp[0] = '\0';

    size_t i = 0;

    while (i + 3 < len)
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
        {
            strcat(t, "**");
            t += 2;
            i += 4;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    while (str[i] != 0)
    {
        *t++ = str[i++];
        *t = '\0';
    }

    strcpy(str, tmp);

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 4 equal symbols" << endl;

    char* dest = new char[101];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
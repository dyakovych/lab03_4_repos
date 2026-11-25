/*
lab_9_2.
Обчислити значення w залежно від z, використовуючи макроси
max, min, піднесення до степеня, виведення результатів.
За допомогою директив умовної компіляції вибрати гілку обчислення.

w = max^2(x*y^3, x+z), якщо z > 5
w = min(x - y*z, x*y + z), якщо z <= 5
*/

#define _CRT_SECURE_NO_WARNINGS   // дозволяє scanf у Visual Studio

#include <stdio.h>
#include <conio.h>

#define Z 3                        // значення z (змінюється в коді)

#define SQR(x) ((x)*(x))           // квадрат числа
#define CUBE(x) ((x)*(x)*(x))      // куб числа
#define MAX(a,b) (((a)>(b))?(a):(b))   // максимум з двох чисел
#define MIN(a,b) (((a)<(b))?(a):(b))   // мінімум з двох чисел

// виведення повідомлення та значення дійсного числа
#define PRINTR(w) puts("result :"); \
                  printf(#w "=%f\n", (double)(w))

int main()
{
    double x, y, w;     // змінні для розрахунків
    char ch;            // відповідь, чи продовжувати виконання програми

    puts("Lab 9.2. Using macros and preprocessing directives");
    printf("z = %d\n", Z);

    do
    {
        puts("Input x and y");
        scanf("%lf", &x);
        scanf("%lf", &y);

#if Z>5         // якщо z > 5, компілюється ця гілка
        w = SQR(MAX(x * CUBE(y), x + Z));
#else           // інакше (z <= 5) – ця гілка
        w = MIN(x - y * Z, x * y + Z);
#endif          // завершення блоку умовної компіляції

        PRINTR(w);      // макрос виведення результату

        puts("Repeat? y/n");
        ch = _getch();
    } while (ch == 'y');

    return 0;
}
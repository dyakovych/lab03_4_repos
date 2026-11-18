// sum.cpp
// файл реалізації функції
#include <math.h>

#include "dod.h"
#include "sum.h"
#include "vars.h"    // підключили зовнішні оголошення змінних

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    n = 0;
    a = x;          // перший доданок
    s = a;
    do {
        n++;
        dod();      // виклик процедури обчислення доданку
        s += a;
    } while (fabs(a) > e);
}
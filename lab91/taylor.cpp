// taylor.cpp
// файл реалізації функції обчислення суми ряду
#include <math.h>

#include "nextterm.h"
#include "taylor.h"
#include "params.h"

using namespace nsNext;
using namespace nsParams;

void nsTaylor::calcSum() {
    n = 0;
    a = x;              // перший доданок
    s = a;
    do {
        n++;
        nextTerm();     // виклик процедури обчислення доданку
        s += a;
    } while (fabs(a) > e);
}
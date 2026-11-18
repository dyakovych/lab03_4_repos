// series.cpp
// файл реалізації функції обчислення суми
#include <math.h>

#include "term.h"
#include "series.h"
#include "globals.h"

using namespace nsTerm;
using namespace nsGlobals;

void nsSeries::calc() {
    n = 0;
    a = x;          // перший доданок
    s = a;
    do {
        n++;
        term();     // виклик процедури обчислення доданку
        s += a;
    } while (fabs(a) > e);
}
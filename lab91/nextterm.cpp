// nextterm.cpp
// файл реалізації функції обчислення доданку
#include "nextterm.h"
#include "params.h"

using namespace nsParams;

void nsNext::nextTerm() {
    a *= -x * x * (2 * n - 1) / (2 * n + 1);   // доданок домножується на
}                                              // коефіцієнт рекурентності
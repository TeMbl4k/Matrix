#include "Symbol.h"
#include <Windows.h>
#include <cstdlib>
#include <random>

char Symbol::SetValue() const {
    int n = 33 + rand() % (126 - 33);

    if (epilepsy) {
        SetTextColor();
    }
    else {
        SetColor(2); 
    }
    return char(n);
}


void Symbol::SetColor(int text) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)(text));
}

void Symbol::SetTextColor() {
    int i = 1 + rand() % 15;
    SetColor(i);
}

Symbol::Symbol(bool epilepsy) : epilepsy(epilepsy) {}

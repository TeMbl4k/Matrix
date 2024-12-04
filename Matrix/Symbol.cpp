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
        SetColor(2); //green
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

Symbol::~Symbol() = default;


//#include "Symbol.h"
//#include <windows.h>
//#include <cstdlib>
//#include <random>
//#include <string>
//using namespace std;
//
//
//Symbol::Symbol(bool epilepsyMode) : epilepsy(epilepsyMode) {
//    symbol = getRandomSymbol(); // Генерация случайного символа
//}
//
//// Метод для генерации случайного символа
//char Symbol::getRandomSymbol() {
//    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWxyZabcdefghijklmnopqrstuvwxyz !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
//    int index = rand() % characters.size();
//    return characters[index]; 
//}
//
//// Метод для отображения символа
//void Symbol::display() {
//    if (epilepsy) {
//        int color = rand() % 7 + 1;
//        cout << "\033[1;3" << color << "m" << symbol << "\033[0m";
//    }
//    else {
//        cout << "\033[1;32m" << symbol << "\033[0m";
//    }
//}
//
//char Symbol::Disp() const {
//    int n = 33 + rand() % (126 - 33);
//
//    SetColor(2); //green
//    
//    return char(n);
//}
//
//void Symbol::SetColor(int text) {
//    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hStdOut, (WORD)(text));
//}
//
//Symbol::~Symbol() = default;



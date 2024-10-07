#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <cstdlib>

class Symbol {
public:
    char symbol;
    bool epilepsy;

    Symbol(bool epilepsyMode);
    char getRandomSymbol();
    void display();
};

#endif // SYMBOL_H

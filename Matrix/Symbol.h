#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <cstdlib>

class Symbol {
private:
    char symbol;
    bool epilepsy;

public:
    Symbol(bool epilepsyMode);
    char getRandomSymbol();
    void display();
};

#endif // SYMBOL_H

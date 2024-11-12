#ifndef SyMBOL_H
#define SyMBOL_H

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
    ~Symbol();
};

#endif // SyMBOL_H

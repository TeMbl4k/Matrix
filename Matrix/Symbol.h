#ifndef MATRIX_SYMBOL_H
#define MATRIX_SYMBOL_H


class Symbol {
    bool EpilepsyMode;
public:
    explicit Symbol(bool epilepsyMode);
    static void SetColor(int text);
    static void SetTextColor();
    char SetValue() const;

    ~Symbol();
};


#endif //MATRIX_SYMBOL_H


//#ifndef SyMBOL_H
//#define SyMBOL_H
//
//#include <iostream>
//#include <cstdlib>
//
//class Symbol {
//private:
//    char symbol;
//    bool epilepsy;
//
//public:
//    Symbol(bool epilepsyMode);
//    char getRandomSymbol();
//    void display();
//    ~Symbol();
//
//    static void SetColor(int text);
//    char Disp() const;
//
//};
//
//#endif // SyMBOL_H

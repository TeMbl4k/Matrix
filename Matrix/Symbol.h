#ifndef MATRIX_SYMBOL_H
#define MATRIX_SYMBOL_H


class Symbol {
    bool epilepsy;
public:
    explicit Symbol(bool epilepsy);
    static void SetColor(int text);
    static void SetTextColor();
    char SetValue() const;
};


#endif //MATRIX_SYMBOL_H

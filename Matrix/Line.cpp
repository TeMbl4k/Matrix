#include "Line.h"  

using namespace std;

// Устанавливаем курсор в заданную позицию в консоли
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    COORD position; // Координаты курсора
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position); // Устанавливаем позицию курсора

    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = false; // Скрываем курсор
    SetConsoleCursorInfo(hConsole, &cursor); // Применяем изменения
}


Line::Line(int len, int spd, bool epi) : length(len), speed(spd), epilepsy(epi) {}

// Метод для отрисовки ромба
void Line::printRomb(int startX, int startY) {
    setCursorPosition(startX, startY); 
    Symbol sym1{ epilepsy }; 
    sym1.display(); 
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); 

    setCursorPosition(startX + 2, startY + 1);
    Symbol sym2{ epilepsy };
    sym2.display(); 

    setCursorPosition(startX + 2, startY - 1);
    sym2.display(); // Отображаем символ выше
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); 
}

// Метод для очистки
void Line::clearRomb(int startX, int startY) {
    // Определяем четность длины линии для правильного отображения
    int ood = length % 2 == 0 ? 2 : 0;
    setCursorPosition(startX - (length * 2) - ood - 2, startY);
    cout << " "; 
    setCursorPosition(startX - length * 2 - ood, startY + 1);
    cout << " "; 
    setCursorPosition(startX - length * 2 - ood, startY - 1);
    cout << " "; 
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); 
}

// Метод для отрисовки линии в виде последовательности ромбов
void Line::printLine(int startY, int width) {
    int startX = 0; 
    setCursorPosition(startX, startY); 

    
    for (int i = 0; i < length / 2; i++) {
        printRomb(startX, startY); 
        startX += 4; 
    }

    while (startX < width) {
        printRomb(startX, startY); 
        startX += 4; 
        clearRomb(startX, startY); 
    }

    // Очистка ромбов в конце линии, чтобы удалить следы при выходе за границы
    for (int i = width - length - 2; i < width; i++) {
        clearRomb(startX, startY); 
        startX += 2;
    }
}

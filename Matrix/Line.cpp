#include "Line.h"  // Подключаем заголовочный файл с описанием класса Line и других зависимостей

using namespace std;

// Устанавливаем курсор в заданную позицию в консоли
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
    COORD position; // Координаты курсора
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position); // Устанавливаем позицию курсора

    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = false; // Скрываем курсор
    SetConsoleCursorInfo(hConsole, &cursor); // Применяем изменения
}

// Конструктор класса Line, который инициализирует длину линии, скорость и режим эпилепсии
Line::Line(int len, int spd, bool epi) : length(len), speed(spd), epilepsy(epi) {}

// Метод для отрисовки ромба в заданной позиции консоли (startX, startY)
void Line::printRomb(int startX, int startY) {
    setCursorPosition(startX, startY); // Устанавливаем курсор в начальную позицию
    Symbol sym1{ epilepsy }; // Создаем символ, учитывая режим эпилепсии
    sym1.display(); // Отображаем символ
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); // Ждем, чтобы соблюсти скорость линии

    // Отрисовка двух символов выше и ниже исходного
    setCursorPosition(startX + 2, startY + 1);
    Symbol sym2{ epilepsy };
    sym2.display(); // Отображаем символ ниже

    setCursorPosition(startX + 2, startY - 1);
    sym2.display(); // Отображаем символ выше
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); // Опять пауза для контроля скорости
}

// Метод для очистки символов ромба в консоли (удаление следов линии)
void Line::clearRomb(int startX, int startY) {
    // Определяем четность длины линии для правильного отображения
    int ood = length % 2 == 0 ? 2 : 0;
    setCursorPosition(startX - (length * 2) - ood - 2, startY);
    cout << " "; // Очищаем символ в начальной позиции
    setCursorPosition(startX - length * 2 - ood, startY + 1);
    cout << " "; // Очищаем символ ниже
    setCursorPosition(startX - length * 2 - ood, startY - 1);
    cout << " "; // Очищаем символ выше
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); // Пауза для соблюдения скорости
}

// Метод для отрисовки линии в виде последовательности ромбов
void Line::printLine(int startY, int width) {
    int startX = 0; // Начальная позиция линии
    setCursorPosition(startX, startY); // Устанавливаем курсор

    // Цикл для отрисовки линии половинной длины
    for (int i = 0; i < length / 2; i++) {
        printRomb(startX, startY); // Рисуем ромб
        startX += 4; // Смещаемся вправо для следующего ромба
    }

    // Основной цикл отрисовки линии до конца консоли
    while (startX < width) {
        printRomb(startX, startY); // Рисуем ромб
        startX += 4; // Смещаемся вправо
        clearRomb(startX, startY); // Очищаем предыдущий ромб
    }

    // Очистка ромбов в конце линии, чтобы удалить следы при выходе за границы
    for (int i = width - length - 2; i < width; i++) {
        clearRomb(startX, startY); // Очищаем оставшиеся символы
        startX += 2; // Сдвигаем курсор вправо
    }
}

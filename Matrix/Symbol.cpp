#include "Symbol.h" // Подключаем заголовочный файл, содержащий описание класса Symbol

using namespace std;

// Конструктор класса Symbol, который принимает параметр epilepsyMode и инициализирует поле epilepsy
// Также инициализируется символ с помощью метода getRandomSymbol, который генерирует случайный символ
Symbol::Symbol(bool epilepsyMode) : epilepsy(epilepsyMode) {
    symbol = getRandomSymbol(); // Генерация случайного символа
}

// Метод для генерации случайного символа
char Symbol::getRandomSymbol() {
    // Строка, содержащая возможные символы для отображения
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    int index = rand() % characters.size(); // Генерация случайного индекса для выбора символа
    return characters[index]; // Возвращаем случайный символ
}

// Метод для отображения символа
void Symbol::display() {
    if (epilepsy) {
        // Если включен режим эпилепсии, выбираем случайный цвет (от 1 до 7) и применяем его к символу
        int color = rand() % 7 + 1;
        cout << "\033[1;3" << color << "m" << symbol << "\033[0m"; // Вывод символа с цветом
    }
    else {
        // Если режим эпилепсии выключен, отображаем символ в зелёном цвете
        cout << "\033[1;32m" << symbol << "\033[0m"; // Вывод символа в зелёном цвете
    }
}

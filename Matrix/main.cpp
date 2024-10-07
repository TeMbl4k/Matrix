#include <iostream> // Подключаем библиотеку для работы с вводом/выводом
#include "AppManager.h" // Подключаем заголовочный файл с описанием класса AppManager
#include <windows.h> // Библиотека для работы с функциями Windows (например, с консолью)
#include <string> // Библиотека для работы со строками
#include <stdexcept> // Библиотека для работы с исключениями

using namespace std;

int main(int argc, char* argv[]) {
    AppManager app;  // Создаем объект класса AppManager
    app.startApp(argc, argv);  // Вызываем метод startApp для обработки 
    return 0;
}


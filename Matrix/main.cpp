#include <iostream> // Подключаем библиотеку для работы с вводом/выводом
#include "AppManager.h" // Подключаем заголовочный файл с описанием класса AppManager
#include <windows.h> // Библиотека для работы с функциями Windows (с консолью)
#include <string> // Библиотека для работы со строками
#include <stdexcept> // Библиотека для работы с исключениями

using namespace std;

AppManager app;

int main(int argc, char* argv[]) {
    app.startApp(argc, argv);  
}


#include "AppManager.h" 

using namespace std;

int main(int argc, char* argv[]) {
    AppManager app;  // Создаем объект класса AppManager
    app.startApp(argc, argv);  // Вызываем метод startApp для обработки 
    return 0;
}


#include "AppManager.h" 
#include <string>

using namespace std;

#ifdef max
#undef max
#endif

//Получает размеры консоли
AppManager::AppManager() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    GetConsoleScreenBufferInfo(hConsole, &csbi); 
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void AppManager::welcome() {

    cout << "          Welcome to Matrix -_-\n============================================" << endl;

    // Запрашиваем у пользователя скорость линии (1-30) с проверкой на корректность
    cout << "Print line speed (1 - 30): ";
    while (true) {
        cin >> line_speed;
        // Если ввод некорректный или число не в диапазоне, повторяем запрос
        if (cin.fail() || line_speed < 1 || line_speed > 30) {
            cin.clear(); // Очищаем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            cout << "Invalid input. Please enter a valid number: "; 
        }
        else {
            break; 
        }
    }

    // Запрашиваем длину линии с проверкой на корректность (аналогично предыдущему шагу)
    cout << "Print line length (1 - 30): ";
    while (true) {
        cin >> line_length; // Читаем длину
        if (cin.fail() || line_length < 1 || line_length > 30) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else {
            break;
        }
    }

    // Запрашиваем включение режима эпилепсии (Y/N) с проверкой на корректность
    string epilepsy_input;
    cout << "Epilepsy mode (Y/N): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    while (true) {
        getline(cin, epilepsy_input); // Читаем ввод
        // Проверяем, введен ли один из допустимых символов (Y/N, y/n)
        if (epilepsy_input.length() == 1 && (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'N' || epilepsy_input[0] == 'y' || epilepsy_input[0] == 'n')) {
            epilepsy = (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'y'); // Определяем режим эпилепсии
            break;
        }
        else {
            cout << "Print correct flag (Y/N): "; 
        }
    }
}

void AppManager::startApp(int argc, char* argv[]) {
    bool validArgs = true;  // Флаг для проверки аргументов

    if (argc > 1) {
        // Если передан флаг --help или /?, выводим инструкцию по использованию программы
        if (string(argv[1]) == "--help" || string(argv[1]) == "/?") {
            cout << "Usage: matrix.exe [speed (1-30)] [length (1-30)] [epilepsy (Y/N)]" << endl;
            return;
        }

        // Если передано ровно 3 аргумента, выполняем их обработку
        if (argc == 4) {
            try {
                // Преобразуем первый аргумент (скорость линии) в число и проверяем его диапазон
                int speed = stoi(argv[1]);
                if (speed < 1 || speed > 30) {
                    cout << "Invalid speed. Speed must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_speed = speed;
                }

                // Преобразуем второй аргумент (длина линии) в число и проверяем его диапазон
                int length = stoi(argv[2]);
                if (length < 1 || length > 30) {
                    cout << "Invalid length. Length must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_length = length;
                }

                // Проверяем третий аргумент (режим эпилепсии)
                string input = argv[3];
                if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n')) {
                    epilepsy_flag = input[0];
                    epilepsy = (epilepsy_flag == 'Y' || epilepsy_flag == 'y');
                }
                else {
                    cout << "Invalid epilepsy flag. Use Y/N." << endl;
                    validArgs = false;
                }

            }
            catch (invalid_argument& e) {
                cout << "Invalid input. Arguments must be numbers for speed and length." << endl;
                validArgs = false;
            }
            catch (out_of_range& e) {
                cout << "Number out of range. Please enter valid numbers." << endl;
                validArgs = false;
            }
        }
        else {
            cout << "Invalid number of arguments. Use --help for usage instructions." << endl;
            validArgs = false;
        }
    }
    else {
        validArgs = false; // Если аргументов нет, устанавливаем флаг в false для вызова диалогового режима
    }

    // Если аргументы некорректны или отсутствуют, вызываем диалоговый режим
    if (!validArgs) {
        welcome();
    }

    // Запускаем приложение
    run();
}


// Основной цикл программы
void AppManager::run() {
    system("cls");
    while (true) {
        Line line(line_length, line_speed, epilepsy); // Создаем объект класса Line с параметрами
        line.Start(line_length, line_speed,  epilepsy, height, width);
    }
}


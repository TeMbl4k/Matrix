#include "AppManager.h" // Подключаем заголовочный файл с описанием класса AppManager
#include <string> // Подключаем библиотеку для работы со строками

using namespace std;

#ifdef max
#undef max
#endif

// Конструктор класса AppManager, который получает размеры консоли
AppManager::AppManager() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
    CONSOLE_SCREEN_BUFFER_INFO csbi; // Структура для хранения информации о консоли
    GetConsoleScreenBufferInfo(hConsole, &csbi); // Получаем информацию о текущем размере окна консоли
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // Ширина консоли
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // Высота консоли
}

// Функция для очистки консоли
void clearConsole() {
    system("cls"); // Очищаем консольную строку
}

// Метод приветствия и запроса параметров для работы программы
void AppManager::welcome() {
    // Вывод приветственного сообщения
    cout << "          Welcome to Matrix -_-\n============================================" << endl;

    // Запрашиваем у пользователя скорость линии (1-30) с проверкой на корректность
    cout << "Print line speed (1 - 30): ";
    while (true) {
        cin >> line_speed; // Читаем скорость
        // Если ввод некорректный или число не в диапазоне, повторяем запрос
        if (cin.fail() || line_speed < 1 || line_speed > 30) {
            cin.clear(); // Очищаем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            cout << "Invalid input. Please enter a valid number: "; // Просим повторить ввод
        }
        else {
            break; // Если всё правильно, выходим из цикла
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
            cout << "Print correct flag (Y/N): "; // Просим ввести корректное значение
        }
    }
}

void AppManager::startApp(int argc, char* argv[]) {
    // Проверяем, были ли переданы аргументы через командную строку
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
                    cout << "Invalid speed. Print correct speed (1 - 30)." << endl;
                    return;
                }
                line_speed = speed; // Сохраняем скорость

                // Преобразуем второй аргумент (длина линии) в число и проверяем его диапазон
                int length = stoi(argv[2]);
                if (length < 1 || length > 30) {
                    cout << "Invalid length. Print correct length (1 - 30)." << endl;
                    return;
                }
                line_length = length; // Сохраняем длину
            }
            catch (invalid_argument& e) {
                cout << "Invalid input. Print correct length and speed (1 - 30)." << endl;
                return;
            }
            catch (out_of_range& e) {
                cout << "Number out of range. Please enter numbers." << endl;
                return;
            }

            // Проверяем третий аргумент (режим эпилепсии)
            string input = argv[3];
            if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n')) {
                epilepsy_flag = input[0];
                epilepsy = (epilepsy_flag == 'Y' || epilepsy_flag == 'y');
            }
            else {
                cout << "Epilepsy flag incorrect (Y/N). Please enter correct flag." << endl;
                return;
            }
        }
        else {
            cout << "Invalid arguments. Use --help for usage." << endl;
            return;
        }
    }
    else {
        // Если аргументы командной строки не переданы, вызываем диалоговый режим
        welcome();
    }

    // Запускаем основную работу программы
    run();
}

// Основной цикл программы
void AppManager::run() {
    clearConsole(); // Очищаем консоль перед началом отрисовки
    while (true) {
        int randomRow = rand() % height; // Выбираем случайную строку для начала отрисовки линии
        Line line(line_length, line_speed, epilepsy); // Создаем объект класса Line с параметрами
        line.printLine(randomRow, width); // Отрисовываем линию в выбранной строке
    }
}


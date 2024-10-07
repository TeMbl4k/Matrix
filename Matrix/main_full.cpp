//#include <iostream>
//#include <cstdlib>  // Для rand()
//#include <chrono>   // Для управления скоростью
//#include <thread>   // Для задержек
//#include <windows.h> // Для работы с консолью
//#include <limits>  // для проверки на дурака
//#include <string>  
//#include <stdexcept> // Для обработки исключений
//
//using namespace std;
//
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//#ifdef max
//#undef max
//#endif
//
//void setCursorPosition(int x, int y) {
//    COORD position;
//    position.X = x;
//    position.Y = y;
//    SetConsoleCursorPosition(hConsole, position);
//
//    CONSOLE_CURSOR_INFO cursor;
//    cursor.dwSize = 1;
//    cursor.bVisible = false;
//    SetConsoleCursorInfo(hConsole, &cursor);
//}
//
//void clearConsole() {
//    system("cls");
//}
//
//class Symbol {
//public:
//    char symbol;
//    bool epilepsy;
//
//    Symbol(bool epilepsyMode) : epilepsy(epilepsyMode) {
//        symbol = getRandomSymbol();
//    }
//
//    char getRandomSymbol() {
//        return 'A' + rand() % 64;
//    }
//
//    void display() {
//        if (epilepsy) {
//            int color = rand() % 7 + 1;
//            cout << "\033[1;3" << color << "m" << symbol << "\033[0m";
//        }
//        else {
//            cout << "\033[1;32m" << symbol << "\033[0m";
//        }
//    }
//};
//
//class Line {
//public:
//    int length;
//    int speed;
//    bool epilepsy;
//
//
//    Line(int len, int spd, bool epi) : length(len), speed(spd), epilepsy(epi) {}
//
//    void printRomb(int startX, int startY) {
//        setCursorPosition(startX, startY);
//        Symbol sym1{ epilepsy }; sym1.display();
//        this_thread::sleep_for(chrono::milliseconds(1000 / speed));
//        setCursorPosition(startX + 2, startY + 1);
//        Symbol sym2{ epilepsy }; sym2.display();
//        setCursorPosition(startX + 2, startY - 1);
//        sym2.display();
//        this_thread::sleep_for(chrono::milliseconds(1000 / speed));
//    };
//
//    void clearRomb(int startX, int startY) {
//        int ood = length % 2 == 0 ? 2 : 0; // определение чётности длины
//        setCursorPosition(startX - (length * 2) - ood - 2, startY);
//        cout << " ";
//        setCursorPosition(startX - length * 2 - ood, startY + 1);
//        cout << " ";
//        setCursorPosition(startX - length * 2 - ood, startY - 1);
//        cout << " ";
//        this_thread::sleep_for(chrono::milliseconds(1000 / speed));
//    };
//
//    void printLine(int startY, int width) {
//        int startX = 0;
//        setCursorPosition(startX, startY);
//
//        for (int i = 0; i < length / 2; i++) { // вывод линии в начале консоли
//            printRomb(startX, startY);
//            startX += 4;
//        };
//
//        while (startX < width) { // ползание линии до конца консоли
//            printRomb(startX, startY);
//            startX += 4;
//            clearRomb(startX, startY);
//        }
//        for (int i = width - length - 2; i < width; i++) { // подтирание линии в конце консоли
//            clearRomb(startX, startY);
//            startX += 2;
//        }
//    }
//};
//
//class AppManager {
//public:
//    int line_speed, line_length;
//    bool epilepsy;
//    char epilepsy_flag;
//
//    AppManager() {
//        CONSOLE_SCREEN_BUFFER_INFO csbi;
//        GetConsoleScreenBufferInfo(hConsole, &csbi);
//        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
//    }
//
//    void welcome() {
//        cout << "          Welcome to Matrix -_-\n============================================" << endl;
//
//        cout << "Print line speed (1 - 30): ";
//
//        while (true) {
//            cin >> line_speed;
//
//            // Проверяем, произошла ли ошибка ввода (например, введена буква)
//            if (cin.fail()) {
//                cin.clear(); // Сбрасываем флаг ошибки
//                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
//                cout << "Invalid input. Please enter a number: ";
//            }
//            else if (line_speed < 1 || line_speed > 30) {
//                cout << "Print correct speed (1 - 30): ";
//            }
//            else {
//                break;
//            }
//        }
//
//        // Ввод длины
//        cout << "Print line length (1 - 30): ";
//
//        while (true) {
//            cin >> line_length;
//
//            // Проверяем, произошла ли ошибка ввода (например, введена буква)
//            if (cin.fail()) {
//                cin.clear(); // Сбрасываем флаг ошибки
//                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
//                cout << "Invalid input. Please enter a number: ";
//            }
//            else if (line_length < 1 || line_length > 30) {
//                cout << "Print correct length (1 - 30): ";
//            }
//            else {
//                break;
//            }
//        }
//
//        // Ввод режима эпилепсии
//        string epilepsy_input;
//
//        cout << "Epilepsy mode (Y/N): ";
//
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        while (true) {
//            getline(cin, epilepsy_input);
//
//            if (epilepsy_input.length() == 1 && (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'N' || epilepsy_input[0] == 'y' || epilepsy_input[0] == 'n')) {
//                // Если введён только один символ и он корректен
//                epilepsy = (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'y');
//                break;
//            }
//            else {
//                cout << "Print correct flag (Y/N): ";
//            }
//        }
//    }
//
//    int width, height;
//
//    void run() {
//        clearConsole();
//
//        while (true) {
//            int randomRow = rand() % height;
//            Line line(line_length, line_speed, epilepsy);
//            line.printLine(randomRow, width);
//        }
//    }
//};
//
//int main(int argc, char* argv[]) {
//    AppManager app;
//
//    if (argc > 1) {
//        if (string(argv[1]) == "--help" || string(argv[1]) == "/?") {
//            cout << "Usage: matrix.exe [speed (1-30)] [length (1-30)] [epilepsy (Y/N)]" << endl;
//            return 0;
//        }
//
//        if (argc == 4) {
//
//            try {
//                // Проверка скорости
//                int speed = stoi(argv[1]);
//                if (speed < 1 || speed > 30) {
//                    cout << "Invalid speed. Print correct speed (1 - 30)." << endl;
//                    return 1;
//                }
//                app.line_speed = speed;
//
//                // Проверка длины
//                int length = stoi(argv[2]);
//                if (length < 1 || length > 30) {
//                    cout << "Invalid length. Print correct length (1 - 30)." << endl;
//                    return 1;
//                }
//                app.line_length = length;
//
//            }
//            catch (invalid_argument& e) {
//                // Исключение возникает, если аргумент не является числом
//                cout << "Invalid input. Print correct length and speed (1 - 30)." << endl;
//                return 1;
//            }
//            catch (out_of_range& e) {
//                // Исключение возникает, если число выходит за пределы int
//                cout << "Number out of range. Please enter numbers." << endl;
//                return 1;
//            }
//
//            // Проверка режима эпилепсии
//            string input;
//            while (true) {
//                input = argv[3];
//                if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n')) {
//                    app.epilepsy_flag = input[0];
//                    app.epilepsy = (app.epilepsy_flag == 'Y' || app.epilepsy_flag == 'y');
//
//                    break;
//                }
//                else {
//                    cout << "Epilepsy flag incorrect (Y/N). Please enter correct flag.";
//                    return 1;
//                }
//            }
//        }
//        else {
//            cout << "Invalid arguments. Use --help for usage." << endl;
//            return 1;
//        }
//    }
//    else {
//        app.welcome();  // Использование метода welcome для запроса ввода
//    }
//
//    app.run();
//    return 0;
//}

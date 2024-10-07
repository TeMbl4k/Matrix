#include "AppManager.h" // ���������� ������������ ���� � ��������� ������ AppManager
#include <string> // ���������� ���������� ��� ������ �� ��������

using namespace std;

#ifdef max
#undef max
#endif

// ����������� ������ AppManager, ������� �������� ������� �������
AppManager::AppManager() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������
    CONSOLE_SCREEN_BUFFER_INFO csbi; // ��������� ��� �������� ���������� � �������
    GetConsoleScreenBufferInfo(hConsole, &csbi); // �������� ���������� � ������� ������� ���� �������
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1; // ������ �������
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // ������ �������
}

// ������� ��� ������� �������
void clearConsole() {
    system("cls"); // ������� ���������� ������
}

// ����� ����������� � ������� ���������� ��� ������ ���������
void AppManager::welcome() {
    // ����� ��������������� ���������
    cout << "          Welcome to Matrix -_-\n============================================" << endl;

    // ����������� � ������������ �������� ����� (1-30) � ��������� �� ������������
    cout << "Print line speed (1 - 30): ";
    while (true) {
        cin >> line_speed; // ������ ��������
        // ���� ���� ������������ ��� ����� �� � ���������, ��������� ������
        if (cin.fail() || line_speed < 1 || line_speed > 30) {
            cin.clear(); // ������� ���� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ������������ ����
            cout << "Invalid input. Please enter a valid number: "; // ������ ��������� ����
        }
        else {
            break; // ���� �� ���������, ������� �� �����
        }
    }

    // ����������� ����� ����� � ��������� �� ������������ (���������� ����������� ����)
    cout << "Print line length (1 - 30): ";
    while (true) {
        cin >> line_length; // ������ �����
        if (cin.fail() || line_length < 1 || line_length > 30) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else {
            break;
        }
    }

    // ����������� ��������� ������ ��������� (Y/N) � ��������� �� ������������
    string epilepsy_input;
    cout << "Epilepsy mode (Y/N): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
    while (true) {
        getline(cin, epilepsy_input); // ������ ����
        // ���������, ������ �� ���� �� ���������� �������� (Y/N, y/n)
        if (epilepsy_input.length() == 1 && (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'N' || epilepsy_input[0] == 'y' || epilepsy_input[0] == 'n')) {
            epilepsy = (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'y'); // ���������� ����� ���������
            break;
        }
        else {
            cout << "Print correct flag (Y/N): "; // ������ ������ ���������� ��������
        }
    }
}

void AppManager::startApp(int argc, char* argv[]) {
    // ���������, ���� �� �������� ��������� ����� ��������� ������
    if (argc > 1) {
        // ���� ������� ���� --help ��� /?, ������� ���������� �� ������������� ���������
        if (string(argv[1]) == "--help" || string(argv[1]) == "/?") {
            cout << "Usage: matrix.exe [speed (1-30)] [length (1-30)] [epilepsy (Y/N)]" << endl;
            return;
        }

        // ���� �������� ����� 3 ���������, ��������� �� ���������
        if (argc == 4) {
            try {
                // ����������� ������ �������� (�������� �����) � ����� � ��������� ��� ��������
                int speed = stoi(argv[1]);
                if (speed < 1 || speed > 30) {
                    cout << "Invalid speed. Print correct speed (1 - 30)." << endl;
                    return;
                }
                line_speed = speed; // ��������� ��������

                // ����������� ������ �������� (����� �����) � ����� � ��������� ��� ��������
                int length = stoi(argv[2]);
                if (length < 1 || length > 30) {
                    cout << "Invalid length. Print correct length (1 - 30)." << endl;
                    return;
                }
                line_length = length; // ��������� �����
            }
            catch (invalid_argument& e) {
                cout << "Invalid input. Print correct length and speed (1 - 30)." << endl;
                return;
            }
            catch (out_of_range& e) {
                cout << "Number out of range. Please enter numbers." << endl;
                return;
            }

            // ��������� ������ �������� (����� ���������)
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
        // ���� ��������� ��������� ������ �� ��������, �������� ���������� �����
        welcome();
    }

    // ��������� �������� ������ ���������
    run();
}

// �������� ���� ���������
void AppManager::run() {
    clearConsole(); // ������� ������� ����� ������� ���������
    while (true) {
        int randomRow = rand() % height; // �������� ��������� ������ ��� ������ ��������� �����
        Line line(line_length, line_speed, epilepsy); // ������� ������ ������ Line � �����������
        line.printLine(randomRow, width); // ������������ ����� � ��������� ������
    }
}


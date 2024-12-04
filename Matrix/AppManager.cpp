#include <iostream>
#include "AppManager.h"
#include "Run.h"
#include <string>

using namespace std;

#ifdef max
#undef max
#endif

void AppManager::welcome() {

    cout << "          Welcome to Matrix -_-\n============================================" << endl;

    std::cout << "Print line speed (1 - 30): ";
    while (true) {
        cin >> line_speed;
        if (cin.fail() || line_speed < 1 || line_speed > 30) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else {
            break;
        }
    }

    cout << "Print line length (1 - 30): ";
    while (true) {
        cin >> line_length;
        if (cin.fail() || line_length < 1 || line_length > 30) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number: ";
        }
        else {
            break;
        }
    }

    cout << "Print line frequency (1 - 30): ";
    while (true) {
        cin >> line_frequency;
        if (cin.fail() || line_frequency < 1 || line_frequency > 30) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 30: ";
        }
        else {
            break;
        }
    }

    cout << "Print exp_prob (1 - 1000): ";
    while (true) {
        cin >> exp_prob;
        if (cin.fail() || exp_prob < 1 || exp_prob > 1000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 30: ";
        }
        else {
            break;
        }
    }

    cout << "Print min rad (1 - 10): ";
    while (true) {
        cin >> min_rad;
        if (cin.fail() || min_rad < 1 || min_rad > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 30: ";
        }
        else {
            break;
        }
    }

    cout << "Print max rad (1 - 30): ";
    while (true) {
        cin >> max_rad;
        if (cin.fail() || max_rad < 1 || max_rad > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 30: ";
        }
        else {
            break;
        }
    }

    string epilepsy_input;
    cout << "Epilepsy mode (y/N): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        getline(cin, epilepsy_input);
        if (epilepsy_input.length() == 1 && (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'N' || epilepsy_input[0] == 'y' || epilepsy_input[0] == 'n')) {
            epilepsy = (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'y');
            break;
        }
        else {
            cout << "Print correct flag (y/N): ";
        }
    }
}

void AppManager::startApp(int argc, char* argv[]) {
    bool validArgs = true;

    if (argc > 1) {
        if (string(argv[1]) == "--help" || string(argv[1]) == "/?") {
            cout << "Usage: matrix.exe [speed (1-30)] [length (1-30)] [epilepsy (y/N)]" << endl;
            return;
        }

        if (argc == 8) {
            try {
                int speed = stoi(argv[1]);
                if (speed < 1 || speed > 30) {
                    cout << "Invalid speed. Speed must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_speed = speed;
                }

                int length = stoi(argv[2]);
                if (length < 1 || length > 30) {
                    cout << "Invalid length. Length must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_length = length;
                }

                int frequency = stoi(argv[3]);
                if (frequency < 1 || frequency > 30) {
                    cout << "Invalid frequency. Length must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_frequency = frequency;
                }

                int exp_prob = stoi(argv[4]);
                if (frequency < 1 || frequency > 30) {
                    cout << "Invalid frequency. Length must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_frequency = frequency;
                }

                int min_rad = stoi(argv[5]);
                if (frequency < 1 || frequency > 30) {
                    cout << "Invalid frequency. Length must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_frequency = frequency;
                }

                int max_rad = stoi(argv[6]);
                if (frequency < 1 || frequency > 30) {
                    cout << "Invalid frequency. Length must be between 1 and 30." << endl;
                    validArgs = false;
                }
                else {
                    line_frequency = frequency;
                }

                string input = argv[7];
                if (input.length() == 1 && (input[0] == 'Y' || input[0] == 'y' || input[0] == 'N' || input[0] == 'n')) {
                    epilepsy_flag = input[0];
                    epilepsy = (epilepsy_flag == 'Y' || epilepsy_flag == 'y');
                }
                else {
                    cout << "Invalid epilepsy flag. Use Y/N." << endl;
                    validArgs = false;
                }

            }
            catch (invalid_argument&) {
                cout << "Invalid input. Arguments must be numbers for speed and length." << endl;
                validArgs = false;
            }
            catch (out_of_range&) {
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
        validArgs = false;
    }

    if (!validArgs) {
        welcome();
    }

    srand(time(nullptr));
    Windows win;
    win.clean();
    win.hidecursor();


    Run run(line_length, line_speed, line_frequency, epilepsy, exp_prob, min_rad, max_rad);
}



//#include "Welcome.h"
//#include "AppManager.h"
//#include "Run.h"
//#include "Line.h"
//
//#include <windows.h>
//#include <string>
//#include <cstdio>
//#include <ctime>
//#include <cstdlib>
//#include <cctype>
//#include <iostream>
//#include <random>
//
//#ifdef max
//#undef max
//#endif
//
//using namespace std;
//
//Welcome::Welcome() {
//    set_param();
//}
//
//void Welcome::set_length() {
//    std::cout << "Print line lenght (1 - 30): ";
//    while (true) {
//        cin >> line_length; // ������ �����
//        if (cin.fail() || line_length < 1 || line_length > 30) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a valid number: ";
//        }
//        else {
//            break;
//        }
//    }
//}
//
//void Welcome::set_speed() {
//    std::cout << "Print line speed (1 - 30): ";
//        while (true) {
//            std::cin >> line_speed;
//            // ���� ���� ������������ ��� ����� �� � ���������, ��������� ������
//            if (cin.fail() || line_speed < 1 || line_speed > 30) {
//                cin.clear(); // ������� ���� ������
//                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ������������ ����
//                cout << "Invalid input. Please enter a valid number: "; 
//            }
//            else {
//                break; 
//            }
//        }
//}
//
//
//
//void Welcome::set_frequency() {
//    cout << "Print line frequency (1 - 30): ";
//    while (true) {
//        cin >> line_frequency;
//        if (cin.fail() || line_frequency < 1 || line_frequency > 30) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Please enter a number between 1 and 30: ";
//        }
//        else {
//            break;
//        }
//    }
//}
//
//void Welcome::set_epilepsy() {
//    string epilepsy_input;
//        cout << "Epilepsy mode (Y/N): ";
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
//        while (true) {
//            getline(cin, epilepsy_input); // ������ ����
//            // ���������, ������ �� ���� �� ���������� �������� (Y/N, y/n)
//            if (epilepsy_input.length() == 1 && (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'N' || epilepsy_input[0] == 'y' || epilepsy_input[0] == 'n')) {
//                epilepsy = (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'y'); // ���������� ����� ���������
//                break;
//            }
//            else {
//                cout << "Print correct flag (Y/N): "; 
//            }
//        }
//}
//
////void AppManager::welcome() {
////
////    cout << "          Welcome to Matrix -_-\n============================================" << endl;
////
////    // ����������� � ������������ �������� ����� (1-30) � ��������� �� ������������
////    std::cout << "Print line speed (1 - 30): ";
////    while (true) {
////        cin >> line_speed;
////        // ���� ���� ������������ ��� ����� �� � ���������, ��������� ������
////        if (cin.fail() || line_speed < 1 || line_speed > 30) {
////            cin.clear(); // ������� ���� ������
////            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� ������������ ����
////            cout << "Invalid input. Please enter a valid number: "; 
////        }
////        else {
////            break; 
////        }
////    }
////
////    // ����������� ����� ����� � ��������� �� ������������ (���������� ����������� ����)
////    cout << "Print line length (1 - 30): ";
////    while (true) {
////        cin >> line_length; // ������ �����
////        if (cin.fail() || line_length < 1 || line_length > 30) {
////            cin.clear();
////            cin.ignore(numeric_limits<streamsize>::max(), '\n');
////            cout << "Invalid input. Please enter a valid number: ";
////        }
////        else {
////            break;
////        }
////    }
////
////    cout << "Print line frequency (1 - 30): ";
////    while (true) {
////        cin >> line_frequency;
////        if (cin.fail() || line_frequency < 1 || line_frequency > 30) {
////            cin.clear();
////            cin.ignore(numeric_limits<streamsize>::max(), '\n');
////            cout << "Invalid input. Please enter a number between 1 and 30: ";
////        }
////        else {
////            break;
////        }
////    }
////
////    // ����������� ��������� ������ ��������� (Y/N) � ��������� �� ������������
////    string epilepsy_input;
////    cout << "Epilepsy mode (Y/N): ";
////    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
////    while (true) {
////        getline(cin, epilepsy_input); // ������ ����
////        // ���������, ������ �� ���� �� ���������� �������� (Y/N, y/n)
////        if (epilepsy_input.length() == 1 && (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'N' || epilepsy_input[0] == 'y' || epilepsy_input[0] == 'n')) {
////            epilepsy = (epilepsy_input[0] == 'Y' || epilepsy_input[0] == 'y'); // ���������� ����� ���������
////            break;
////        }
////        else {
////            cout << "Print correct flag (Y/N): "; 
////        }
////    }
////}
////
//
//void Welcome::set_param() {
//    set_length();
//    set_speed();
//    set_frequency();
//    set_epilepsy();
//}
//
//
//bool Welcome::is_epilepsy() {
//    return epilepsy;
//}
//
//int Welcome::get_length() {
//    return line_length;
//}
//
//int Welcome::get_speed() {
//    return line_speed;
//}
//
//int Welcome::get_frequency() {
//    return line_frequency;
//}

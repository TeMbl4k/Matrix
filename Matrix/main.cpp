#include <iostream> // ���������� ���������� ��� ������ � ������/�������
#include "AppManager.h" // ���������� ������������ ���� � ��������� ������ AppManager
#include <windows.h> // ���������� ��� ������ � ��������� Windows (� ��������)
#include <string> // ���������� ��� ������ �� ��������
#include <stdexcept> // ���������� ��� ������ � ������������

using namespace std;

AppManager app;

int main(int argc, char* argv[]) {
    app.startApp(argc, argv);  
}


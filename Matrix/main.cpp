#include <iostream> // ���������� ���������� ��� ������ � ������/�������
#include "AppManager.h" // ���������� ������������ ���� � ��������� ������ AppManager
#include <windows.h> // ���������� ��� ������ � ��������� Windows (��������, � ��������)
#include <string> // ���������� ��� ������ �� ��������
#include <stdexcept> // ���������� ��� ������ � ������������

using namespace std;

int main(int argc, char* argv[]) {
    AppManager app;  // ������� ������ ������ AppManager
    app.startApp(argc, argv);  // �������� ����� startApp ��� ��������� 
    return 0;
}


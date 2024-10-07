#include "Line.h"  // ���������� ������������ ���� � ��������� ������ Line � ������ ������������

using namespace std;

// ������������� ������ � �������� ������� � �������
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������
    COORD position; // ���������� �������
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position); // ������������� ������� �������

    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = false; // �������� ������
    SetConsoleCursorInfo(hConsole, &cursor); // ��������� ���������
}

// ����������� ������ Line, ������� �������������� ����� �����, �������� � ����� ���������
Line::Line(int len, int spd, bool epi) : length(len), speed(spd), epilepsy(epi) {}

// ����� ��� ��������� ����� � �������� ������� ������� (startX, startY)
void Line::printRomb(int startX, int startY) {
    setCursorPosition(startX, startY); // ������������� ������ � ��������� �������
    Symbol sym1{ epilepsy }; // ������� ������, �������� ����� ���������
    sym1.display(); // ���������� ������
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); // ����, ����� �������� �������� �����

    // ��������� ���� �������� ���� � ���� ���������
    setCursorPosition(startX + 2, startY + 1);
    Symbol sym2{ epilepsy };
    sym2.display(); // ���������� ������ ����

    setCursorPosition(startX + 2, startY - 1);
    sym2.display(); // ���������� ������ ����
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); // ����� ����� ��� �������� ��������
}

// ����� ��� ������� �������� ����� � ������� (�������� ������ �����)
void Line::clearRomb(int startX, int startY) {
    // ���������� �������� ����� ����� ��� ����������� �����������
    int ood = length % 2 == 0 ? 2 : 0;
    setCursorPosition(startX - (length * 2) - ood - 2, startY);
    cout << " "; // ������� ������ � ��������� �������
    setCursorPosition(startX - length * 2 - ood, startY + 1);
    cout << " "; // ������� ������ ����
    setCursorPosition(startX - length * 2 - ood, startY - 1);
    cout << " "; // ������� ������ ����
    this_thread::sleep_for(chrono::milliseconds(1000 / speed)); // ����� ��� ���������� ��������
}

// ����� ��� ��������� ����� � ���� ������������������ ������
void Line::printLine(int startY, int width) {
    int startX = 0; // ��������� ������� �����
    setCursorPosition(startX, startY); // ������������� ������

    // ���� ��� ��������� ����� ���������� �����
    for (int i = 0; i < length / 2; i++) {
        printRomb(startX, startY); // ������ ����
        startX += 4; // ��������� ������ ��� ���������� �����
    }

    // �������� ���� ��������� ����� �� ����� �������
    while (startX < width) {
        printRomb(startX, startY); // ������ ����
        startX += 4; // ��������� ������
        clearRomb(startX, startY); // ������� ���������� ����
    }

    // ������� ������ � ����� �����, ����� ������� ����� ��� ������ �� �������
    for (int i = width - length - 2; i < width; i++) {
        clearRomb(startX, startY); // ������� ���������� �������
        startX += 2; // �������� ������ ������
    }
}

#include "Symbol.h" // ���������� ������������ ����, ���������� �������� ������ Symbol

using namespace std;

// ����������� ������ Symbol, ������� ��������� �������� epilepsyMode � �������������� ���� epilepsy
// ����� ���������������� ������ � ������� ������ getRandomSymbol, ������� ���������� ��������� ������
Symbol::Symbol(bool epilepsyMode) : epilepsy(epilepsyMode) {
    symbol = getRandomSymbol(); // ��������� ���������� �������
}

// ����� ��� ��������� ���������� �������
char Symbol::getRandomSymbol() {
    // ������, ���������� ��������� ������� ��� �����������
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    int index = rand() % characters.size(); // ��������� ���������� ������� ��� ������ �������
    return characters[index]; // ���������� ��������� ������
}

// ����� ��� ����������� �������
void Symbol::display() {
    if (epilepsy) {
        // ���� ������� ����� ���������, �������� ��������� ���� (�� 1 �� 7) � ��������� ��� � �������
        int color = rand() % 7 + 1;
        cout << "\033[1;3" << color << "m" << symbol << "\033[0m"; // ����� ������� � ������
    }
    else {
        // ���� ����� ��������� ��������, ���������� ������ � ������ �����
        cout << "\033[1;32m" << symbol << "\033[0m"; // ����� ������� � ������ �����
    }
}

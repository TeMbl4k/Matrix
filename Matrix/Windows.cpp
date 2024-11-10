#include "Windows.h"

Windows::Windows()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO buffer;
	GetConsoleScreenBufferInfo(hConsole, &buffer);
	height = buffer.srWindow.Bottom - buffer.srWindow.Top;
	width = buffer.srWindow.Right - buffer.srWindow.Left;

	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1;
	cursor.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursor);

	srand(time(NULL));
}


void Windows::SetPos(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position; // Координаты курсора
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position); // Устанавливаем позицию курсора

	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1;
	cursor.bVisible = false; // Скрываем курсор
	SetConsoleCursorInfo(hConsole, &cursor); // Применяем изменения
}


int Windows::GetHeight()
{
	return height;
}

int Windows::GetWidth()
{
	return width;
}

#include "Windows.h"
#include <windows.h>


void Windows::SetPos(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut, coord);
}

class cs Windows::getConsoleSize() {
    class cs tmp {};
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    tmp.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    tmp.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return tmp;
}

void Windows::clean() {
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(hStdout);
}

void Windows::cls(void* hConsole) {
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
        (TCHAR)' ',      // Character to write to the buffer
        dwConSize,       // Number of cells to write
        coordScreen,     // Coordinates of first cell
        &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
        csbi.wAttributes, // Character attributes to use
        dwConSize,        // Number of cells to set attribute
        coordScreen,      // Coordinates of first cell
        &cCharsWritten))  // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void Windows::hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

//#include "Windows.h"
//
//Windows::Windows()
//{
//	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	CONSOLE_SCREEN_BUFFER_INFO buffer;
//	GetConsoleScreenBufferInfo(hConsole, &buffer);
//	height = buffer.srWindow.Bottom - buffer.srWindow.Top;
//	width = buffer.srWindow.Right - buffer.srWindow.Left;
//
//	CONSOLE_CURSOR_INFO cursor;
//	cursor.dwSize = 1;
//	cursor.bVisible = false;
//	SetConsoleCursorInfo(hConsole, &cursor);
//
//	srand(time(NULL));
//}
//
//
//void Windows::SetPos(int x, int y) {
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD position; // Координаты курсора
//	position.X = x;
//	position.Y = y;
//	SetConsoleCursorPosition(hConsole, position); // Устанавливаем позицию курсора
//
//	CONSOLE_CURSOR_INFO cursor;
//	cursor.dwSize = 1;
//	cursor.bVisible = false; // Скрываем курсор
//	SetConsoleCursorInfo(hConsole, &cursor); // Применяем изменения
//}
//
//
//int Windows::GetHeight() const
//{
//	return height;
//}
//
//int Windows::GetWidth() const
//{
//	return width;
//}

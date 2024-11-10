#ifndef WINDOWS_H

#define WINDOWS_H

#include <windows.h>
#include <ctime>

class Windows
{
private:
	int height, width;
	COORD coord;
	HANDLE hConsole;

public:
	Windows();
	void SetPos(int x, int y);
	int GetHeight() const;
	int GetWidth() const;
};

#endif

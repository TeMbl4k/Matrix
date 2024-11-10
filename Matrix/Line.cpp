#include "Line.h"

using namespace std;

// Устанавливаем курсор в заданную позицию в консоли

Line::Line(int len, int spd, bool epi, int freq) : length(len), speed(spd), epilepsy(epi), frequency(freq){
    int random_width = rand() % (Win.GetWidth() - 1) + 1;
}

void Line::Start(int line_length, int speed, bool ep)
{
    while (true)
    {
        int len = 0;

        bool r = rand() % 2;
        for (int i = 0; i <+ Win.GetHeight(); i++)
        {
            if ((i + r) % 2 == 0)
            {
                Win.SetPos(random_width, i);
                Symbol sym{ epilepsy };
                sym.display();

            }
            else
            {
                Win.SetPos(random_width + 1, i);
                Symbol sym1{ epilepsy };
                sym1.display();
                Win.SetPos(random_width - 1, i);
                Symbol sym2{ epilepsy };
                sym2.display();
            }
            if (len == line_length)
            {
                Win.SetPos(random_width + 1, i - line_length);
                cout << " ";
                Win.SetPos(random_width, i - line_length);
                cout << " ";
                Win.SetPos(random_width - 1, i - line_length);
                cout << " ";
            }
            else
            {
                len++;
            }
            Sleep(1000 / speed);
        }
        for (int i = Win.GetHeight() - line_length - 1; i <= Win.GetHeight(); i++)
        {
            Win.SetPos(random_width + 1, i);
            cout << ' ';
            Win.SetPos(random_width, i);
            cout << ' ';
            Win.SetPos(random_width - 1, i);
            cout << ' ';

            Sleep(1000 / speed);
        }
    }
}
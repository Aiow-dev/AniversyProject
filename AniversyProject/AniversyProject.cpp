#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void set_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void set_position(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clear_console()
{
	system("cls");
}

int menu(int points_num, string* points, int start_x = 1, int start_y = 3)
{
	int max_index = points_num - 1;
	int default_color = 7;
	int active_color = 12;
	int x = start_x;
	int y = start_y;
	int counter = 0;
	char key;

	while (true)
	{
		y = start_y;
		for (int i = 0; i < points_num; i++)
		{
			set_position(x, y);
			if (counter == i)
			{
				set_color(active_color);
			}
			else
			{
				set_color(default_color);
			}
			cout << points[i];
			y++;
		}

		key = _getch();
		if (key == 72)
		{
			counter--;
		}
		if (key == 80)
		{
			counter++;
		}
		if (key == '\r')
		{
			set_color(default_color);
			return counter;
		}

		if (counter < 0) {
			counter = max_index;
		}
		if (counter > max_index) {
			counter = 0;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RuS");

	set_position(1, 1);
	cout << "Меню:" << endl;
	string main_points[] = { 
		"1. Ведомость абитуриентов", 
		"2. Список абитуриентов (балл выше среднего)",
		"3. Создание записи",
		"4. Поиск записи",
		"5. Выход"
	};
	int point_num = menu(5, main_points);
	clear_console();

	return 0;
}

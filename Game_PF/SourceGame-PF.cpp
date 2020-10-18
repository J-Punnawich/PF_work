#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcolor(int fg, int bg)
{
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	}
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);setcolor(2, 4); printf(" <-0-> ");

}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");

}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ammo(int x, int y)
{
	gotoxy(x += 2, --y); setcolor(2, 0); printf("^");
}
void delete_ammo(int x, int y)
{
	gotoxy(x += 2, --y); setcolor(0, 0); printf(" ");
}
char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];
}





int main()
{

	srand(time(NULL));

	setcursor(0);
	char ch = ' ';
	int x1 = 38, y1 = 20, x2[5], y2[5] = { 20,20,20,20,20 }, x3, y3, moving = 0, shoot[5] = { 0,0,0,0,0 }, count = -1;
	draw_ship(x1, y1);


	//randomStar
	int k = 0;
	while (k <= 10)
	{
		x3 = rand() / 10;
		y3 = rand() / 10;
		if (x3 >= 10 && x3 <= 70 && y3 >= 2 && y3 <= 5)
		{
			gotoxy(x3, y3);

			printf(" * ");
			k++;
		}

	}


	do
	{

		for (int i = 0; i < 5; i++)
		{
			if (shoot[i] == 0) { x2[i] = x1; }

			if (shoot[i] == 1)
			{
				delete_ammo(x2[i], y2[i]);
				if (y2[i] == 2) { shoot[i] = 0; }
				else { draw_ammo(x2[i], --y2[i]); }
			}
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' && x1 > 0) { erase_ship(x1, y1);draw_ship(--x1, y1); }
			if (ch == 'd' && x1 < 73) { erase_ship(x1, y1); draw_ship(++x1, y1); }
			if (ch == 's') { erase_ship(x1, y1); draw_ship(x1, ++y1); }
			if (ch == ' ' && count < 4) { ++count; shoot[count] = 1; }
			fflush(stdin);

			for (int j = 0; j <= 4; j++)
			{
				if (shoot[j] == 1 && y2[j] > 0)
				{
					delete_ammo(x2[j], y2[j]);
					draw_ammo(x2[j], --y2[j]);
				}
				
			}
			if (y2[0] == 1)
			{
				delete_ammo(x2[0], y2[0]);
				shoot[0] = 0;
				y2[0] = y1;
				--count;
				for (int a = 1; a <= 4; a++)
				{
					shoot[a - 1] = shoot[a];
					y2[a - 1] = y2[a];
					x2[a - 1] = x2[a];
				}
				shoot[4] = 0; y2[4] = y1; x2[4] = x1;
			}
			

		}

		Sleep(100);

	} while (ch != 'x');
	return 0;
}






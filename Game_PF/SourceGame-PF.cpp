#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);
void draw_ship(int x, int y);
void erase_ship(int x, int y);

int main()
{

	char ch = ' ';
	int x = 38, y = 20;
	setcursor(0);
	draw_ship(x, y);


	do {
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' && x > 0) { erase_ship(x, y);draw_ship(--x, y); }
			if (ch == 'd' && x < 73) { erase_ship(x, y); draw_ship(++x, y); }
			if (ch == 'w' && y > 0) { erase_ship(x, y); draw_ship(x, --y); }
			if (ch == 's') { erase_ship(x, y); draw_ship(x, ++y); }
			fflush(stdin);

		}
		Sleep(100);

	} while (ch != 'x');
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, bg * 16 + fg);
	}
}
void draw_ship(int x,int y)
{
	gotoxy(x, y);setcolor(2,4); printf(" <-0-> ");

}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
	
}





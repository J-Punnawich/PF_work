#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
void draw_ship(int, int);
void gotoxy(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void draw_shot(int, int);
void erase_shot(int, int);
void draw_star(int, int);
void erase_star(int, int);
void score(int, int);
char cursor(int, int);
int number = 0;
//ยาว 80 สูง 20
int main() {
	int x = 38, y = 20, position_x[5], position_y[5], shot[5], num = 0, star,
		star_x[20], star_y[20], star_1 = 0;

	char ch = ' ';


	setcursor(0);
	srand(time(NULL));  // ล้างค่าrandom
	cursor(1, 3);

	for (star = 0; star < 20; star++) {

		star_x[star] = (rand() % 61) + 10;	// ค่ามันจะสุ่มได้ 0-60 เรา + 1 เข้าไปจะได้ 10-70 นั่นเอง 
		star_y[star] = (rand() % 4) + 1;  // ค่ามันจะสุ่มได้ 0-3 เรา + 1 เข้าไปจะได้ 1-4 นั่นเอง 
		draw_star(star_x[star], star_y[star]);

	}


	draw_ship(x, y);
	for (int i = 0; i < 5; i++) {
		shot[i] = 0;		//กำหนดค่าของกระสุนไว้ ไม่ให้เป็นค่าขยะเฉยๆ	
	}


	do {
		score(x, y); // ให้วนลูปในการแสดงค่าคะแนน แต่ละครั้งเมื่อยินโดน * 
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				num = 1;
			}
			//เป็นการรับค่าเข้าาเฉยๆเพื่อจะได้รู้ว่าไปซ้ายไปขวาคือตัวเลขอะไรแล้วไปเช็ตเงื่อนไขการเคลื่อนที่ข้างล่าง

			if (ch == 'd') {
				num = 2;
			}


			if (ch == 's') {   // วิ่งซ้ายขวาเรื่อยๆ จนกว่าจะชนหรือกด s
				num = 3;
			}


			if (ch == ' ') {   // กด spacbar เพิ้อ ยิงกระสุน

				for (int i = 0; i < 5; i++) { //แค่ทำให้ครบรอบเฉยๆ แต่จริงๆไม่ต้องวนลูปก็ได้
					if (shot[i] == 0) {

						shot[i] = 1;		//เซ้ทค่าเพื่อเอาไปใช้ให้มันขยับ ใน for ข้างล่าง 
						position_x[i] = x + 2;  // ใช้ค่าตน.ของยานมาให้เท่ากับ ตัวแปร position    // *** และให้กรสุนมันขยับไปตรงกลางยานโดยการ +2
						position_y[i] = y - 1;

						draw_shot(position_x[i], position_y[i]); // ใช้ค่า x เป็นค่าของยาน เลยเป็นยานออกมา
						break;

					}
				}
			}

			fflush(stdin);
		}  // จบif ใหญ่

		//เงื่อนไขในการเช็คว่าไปซ้ายไปขวา
		if (num == 1 && x > 0)    //ไปทางซ้าย
		{
			erase_ship(x, y); draw_ship(--x, y);
		}
		if (num == 2 && x < 73)	 //ไปทางขวา
		{
			erase_ship(x, y); draw_ship(++x, y);
		}  // ถ้าให้มันหยุดคือกด s ถ้ากด s ค่ามันคือ 3 มันจะไม่เข้าเงื่อไขไหนเลยมันก็จะหยุด


		for (int i = 0; i < 5; i++) {
			if (shot[i] == 1)    //ค่าที่รับจากลูปด้านบน เปิดค่าให้มันยิงมา
			{

				erase_shot(position_x[i], position_y[i]); //ลบกระสุนตรงยานออก


				if (position_y[i] > 0) {     //เป็นการฟิคขอบเขตของความสูงของจอภาพ 

					position_y[i] = position_y[i] - 1; // วนลูปให้กระสุนลดขึ้นจอด้านบนไปเรื่อยๆ วนลูปไป


					if (cursor(position_x[i], position_y[i]) == '*') {  // การเช็คค่าว่ามันโดน * ไหม

						shot[i] = 0;								// เซ้ทค่าเพื่อให้ให้ค่า มันเป็น 1 เหมือนเดิม เพราะไม่งั้น เมื่อชนแล้วลูกษรนี้ ^ ก็ยังไม่หายไป
						erase_star(position_x[i], position_y[i]);
						erase_shot(position_x[i], position_y[i]);
						Beep(700, 200);  //ให้เกิดเสียง
						draw_star(rand() % 65, rand() % 5);   // ให้ดาวเกิดสุ่มเรื่อยๆ หลังโดนยิงไป 1 อัน 
						number = number + 1;  // เมื่อยิงโดน ให้เพิ่มค่าscore ทีละ 1 

					}

					else {

						draw_shot(position_x[i], position_y[i]); //จาก  position_y[i] - 1 ถ้ามันยังไม่น้อยกว่า 0 (ต่อข้อความข่างล่าง)
																// มันก็จะวาดอันใหม่ที่ตำแหน่งโดนลบไป 1 แล้วจากด้านบนที่ลบไป

					}

				}
				else // ถ้าเกินให้เซ้ตค่า ตัวรับว่ายิง เป็น 0 เพื่อให้ยินใหม่ได้
				{
					shot[i] = 0;
					erase_shot(position_x[i], position_y[i]);
				}


			}
		}

		Sleep(100);

	} while (ch != 'x');  setcolor(7, 0);


	return 0;
}


char cursor(int x, int y) {
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}

void score(int x, int y) {  // กระดานคะแนนข้างขวา 
	setcolor(7, 4);
	gotoxy(81, 1);
	printf(" ** SCORE ** ");
	setcolor(3, 0);
	gotoxy(80, 2);
	printf("--------------- ");
	gotoxy(80, 3);
	printf("YOUR SCORE : %d ", number); //ให้คะแนนเพิ่มขึ้นเมื่อยินโดน

}

void gotoxy(int x, int y) {    // ตน. ของยาน
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y) {
	setcursor(0);
	gotoxy(x, y);
	setcolor(2, 4);  // เปลี่ยนสีก่อนเริ่มเดิน
	printf("<-0->");

}

void erase_ship(int x, int y) {
	gotoxy(x, y);
	setcolor(0, 0);
	printf("      ");
}

void setcursor(bool visible) {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void erase_shot(int x, int y) {		//ลบรูปกระสุน
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");

}

void draw_shot(int x, int y) {		//วาดรูปกระสุน
	gotoxy(x, y);
	setcolor(7, 0);
	printf("^");
}

void draw_star(int x, int y) {   //วาดดาว
	gotoxy(x, y);
	setcolor(3, 0);
	printf("*");

}

void erase_star(int x, int y) {		//ลบดาว
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}

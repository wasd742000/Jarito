#define _CRT_SECURE_NO_WARNINGS
#include "game.h" 
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define LEFT 3 //khoang cach le trai
#define TOP 1 // Khoang cach le tren
#define N 100 // Do dai list saved game
#define MAX_SIZE_BOARD 13


int boardsize = 12; //Do lon ban co

_POINT _A[MAX_SIZE_BOARD][MAX_SIZE_BOARD]; // Mang toa do ban co
bool _TURN; // luot nguoi choi
int _COMMAND; // Lenh vao
int _X, _Y; // Vi tri toa do console cua o co
int TBL[MAX_SIZE_BOARD][MAX_SIZE_BOARD]; // Ban co va trang thai tung o
int vtx, vty; // Vi tri thuc cua ban co


int nx, no; //so quan co da danh cua X va O
int m = 0, mx = 0, mo = 0; // so tran, so tran thang cua X, O


void size(int & s){
	int pointer = 0;
	mystring size[] = { "6 * 6", "7 * 7", "8 * 8", "9 * 9", "10 * 10", "12 * 12", "13 * 13" };
	while (1){
		system("cls");
		printf("\n\n\n                      KICH THUOC O CO \n\n");
		for (int i = 0; i < 7; i++){
			if (pointer == i){
				TextColor(12);
				printf("\n                         | %s |\n", size[i].str);
			}
			else{
				TextColor(15);
				printf("\n                         %s        \n", size[i].str);
			}
		}
		TextColor(11);
		printf("\n\n\n\n\n\n\n\n\n     ESC: back                                                                                    ENTER: select");
		while (1){
			if (_kbhit()){
				int key = _getch();
				// Phim di len
				if (key == 72){
					if (pointer == 0){
						pointer = 6;
					}
					else{
						pointer--;
					}
					break;
				}
				//Mui ten di xuong
				if (key == 80){
					if (pointer == 6){
						pointer = 0;
					}
					else{
						pointer++;
					}
					break;
				}
				//Phim enter
				if (key == 13){
					switch (pointer){
					case 0:
						s = 6;
						TextColor(12);
						printf("									   ! Ban chon ban co 6 * 6 !            \n");
						Sleep(700);
						break;
					case 1:
						s = 7;
						TextColor(12);
						printf("									   ! Ban chon ban co 7 * 7 !            \n");
						Sleep(700);
						break;
					case 2:
						s = 8;
						TextColor(12);
						printf("									   ! Ban chon ban co 8 * 8 !            \n");
						Sleep(700);
						break;
					case 3:
						s = 9;
						TextColor(12);
						printf("									   ! Ban chon ban co 9 * 9 !            \n");
						Sleep(700);
						break;
					case 4:
						s = 10;
						TextColor(12);
						printf("									   ! Ban chon ban co 10 * 10 !            \n");
						Sleep(700);
						break;
					case 5:
						s = 12;
						TextColor(12);
						printf("									   ! Ban chon ban co 12 * 12 !            \n");
						Sleep(700);
						break;
					case 6:
						s = 13;
						TextColor(12);
						printf("									   ! Ban chon ban co 13 * 13 !            \n");
						Sleep(700);
						break;
					}
					break;
				}
				if (key == 27){
					return;
				}
			}
		}
	}
}

// &c la mau sac tra ve khi nguoi choi lua chon
// Ham menu setting color
void color(int & c){
	int pointer = 0;
	mystring color[] = { "BLUE", "GREEN", "CYAN", "RED", "PINK", "YELLOW", "WHITE" };
	while (1){
		system("cls");
		printf("\n\n\n\n\n");
		for (int i = 0; i < 7; i++){
			if (pointer == i){
				TextColor(i + 9);
				printf("\n                         --->%s<---\n", color[i].str);
			}
			else{
				TextColor(i + 9);
				printf("\n                         %s        \n", color[i].str);
			}
		}
		TextColor(11);
		printf("\n\n\n\n\n\n\n\n\n     ESC: back                                                                                    ENTER: select");
		while (1){
			if (_kbhit()){
				int key = _getch();
				// Phim di len
				if (key == 72){
					if (pointer == 0){
						pointer = 6;
					}
					else{
						pointer--;
					}
					break;
				}
				//Mui ten di xuong
				if (key == 80){
					if (pointer == 6){
						pointer = 0;
					}
					else{
						pointer++;
					}
					break;
				}
				//Phim enter
				if (key == 13){
					switch (pointer){
					case 0:
						c = 9;
						TextColor(c);

						printf("									   !Ban chon mau xanh duong!            \n");
						Sleep(1000);
						break;
					case 1:
						c = 10;
						TextColor(c);

						printf("								       !Ban chon mau xanh la!            \n");
						Sleep(1000);
						break;
					case 2:
						c = 11;
						TextColor(c);

						printf("							           !Ban chon mau xanh cyan!            \n");
						Sleep(1000);
						break;
					case 3:
						c = 12;
						TextColor(c);

						printf("								       !Ban chon mau do!            \n");
						Sleep(1000);
						break;
					case 4:
						c = 13;
						TextColor(c);

						printf("					        			!Ban chon mau hong!            \n");
						Sleep(1000);
						break;
					case 5:
						c = 14;
						TextColor(c);

						printf("							     		!Ban chon mau vang!            \n");
						Sleep(1000);
						break;
					case 6:
						c = 15;
						TextColor(c);

						printf("                                         !Ban chon mau trang!            \n");
						Sleep(1000);
						break;
					}
					break;
				}
				if (key == 27){
					return;
				}
			}
		}
	}
}

//Ham menu settings
//Tra ve kieu setting s
void settings(setting &s){
	int pointer = 0;
	mystring menusetting[] = { "Mau sac cua o caro", "Mau sac cua quan co X", "Mau sac cua quan co O", "Kich thuoc ban co" };
	while (1){
		system("cls");
		printf("\n\n\n\n\n");
		TextColor(14);
		printf("                               SETTINGS\n\n\n");
		TextColor(15);
		for (int i = 0; i < 4; i++){
			if (pointer == i){
				TextColor(12);
				printf("\n                         --->%s<---\n", menusetting[i].str);
			}
			else{
				TextColor(15);
				printf("\n                         %s\n", menusetting[i].str);
			}
		}
		TextColor(11);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n     ESC: back                                                                                    ENTER: select");
		while (1){
			if (_kbhit()){
				int key = _getch();
				if (key == 72){
					if (pointer == 0){
						pointer = 3;
					}
					else{
						pointer--;
					}
					break;
				}
				//Mui ten di xuong
				if (key == 80){
					if (pointer == 3){
						pointer = 0;
					}
					else{
						pointer++;
					}
					break;
				}
				//Phim enter
				if (key == 13){
					switch (pointer){
					case 0:
						color(s.boardc);
						break;
					case 1:
						color(s.xc);
						break;
					case 2:
						color(s.oc);
						break;
					case 3:
						size(boardsize);
						break;
					}
					break;
				}
				if (key == 27){
					return;
				}
			}
		}
	}
}



void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Thay doi mau chu
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Ham xu ly game chinh 
void gamemain(setting s){
	TextColor(s.boardc);
	StartGame();
	scoreboard(s);
	bool validEnter = true;
	while (1){
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27){
			ExitGame();
			return;
		}
		else{

			if (_COMMAND == 'R'){
				gamemain(s);
			}
			else if (_COMMAND == 'L') {
				xlsaveload(1, s);
			}
			else if (_COMMAND == 'T'){
				xlsaveload(0, s);
			}
			else if (_COMMAND == 'A')  MoveLeft();
			else if (_COMMAND == 'W')  MoveUp();
			else if (_COMMAND == 'S')  MoveDown();
			else if (_COMMAND == 'D')  MoveRight();
			else if (_COMMAND == 13){
				Beep(530, 100);
				switch (CheckBoard(_X, _Y)){
				case -1:
					TBL[vtx][vty] = 1;
					nx += 1;
					TextColor(s.xc);
					printf("X");
					scoreboard(s);
					break;
				case 1:
					TBL[vtx][vty] = -1;
					no += 1;
					TextColor(s.oc);
					printf("O");
					scoreboard(s);
					break;
				case 0: validEnter = false;
				}
				if (validEnter == true){
					switch (ProcessFinish(TestBoard(), s)){
					case 1: case -1: case 0:
						if (AskContinue() == 0){
							ExitGame();
						}
						else if (AskContinue() == 1){
							m += 1;
							TextColor(s.boardc);
							StartGame();
							scoreboard(s);
						}
					}
				}
				validEnter = true;
			}
		}



	}
}


// Co dinh size console
void FixConsoleWindow(){
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Chay den vi tri toa do console
void GotoXY(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// Ve bang diem va thong so
void scoreboard(setting s){
	// Ve bang diem
	TextColor(9);
	for (int i = 0; i < 12 * 4 + 12 / 2; i++){
		GotoXY(12 * 5 + i, TOP);
		printf("*");
	}
	for (int i = 0; i < 12 * 4 + 12 / 2; i++){
		GotoXY(12 * 5 + i, TOP + 12);
		printf("_");
	}
	for (int i = 0; i < 12 * 4 + 12 / 2; i++){
		GotoXY(12 * 5 + i, TOP + 12 * 2 + 3);
		printf("*");
	}
	for (int i = 0; i < 12 * 2 + 3; i++){
		GotoXY(12 * 5, TOP + i);
		printf("*");
	}
	for (int i = 0; i < 12; i++){
		GotoXY(12 * 7 + 3.5, TOP + i);
		printf("|");
	}
	for (int i = 0; i <= 12 * 2 + 3; i++){
		GotoXY(12 * 9 + 12 / 2, TOP + i);
		printf("*");
	}
	TextColor(15);
	GotoXY(12 * 5 + 10, TOP + 12 + 2);
	printf("          SO TRAN DA CHOI = %d", m);
	// Thong tin x
	GotoXY(12 * 5 + 1, TOP + 1);
	TextColor(s.xc);
	printf("  _NGUOI CHOI 1 (quan X)_");
	TextColor(15);
	GotoXY(12 * 5 + 1, TOP + 4);
	printf(" +So quan co da danh = %d", nx);
	GotoXY(12 * 5 + 1, TOP + 7);
	printf(" +So tran thang = %d", mx);
	GotoXY(12 * 5 + 1, TOP + 10);
	printf(" +Ti le chien thang = %.0f%%", (float(mx) / m) * 100);
	// Thong tin 0
	GotoXY(12 * 7 + 4.5, TOP + 1);
	TextColor(s.oc);
	printf("  _NGUOI CHOI 2 (quan O)_");
	TextColor(15);
	GotoXY(12 * 7 + 4.5, TOP + 4);
	printf(" +So quan co da danh = %d", no);
	GotoXY(12 * 7 + 4.5, TOP + 7);
	printf(" +So tran thang = %d", mo);
	GotoXY(12 * 7 + 4.5, TOP + 10);
	printf(" +Ti le chien thang = %.0f%%", (float(mo) / m) * 100);
}

// Ve ban co
void DrawBoard(int size){
	for (int i = 0; i <= size * 4; i++){
		for (int j = 0; j <= size * 2; j++){
			if (j % 2 == 0){
				GotoXY(LEFT + i, TOP + j);
				printf("_");
			}
		}
	}
	for (int i = 0; i <= size; i++){
		for (int j = 1; j <= size * 2; j++){
			GotoXY(LEFT + 4 * i, TOP + j);
			printf("|");
		}
	}
	GotoXY(LEFT, TOP + size * 2 + 3);
	TextColor(11);
	printf("ESC: back   R: reset game   L: save game    T:load game");
}

// Xu ly hien thi khi thang/thua/hoa
// 
int ProcessFinish(int pWhoWin, setting s){
	GotoXY(12 * 5 + 10, TOP + 12 + 5);
	switch (pWhoWin){
	case 1:
		mx = mx + 1;
		GotoXY(12 * 5 + 14, TOP + 12 + 5);
		TextColor(46);
		printf("****************************\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 6);
		printf("****************************\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 7);
		printf("******* PLAYER 1 WIN *******\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 8);
		printf("****************************\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 9);
		printf("****************************\n");
		break;
	case -1:
		TextColor(s.oc);
		mo = mo + 1;
		GotoXY(12 * 5 + 14, TOP + 12 + 5);
		TextColor(46);
		printf("****************************\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 6);
		printf("****************************\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 7);
		printf("******* PLAYER 2 WIN *******\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 8);
		printf("****************************\n");
		GotoXY(12 * 5 + 14, TOP + 12 + 9);
		printf("****************************\n");
		break;
	case 0:
		printf("         ! HAI NGUOI CHOI HOA NHAU !\n");
		break;
	case 2:
		_TURN = !_TURN;
		break;
	}
	GotoXY(_X, _Y);
	return pWhoWin;
}

// Hoi nguoi choi co tiep tuc choi
int AskContinue(){
	TextColor(11);
	GotoXY(12 * 5 + 4, TOP + 12 * 2);
	printf("TIEP TUC CHOI ?  ");
	TextColor(46);
	printf("ENTER: tiep tuc");
	TextColor(15);
	printf("  ");
	TextColor(33);
	printf("ESC: thoat");
	while (1){
		int key = _getch();
		if (key == 13){
			return 1;
		}
		if (key == 27){
			TextColor(15);
			return 0;
		}

	}
}



// Reset lai cac du lieu khi start new game
void ResetData(){
	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			_A[i][j].x = 4 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0;
			TBL[i][j] = 0;
		}
	}
	_TURN = true;
	_COMMAND = -1;
	_X = _A[0][0].x;
	_Y = _A[0][0].y;
	vtx = 0; vty = 0;
	nx = 0; no = 0;
}

// Don dep data
void GarbageCollect(){

}


//KT ban co da full 
bool fullboard(){
	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			if (TBL[i][j] == 0){
				return 0;
			}
		}
	}
	return 1;
}



/*
- Ham kiem tra thang, thua, hoa.
- TestBoard tra ve:
1 neu nguoi choi X thang
-1 neu nguoi choi O thang
0 neu 2 nguoi hoa
2 neu khong co gi xay ra
*/
int TestBoard(){
	if (fullboard()){
		return 0;
	}
	for (int i = 0; i < boardsize; i++){
		if (TBL[i][0] == 1 && TBL[i + 1][1] == 1 && TBL[i + 2][2] == 1 && TBL[i + 3][3] == 1 && TBL[i + 4][4] == 1){
			return 1;
		}
		else if (TBL[i][0] == -1 && TBL[i + 1][1] == -1 && TBL[i + 2][2] == -1 && TBL[i + 3][3] == -1 && TBL[i + 4][4] == -1){
			return -1;
		}
		else if (TBL[boardsize - 1][0] == 1 && TBL[boardsize - 2][1] == 1 && TBL[boardsize - 3][2] == 1 && TBL[i + 3][3] == 1 && TBL[i - 4][4] == 1){
			return 1;
		}
		else if (TBL[boardsize - 1][0] == -1 && TBL[boardsize - 2][1] == -1 && TBL[boardsize - 3][2] == -1 && TBL[i + 3][3] == -1 && TBL[i - 4][4] == -1){
			return -1;
		}
		else if (TBL[0][i] == 1 && TBL[1][i + 1] == 1 && TBL[2][i + 2] == 1 && TBL[3][i + 3] == 1 && TBL[4][i + 4] == 1){
			return 1;
		}
		else if (TBL[0][i] == -1 && TBL[1][i + 1] == -1 && TBL[2][i + 2] == -1 && TBL[3][i + 3] == -1 && TBL[4][i + 4] == -1){
			return -1;
		}
	}
	// KT hang ngang
	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			if (i != 0){
				if ((TBL[i][j] != -1 || TBL[i + 6][j] != -1) && (TBL[i + 1][j] == 1 && TBL[i + 2][j] == 1 && TBL[i + 3][j] == 1 && TBL[i + 4][j] == 1 && TBL[i + 5][j] == 1)){
					return 1;
				}
				else if ((TBL[i][j] != 1 || TBL[i + 6][j] != 1) && TBL[i + 1][j] == -1 && TBL[i + 2][j] == -1 && TBL[i + 3][j] == -1 && TBL[i + 4][j] == -1 && TBL[i + 5][j] == -1){
					return -1;
				}
			}
			else {
				if (TBL[i][j] != 0 && TBL[i][j] == TBL[i + 1][j] && TBL[i + 1][j] == TBL[i + 2][j] && TBL[i + 2][j] == TBL[i + 3][j] && TBL[i + 3][j] == TBL[i + 4][j]){
					if (TBL[i][j] == 1){
						return 1;
					}
					else {
						return -1;
					}
				}
			}

		}
	}
	

	// Dem hang doc
	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			
			if (j != 0){
				if ((TBL[i][j] != -1 || TBL[i][j + 6] != -1) && TBL[i][j + 1] == 1 && TBL[i][j + 2] == 1 && TBL[i][j + 3] == 1 && TBL[i][j + 4] == 1 && TBL[i][j + 5] == 1){
					return 1;
				}
				else if ((TBL[i][j] != 1 || TBL[i][j + 6] != 1) && TBL[i][j + 1] == -1 && TBL[i][j + 2] == -1 && TBL[i][j + 3] == -1 && TBL[i][j + 4] == -1 && TBL[i][j + 5] == -1){
					return -1;
				}
			}
			else{
				if (TBL[i][j] != 0 && TBL[i][j] == TBL[i][j + 1] && TBL[i][j + 1] == TBL[i][j + 2] && TBL[i][j + 2] == TBL[i][j + 3] && TBL[i][j + 3] == TBL[i][j + 4]){
					if (TBL[i][j] == 1){
						return 1;
					}
					else {
						return -1;
					}
				}
			}

		}
	}

	// Dem theo cheo chinh 
	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			if ((TBL[i][j] != -1 || TBL[i - 6][j + 6] != -1) && TBL[i - 1][j + 1] == 1 && TBL[i - 2][j + 2] == 1 && TBL[i - 3][j + 3] == 1 && TBL[i - 4][j + 4] == 1 && TBL[i - 5][j + 5] == 1){
				return 1;
			}
			else if ((TBL[i][j] != 1 || TBL[i - 6][j + 6] != 1) && TBL[i - 1][j + 1] == -1 && TBL[i - 2][j + 2] == -1 && TBL[i - 3][j + 3] == -1 && TBL[i - 4][j + 4] == -1 && TBL[i - 5][j + 5] == -1){
				return -1;
			}
		}
	}

	// Dem theo cheo phu

	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			if ((TBL[i][j] != -1 || TBL[i + 6][j + 6] != -1) && TBL[i + 1][j + 1] == 1 && TBL[i + 2][j + 2] == 1 && TBL[i + 3][j + 3] == 1 && TBL[i + 4][j + 4] == 1 && TBL[i + 5][j + 5] == 1){
				return 1;
			}
			else if ((TBL[i][j] != 1 || TBL[i + 6][j + 6] != 1) && TBL[i + 1][j + 1] == -1 && TBL[i + 2][j + 2] == -1 && TBL[i + 3][j + 3] == -1 && TBL[i + 4][j + 4] == -1 && TBL[i + 5][j + 5] == -1){
				return -1;
			}
		}
	}

	return 2;
}




// danh dau vao o co
int CheckBoard(int pX, int pY){
	for (int i = 0; i < boardsize; i++){
		for (int j = 0; j < boardsize; j++){
			//Neu o chua duoc danh
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0){
				if (_TURN == true)	_A[i][j].c = -1; // Luot choi cua X
				else _A[i][j].c = 1; //Luot choi cua O.
				return _A[i][j].c;
			}
		}
	}
	return 0; // O da duoc danh
}


// Control

void StartGame(){
	system("cls");
	ResetData();
	DrawBoard(boardsize);
}

void ExitGame(){
	m = 0; mx = 0; mo = 0;
	GarbageCollect();
}

void MoveRight(){
	if (_X < _A[boardsize - 1][boardsize - 1].x){
		vtx += 1;
		_X += 4;
		GotoXY(_X, _Y);
	}
}

void MoveLeft(){
	if (_X > _A[0][0].x){
		vtx -= 1;
		_X -= 4;
		GotoXY(_X, _Y);
	}
}

void MoveDown(){
	if (_Y < _A[boardsize - 1][boardsize - 1].y){
		vty += 1;
		_Y += 2;
		GotoXY(_X, _Y);
	}
}

void MoveUp(){
	if (_Y > _A[0][0].y){
		vty -= 1;
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

// SAVE va LOAD game

// Giao dien menu load file
void menuload(setting s){
	int nlist, p = 1; // pointer
	mystring list[N];
	FILE *in1 = fopen("number.txt", "r");
	fscanf(in1, "%d", &nlist);
	fclose(in1);
	FILE *in2 = fopen("list.txt", "r");
	printf("\n      LOADING:     ");
	for (int i = 1; i <= nlist; i++){
		fscanf(in2, "%s", list[i].str);
	}
	for (int i = 0; i < 4; i++){
		TextColor(30);
		printf("        %.0f %%            ", (float(i) * 100) / 3);
		Sleep(400);
	}
	TextColor(14);
	printf("\n\n                             LOADING COMPLETE !");
	Sleep(500);
	fclose(in2);
	if (nlist != 0){
		while (1){
			system("cls");
			printf("\n\n\n");
			TextColor(15);
			printf("                      CAC FILE GAME DA LUU       \n\n\n\n\n");
			for (int i = 1; i <= nlist; i++){
				if (p == i){
					TextColor(14);
					printf("\n                      >> GAME SAVE %d: %s", i, list[i].str);
				}
				else{
					TextColor(15);
					printf("\n                      Game save %d:  %s  ", i, list[i].str);
				}
			}
			TextColor(11);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n     ESC: back                                                                                    ENTER: select");
			while (1){
				if (_kbhit()){
					int key = _getch();
					// di len
					if (key == 72){
						if (p == 1){
							p = nlist;
						}
						else{
							p--;
						}
						break;
					}
					// di xuong
					if (key == 80){
						if (p == nlist){
							p = 1;
						}
						else{
							p++;
						}
						break;
					}
					if (key == 27){
						return;
					}
					// Phim enter
					if (key == 13){
						load(list[p].str, s);
						redrawgame(s, list[p].str);
						break;
					}
				}
			}
		}

	}
	else{
		GotoXY(boardsize * 2, boardsize);
		printf("       !!!! CHUA CO GAME DUOC LUU !!!!");
		Sleep(1300);
	}
}

// xu ly cho phan save load
// flag = 1 la save game, flag = 0 la  load game
void xlsaveload(bool flag, setting s){
	int nlist;
	char temp[30];
	system("cls");
	// save
	if (flag){
		GotoXY(boardsize * 2, TOP + boardsize);
		FILE *out = fopen("number.txt", "r");
		fscanf(out, "%d", &nlist);
		fclose(out);
		nlist += 1;
		printf("! Ban vui long save game de tranh mat du lieu !!! :)) \n");
		printf("\n\n                       Nhap ten tap tin luu game(VD: tenfile.txt): ");
		fflush(stdin);
		scanf("%s", &temp);
		FILE *in1 = fopen("number.txt", "w");
		fprintf(in1, "%d\n", nlist);
		fclose(in1);
		FILE *in2 = fopen("list.txt", "a");
		fprintf(in2, "\n%s", temp);
		fclose(in2);
		save(temp, s);
	}
	// load
	else{
		menuload(s);
	}
	return;
}

// save data game vao file
void save(char filename[], setting s){
	FILE *save = fopen(filename, "w");
	if (save == NULL){
		GotoXY(12 * 3, TOP + 12 + 1);
		printf("      !! ERROR: Khong the luu %s !! ", filename);
		return;
	}
	else {
		for (int i = 0; i < boardsize; i++){
			for (int j = 0; j < boardsize; j++){
				fprintf(save, " %d ", _A[i][j].x);
				fprintf(save, " %d ", _A[i][j].y);
				fprintf(save, " %d \n", _A[i][j].c);
			}
		}
		fprintf(save, "\n");
		for (int i = 0; i < boardsize; i++){
			for (int j = 0; j < boardsize; j++){
				fprintf(save, " %d ", TBL[i][j]);
			}
		}
		fprintf(save, "\n");
		fprintf(save, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", _TURN, _COMMAND, _X, _Y, vtx, vty, nx, no, m, mx, mo, s.boardc, s.xc, s.oc, boardsize);
		fclose(save);
	}
}

// load file game da save
void load(char filename[], setting s){
	FILE *load = fopen(filename, "r");
	if (load == NULL){
		GotoXY(12 * 5 + 10, TOP + 12 + 9);
		printf("      !! ERROR: Khong the tai %s !! ", filename);
	}
	else{
		for (int i = 0; i < boardsize; i++){
			for (int j = 0; j < boardsize; j++){
				fscanf(load, "%d", &_A[i][j].x);
				fscanf(load, "%d", &_A[i][j].y);
				fscanf(load, "%d", &_A[i][j].c);
			}
		}
		for (int i = 0; i < boardsize; i++){
			for (int j = 0; j < boardsize; j++){
				fscanf(load, "%d", &TBL[i][j]);
			}
		}
		fscanf(load, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &_TURN, &_COMMAND, &_X, &_Y, &vtx, &vty, &nx, &no, &m, &mx, &mo, &s.boardc, &s.xc, &s.oc, &boardsize);
		fclose(load);
	}
}

// Ve lai game da load
void redrawgame(setting s, char filename[]){
	system("cls");
	_X = LEFT + 2;
	_Y = TOP + 1;
	vtx = 0;
	vty = 0;
	//KT va danh lai o co
	for (int j = 0; j < boardsize; j++){
		for (int i = 0; i < boardsize; i++){
			if (CheckBoard(_X, _Y) == 0){
				switch (TBL[vtx][vty]){
				case 1:
					TextColor(s.xc);
					GotoXY(_X, _Y);
					printf("X");
					break;
				case -1:
					TextColor(s.oc);
					GotoXY(_X, _Y);
					printf("O");
					break;
				default:break;
				}
			}
			MoveRight();
		}
		MoveDown();
		_X = LEFT + 2;
		vtx = 0;
	}
	load(filename, s);
	loadedgame(s);
}


// Start game da load
void loadedgame(setting s){
	TextColor(s.boardc);
	DrawBoard(boardsize);
	scoreboard(s);
	bool validEnter = true;
	while (1){
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27){
			ExitGame();
			return;
		}
		else{
			if (_COMMAND == 'R'){
				gamemain(s);
			}
			else if (_COMMAND == 'L') {
				xlsaveload(1, s);
			}
			else if (_COMMAND == 'T'){
				xlsaveload(0, s);
			}
			else if (_COMMAND == 'A')  MoveLeft();
			else if (_COMMAND == 'W')  MoveUp();
			else if (_COMMAND == 'S')  MoveDown();
			else if (_COMMAND == 'D')  MoveRight();
			else if (_COMMAND == 13){
				Beep(530, 100);
				switch (CheckBoard(_X, _Y)){
				case -1:
					TBL[vtx][vty] = 1;
					nx += 1;
					TextColor(s.xc);
					printf("X");
					scoreboard(s);
					break;
				case 1:
					TBL[vtx][vty] = -1;
					no += 1;
					TextColor(s.oc);
					printf("O");
					scoreboard(s);
					break;
				case 0: validEnter = false;
				}
				if (validEnter == true){
					switch (ProcessFinish(TestBoard(), s)){
					case 1: case -1: case 0:
						if (AskContinue() == 0){
							ExitGame();
						}
						else if (AskContinue() == 1){
							m += 1;
							TextColor(s.boardc);
							StartGame();
							scoreboard(s);
						}
					}
				}
				validEnter = true;
			}
		}
	}
}

// 24/11 STUCK AT SAVE AND LOAD GAME, PRINTF LOADMENU AND SAVELOAD FUNCTION
// 25/11 STUCK AT RELOADED GAME 
// 26/11 sthing wrong with menuload
// COMPLETE

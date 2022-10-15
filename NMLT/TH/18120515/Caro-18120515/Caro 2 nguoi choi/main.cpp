#include "game.h"

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define MAXMENU 5

#define ColorCode_Black			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15






//In phan about author
void about(){
	char s[1000];
	strcpy(s, "NAME: Vu Hong Phuc\n                       Truong DH KHTN, DHQG TP.HCM (HCMUS)\n                       STUDENT ID NUMBER: 18120515\n                       CLASS: 18CTT1TN\n                       Email: wasd742000@gmail.com");
	system("cls");
	printf("\n\n\n");
	TextColor(10);
	printf("                        ABOUT AUTHOR\n\n\n");
	TextColor(15);
	printf("                       %s\n\n", s);
	TextColor(11);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n     ESC: back                                                                                    ");
	while (1){
		if (_kbhit()){
			int key = _getch();
			if (key == 27){
				break;
			}
		}
	}
}

// In phan huong dan
void help(){
	system("cls");
	printf("\n\n\n\n");
	TextColor(13);
	printf("                     HELP\n\n\n");
	TextColor(15);
	printf("             - Trong menu: su dung cac phim mui ten len/xuong va phim Enter de chon, phim ESC de tro ve.\n\n");
	printf("             - Trong game: \n                  + Cac phim W, A, S, D de di chuyen quan co.\n                  + Enter de chon quan co.\n                  + Phim L de save game, phim T de tai game.\n                  + Phim ESC de tro ve MENU.");
	printf("\n\n             - Luat choi:  \n                  + Hai nguoi choi thay phien dat quan co cua minh, moi luot di chi duoc ra mot quan co.");
	printf("                                  + Nguoi dau tien co duoc mot chuoi lien tuc gom 5 quan hang ngang/ doc/ cheo la nguoi chien thang.");
	TextColor(11);
	printf("\n\n\n\n\n\n\n\n\n\n\n     ESC: back                                                                                    ");
	while (1){
		if (_kbhit()){
			int k = _getch();
			if (k == 27){
				break;
			}
		}
	}
}

// Ham menu xu ly chinh
int main(){
	resizeConsole(1000, 550);
	FixConsoleWindow();
	mystring menu[] = { "START NEW GAME", "LOAD SAVED GAME", "SETTINGS", "HELP", "ABOUT AUTHOR", "EXIT" };
	int pointer = 0;
	setting s;
	s.boardc = 15; 
	s.xc = 15;
	s.oc = 15;
	while (1){
		system("cls");
		TextColor(9);
		printf("\n\n");
		printf("            X     X                    _______     ________     ________     ________                  OOOOO           \n");
		printf("             X   X                    / _____/\\   / ____  /\\   / ____  /\\   / ____  /\\                O     O       \n");
		printf("              X X                    / /\\____\\/  / /\\__/ / /  / /___/ / /  / /\\__/ / /                O     O       \n");
		printf("               X                    / / /       / /_/_/ / /  / _   __/ /  / / / / / /                 O     O      \n");
		printf("              X X                  / /_/__     / ____  / /  / / \\ \\__\\/  / /_/_/ / /                  O     O       \n");
		printf("             X   X                /______/\\   /_/\\__/_/ /  /_/ / \\_\\    /_______/ /                   O     O      \n");
		printf("            X     X               \\______\\/   \\_\\/  \\_\\/   \\_\\/   \\_\\   \\_______\\/                     OOOOO       \n");

		printf("\n\n");
		TextColor(12);
		printf("                                         _______CO CARO 2 NGUOI CHOI_______\n");
		TextColor(10);
		printf("\n              Chu y: tat cac phan mem ho tro go dau(VD: Unikey) de tranh xung dot khi choi !!");
		printf("\n\n\n\n");
		for (int i = 0; i <= MAXMENU; i++){
			if (pointer == i){
				TextColor(14);
				printf("                         --> %s <--\n", menu[i].str);
			}
			else{
				TextColor(15);
				printf("                         %s\n", menu[i].str);
			}
		}
		TextColor(11);
		printf("\n\n\n\n\n                                                                                                  ENTER: select");
		while (1){
			if (_kbhit()){
				char key = _getch();
				//Mui ten di len
				if (key == 72){
					if (pointer == 0){
						pointer = MAXMENU;
					}
					else{
						pointer--;
					}
					break;
				}
				//Mui ten di xuong
				if (key == 80){
					if (pointer == MAXMENU){
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
						gamemain(s);
						break;
					case 1:
						xlsaveload(0, s);
						break;
					case 2:
						settings(s);
						break;
					case 3:
						help();
						break;
					case 4:
						about();
						break;
					case 5:
						return 0;
						break;
					}
					break;
				}
			}
		}
	}
	return 0;
}


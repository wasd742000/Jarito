struct setting{
	int boardc, xc, oc, bsize; // mau sac o co, co X, co O mac dinh = 15, kich thuoc o co;
};

struct _POINT{
	int x, y, c;
};

struct mystring{
	char str[30];
};


void size(int & s);
void color(int & c);
void settings(setting &s);
void resizeConsole(int width, int height);
void scoreboard(setting s);
void TextColor(int color);
void gamemain(setting s);
int TestBoard();
void FixConsoleWindow();
void resizeConsole(int width, int height);
void GotoXY(int x, int y);
void DrawBoard(int size);
int ProcessFinish(int pWhoWin, setting s);
int AskContinue();
void ResetData();
void GarbageCollect();
int CheckBoard(int pX, int pY);
void StartGame();
void ExitGame();
void MoveRight();
void MoveLeft();
void MoveUp();
void MoveDown();
void xlsaveload(bool flag, setting s);
void save(char filename[], setting s);
void load(char filename[], setting s);
void menuload(setting s);

void redrawgame(setting s, char filename[]);
void loadedgame(setting s);
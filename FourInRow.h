#define ROW 6
#define COL 7

void playGame(char a[ROW][COL]);
void printBoard(char a[ROW][COL]);
int checkWin(char a[ROW][COL], int row, int col, char y);
int checkHor(char a[ROW][COL], int row, int col, char y);
int checkVer(char a[ROW][COL], int row, int col, char y);
int checkDiag(char a[ROW][COL], int row, int col, char y);


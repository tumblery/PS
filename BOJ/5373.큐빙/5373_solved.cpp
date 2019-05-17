#include<stdio.h>
#include<memory.h>
#define r 'r'
#define w 'w'
#define y 'y'
#define o 'o'
#define g 'g'
#define b 'b'
#define n ' '
const char S_CUBE[9][12] =
{
	{ n,n,n,o,o,o,n,n,n,n,n,n },
	{ n,n,n,o,o,o,n,n,n,n,n,n },//1
	{ n,n,n,o,o,o,n,n,n,n,n,n },
	{ g,g,g,w,w,w,b,b,b,y,y,y },
	{ g,g,g,w,w,w,b,b,b,y,y,y },//2 3 4 5
	{ g,g,g,w,w,w,b,b,b,y,y,y },
	{ n,n,n,r,r,r,n,n,n,n,n,n },
	{ n,n,n,r,r,r,n,n,n,n,n,n },//6
	{ n,n,n,r,r,r,n,n,n,n,n,n }
};

char CUBE[9][12];
int map[6][8][2] = {
	{{3,3},{3,4},{3,5},{4,5},{5,5},{5,4},{5,3},{4,3}},
	{{3,6},{3,7},{3,8},{4,8},{5,8},{5,7},{5,6},{4,6}},
	{{3,9},{3,10},{3,11},{4,11},{5,11},{5,10},{5,9},{4,9}},
	{{3,0},{3,1},{3,2},{4,2},{5,2},{5,1},{5,0},{4,0}},
	{{0,3},{0,4},{0,5},{1,5},{2,5},{2,4},{2,3},{1,3}},
	{{6,3},{6,4},{6,5},{7,5},{8,5},{8,4},{8,3},{7,3}}
};
int list[6][12][2] = {
	{ { 2,3 },{ 2,4 },{ 2,5 },{ 3,6 },{ 4,6 },{ 5,6 },{ 6,5 },{ 6,4 },{ 6,3 },{ 5,2 },{ 4,2 },{ 3,2 } },//U
	{ { 2,5 },{ 1,5 },{ 0,5 },{ 3,9 },{ 4,9 },{ 5,9 },{ 8,5 },{ 7,5 },{ 6,5 },{ 5,5 },{ 4,5 },{ 3,5 } },//R
	{ { 0,5 },{ 0,4 },{ 0,3 },{ 3,0 },{ 4,0 },{ 5,0 },{ 8,3 },{ 8,4 },{ 8,5 },{ 5,8 },{ 4,8 },{ 3,8 } },//D
	{ { 0,3 },{ 1,3 },{ 2,3 },{ 3,3 },{ 4,3 },{ 5,3 },{ 6,3 },{ 7,3 },{ 8,3 },{ 5,11 },{ 4,11 },{ 3,11 } },//L
	{ { 3,11 },{ 3,10 },{ 3,9 },{ 3,8 },{ 3,7 },{ 3,6 },{ 3,5 },{ 3,4 },{ 3,3 },{ 3,2 },{ 3,1 },{ 3,0 } },//B
	{ { 5,3 },{ 5,4 },{ 5,5 },{ 5,6 },{ 5,7 },{ 5,8 },{ 5,9 },{ 5,10 },{ 5,11 },{ 5,0 },{ 5,1 },{ 5,2 } }//F
};

void print() {
	for (int i = 3; i < 6; i++) {
		for (int j = 3; j < 6; j++) {
			printf("%c", CUBE[i][j]);
		}
		printf("\n");
	}
}
void clock(int wh) {//¹«½¼ ¸éÀ»? wh
	for (int i = 0; i < 3; i++) {
		int first = CUBE[list[wh][11][0]][list[wh][11][1]];
		for (int j = 10; j >= 0; j--) {
			CUBE[list[wh][j + 1][0]][list[wh][j + 1][1]] = CUBE[list[wh][j][0]][list[wh][j][1]];
		}
		CUBE[list[wh][0][0]][list[wh][0][1]] = first;
	}
	for (int i = 0; i < 2; i++) {
		int first = CUBE[map[wh][7][0]][map[wh][7][1]];
		for (int j = 6; j >= 0; j--) {
			CUBE[map[wh][j + 1][0]][map[wh][j + 1][1]] = CUBE[map[wh][j][0]][map[wh][j][1]];
		}
		CUBE[map[wh][0][0]][map[wh][0][1]] = first;
	}
}
void cnt_clock(int wh) {
	for (int i = 0; i < 3; i++) {
		int first = CUBE[list[wh][0][0]][list[wh][0][1]];
		for (int j = 1; j < 12; j++) {
			CUBE[list[wh][j - 1][0]][list[wh][j - 1][1]] = CUBE[list[wh][j][0]][list[wh][j][1]];
		}
		CUBE[list[wh][11][0]][list[wh][11][1]] = first;
	}

	for (int i = 0; i < 2; i++) {
		int first = CUBE[map[wh][0][0]][map[wh][0][1]];
		for (int j = 1; j < 8; j++) {
			CUBE[map[wh][j - 1][0]][map[wh][j - 1][1]] = CUBE[map[wh][j][0]][map[wh][j][1]];
		}
		CUBE[map[wh][7][0]][map[wh][7][1]] = first;
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int k;
		scanf("%d", &k);
		getchar();
		memcpy(CUBE, S_CUBE, sizeof(S_CUBE));
		while (k--) {
			char wh, op;
			scanf("%c%c", &wh, &op);
			getchar();
			int W, O;
			switch (wh)
			{
			case 'U':
				W = 0;
				break;
			case 'R':
				W = 1;
				break;
			case 'D':
				W = 2;
				break;
			case 'L':
				W = 3;
				break;
			case 'B':
				W = 4;
				break;
			case 'F':
				W = 5;
				break;
			default:
				break;
			}
			switch (op)
			{
			case '+':
				clock(W);
				break;
			case '-':
				cnt_clock(W);
				break;
			default:
				break;
			}
		}
		print();
	}
	return 0;
}
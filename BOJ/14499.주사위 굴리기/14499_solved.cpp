#include<stdio.h>
#include<memory.h>
#define MAX_Map 20
int dir[5][2] = {
	{0,0},
	{0,1},
	{0,-1},
	{-1,0},
	{1,0}
};
int up[2] = { 1,1 };
int bottom[2] = { 3,1 };
int jusa[5][4][3][2] = {
	{ {{0,0},{0,1},{0,2}},
	{{1,0},{1,1},{1,2}},
	{{2,0},{2,1},{2,2}},
	{{3,0},{3,1},{3,2}},
	},
	{
		{{ 0,0 },{ 0,1 },{ 0,2 }},
		{{ 3,1},{ 1,0 },{ 1,1 }},
		{{ 2,0 },{ 2,1 },{ 2,2 }},
		{{ 3,0 },{ 1,2 },{ 3,2 }},
    },
	{ { { 0,0 },{ 0,1 },{ 0,2 } },
	{ { 1,1 },{ 1,2 },{ 3,1 } },
	{ { 2,0 },{ 2,1 },{ 2,2 } },
	{ { 3,0 },{ 1,0 },{ 3,2 } },
	},
	{ { { 0,0 },{ 1,1 },{ 0,2 } },
	{ { 1,0 },{ 2,1 },{ 1,2 } },
	{ { 2,0 },{ 3,1 },{ 2,2 } },
	{ { 3,0 },{ 0,1 },{ 3,2 } },
	},
	{ { { 0,0 },{ 3,1 },{ 0,2 } },
	{ { 1,0 },{ 0,1 },{ 1,2 } },
	{ { 2,0 },{ 1,1 },{ 2,2 } },
	{ { 3,0 },{ 2,1 },{ 3,2 } },
	},
};
int map[MAX_Map][MAX_Map];
int my_j[4][3] = { 0, };
void lotation_ju(int mod) {
	int tmp;
	int next_j[4][3];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			next_j[i][j] = my_j[jusa[mod][i][j][0]][jusa[mod][i][j][1]];
		}
	}
	memcpy(my_j, next_j, sizeof(next_j));
}
int main() {
	int N, M;
	int X, Y, K;
	scanf("%d%d%d%d%d", &N, &M, &X, &Y, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	}
	int direction;
	for (int i = 0; i < K; i++) {
		scanf("%d", &direction);
		X += dir[direction][0];
		Y += dir[direction][1];
		if (X < 0 || X >= N || Y < 0 || Y >= M) {
			X -= dir[direction][0];
			Y -= dir[direction][1];
			continue;
		}
		lotation_ju(direction);
		if (map[X][Y] == 0) {
			map[X][Y] = my_j[bottom[0]][bottom[1]];
		}
		else {
			my_j[bottom[0]][bottom[1]] = map[X][Y];
			map[X][Y] = 0;
		}
		printf("%d\n", my_j[up[0]][up[1]]);
	}
	return 0;
}
#include<stdio.h>
#include<memory.h>
int cctv[6][4][4][2] = {
	{//방바닥
		{
			{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
		},
		{
			{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
		},
		{
			{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
		},
		{
			{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
		}
},
{//CCTV 1
	{//오른쪽 보기
		{ 0,1 },{ 0,0 },{ 0,0 },{ 0,0 }
	},
	{//아래보기
		{ 1,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	},
	{//왼쪽 보기
		{ 0,-1 },{ 0,0 },{ 0,0 },{ 0,0 }
	},
	{//위로 보기
		{ -1,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	}
}
,
{//CCTV 2
	{//위,아래
		{ 1,0 },{ -1,0 },{ 0,0 },{ 0,0 }
	},
	{//왼,오
		{ 0,1 },{ 0,-1 },{ 0,0 },{ 0,0 }
	},
	{
		{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	},
	{
		{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	}
}
,
{//CCTV 3
	{//위,오
		{ -1,0 },{ 0,1 },{ 0,0 },{ 0,0 }
	},
	{//오,아래
		{ 0,1 },{ 1,0 },{ 0,0 },{ 0,0 }
	},
	{//아래,왼
		{ 1,0 },{ 0,-1 },{ 0,0 },{ 0,0 }
	},
	{//왼,위
		{ 0,-1 },{ -1,0 },{ 0,0 },{ 0,0 }
	}
}
,
{//CCTV 4
	{//오,위,왼
		{ 0,1 },{ -1,0 },{ 0,-1 },{ 0,0 }
	},
	{//위,오,아래
		{ -1,0 },{ 0,1 },{ 1,0 },{ 0,0 }
	},
	{//오,아래,왼
		{ 0,1 },{ 1,0 },{ 0,-1 },{ 0,0 }
	},
	{//아래,왼,위
		{ 1,0 },{ 0,-1 },{ -1,0 },{ 0,0 }
	}
}
,
{//CCTV 5
	{//all
		{ -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 }
	},
	{
		{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	},
	{
		{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	},
	{
		{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }
	}
}
};
int N, M, ans;
int cctv_size[6] = { 0,4,2,4,4,1 };
int map[8][8];
int CCTV[8][4];//0,1:i,j 2:dir, 3 kind
int cctv_N;
int min_(int a, int b) {
	return a < b ? a : b;
}
void set_CCTV() {
	int map_t[8][8];
	memcpy(map_t, map, sizeof(map));
	for (int i = 0; i < cctv_N; i++) {
		int kind = CCTV[i][3];
		int mod = CCTV[i][2];
		int x = CCTV[i][0];
		int y = CCTV[i][1];
		for (int j = 0; j < 4; j++) {
			if (cctv[kind][mod][j][0] + cctv[kind][mod][j][1] == 0)break;
			x = CCTV[i][0] + cctv[kind][mod][j][0];
			y = CCTV[i][1] + cctv[kind][mod][j][1];
			while (map[x][y] != 6 && (x >= 0 && x < N) && (y >= 0 && y < M)) {
				if(map_t[x][y] == 0)
					map_t[x][y] = 7;
				x += cctv[kind][mod][j][0];
				y += cctv[kind][mod][j][1];
			}
		}
	}
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map_t[i][j] == 0)tmp++;
		}
	}
	ans = min_(ans, tmp);
}
void rotate_CCTV(int idx) {
	if (idx == cctv_N) {
		return set_CCTV();
	}
	int  n = cctv_size[CCTV[idx][3]];
	for (int i = 0; i < n; i++) {
		CCTV[idx][2] = i;
		rotate_CCTV(idx + 1);
	}
}

int main() {
	cctv_N = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				CCTV[cctv_N][0] = i;
				CCTV[cctv_N][1] = j;
				CCTV[cctv_N][3] = map[i][j];
				cctv_N++;
			}
		}
	}
	ans = 64;
	rotate_CCTV(0);
	printf("%d", ans);
	return 0;
}

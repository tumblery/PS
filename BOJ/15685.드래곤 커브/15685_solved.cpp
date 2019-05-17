#include<stdio.h>
#include<vector>
#include<memory.h>
using namespace std;

typedef struct info{
	int sx, sy;
	int dx, dy;
	int d;
};

int dir[4][2] = {
	{0,1},
	{-1,0},
	{0,-1},
	{1,0}
};
int clock_dir[4] = { 3,0,1,2 };
int reverse_dir[4] = { 2,3,0,1 };
bool map[101][101] = { false };
char d[101][101];
vector<info> dragon;
int cnt_ans() {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])cnt++;
		}
	}
	return cnt;
}
void set_map() {
	for (int i = 0; i < dragon.size(); i++) {
		map[dragon[i].sx][dragon[i].sy] = true;
		map[dragon[i].dx][dragon[i].dy] = true;
	}
}
void set_debug() {
	memset(d, 'X', sizeof(d));
	for (int i = 0; i < dragon.size(); i++) {
		d[dragon[i].sx][dragon[i].sy] = 'O';
		d[dragon[i].dx][dragon[i].dy] = 'O';
	}
}
void gogo(int now, int goal) {
	if (now == goal) {
		return set_map();
	}
	int size = dragon.size();
	for (int i = size - 1; i >= 0; i--) {
		info tmp = dragon.back();
		info next;
		next.sx = tmp.dx;
		next.sy = tmp.dy;
		next.d = clock_dir[dragon[i].d];
		next.dx = next.sx + dir[next.d][0];
		next.dy = next.sy + dir[next.d][1];
		next.d = reverse_dir[clock_dir[dragon[i].d]];
		dragon.push_back(next);
	}
	set_debug();
	gogo(now + 1, goal);
}

int main() {
	int N, x, y, di, g;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &y, &x, &di, &g);
		dragon.clear();
		info tmp;
		tmp.sx = x;
		tmp.sy = y;
		tmp.dx = x + dir[di][0];
		tmp.dy = y + dir[di][1];
		tmp.d = reverse_dir[di];
		dragon.push_back(tmp);
		gogo(0, g);
	}
	printf("%d", cnt_ans());
}
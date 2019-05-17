#include<stdio.h>

int map[100][100] = { 0, };

int main() {
	int N, x, y;
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (map[x + j][y + k] == 1)continue;
				map[x + j][y + k] = 1;
				ans++;
			}
		}
	}
	printf("%d", ans);
}
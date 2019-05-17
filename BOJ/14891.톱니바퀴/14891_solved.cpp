#include<stdio.h>

int tobni[4][8];
int K;

void turn_clock(int where_) {
	int Z_time = tobni[where_][7];
	for (int i = 7; i > 0; i--) {
		tobni[where_][i] = tobni[where_][i - 1];
	}
	tobni[where_][0] = Z_time;
}
void turn_aclock(int where_) {
	int Z_time = tobni[where_][0];
	for (int i = 0; i < 7; i++) {
		tobni[where_][i] = tobni[where_][i + 1];
	}
	tobni[where_][7] = Z_time;
}
int calc_score() {
	int ans = 0;
	for (int i = 3; i >= 0; i--) {
		ans = (ans << 1) + tobni[i][0];
	}
	return ans;
}
void get_command(int where_, int mode) {
	switch (mode)
	{
	case 1:
		turn_clock(where_);
		break;
	case -1:
		turn_aclock(where_);
		break;
	default:
		break;
	}
	return;
}
int main() {
	char input[10] = { 0, };
	for (int i = 0; i < 4; i++) {
		scanf("%s", input);
		for (int j = 0; j < 8; j++) {
			if (input[j] == '0')tobni[i][j] = 0;
			else if (input[j] == '1')tobni[i][j] = 1;
		}
	}
	int K;
	scanf("%d", &K);
	for (int o = 0; o < K; o++) {
		int c_w, c_m;
		int ops[4] = { 0, };
		scanf("%d%d", &c_w, &c_m);
		c_w--;
		ops[c_w] = c_m;
		for (int i = c_w; i > 0; i--) {
			if (tobni[i][6] != tobni[i - 1][2]) {
				ops[i - 1] = ops[i] * -1;
			}
		}
		for (int i = (c_w+1); i < 4; i++) {
			if (tobni[i - 1][2] != tobni[i][6]) {
				ops[i] = ops[i - 1] * -1;
			}
		}
		for (int i = 0; i < 4; i++) {
			get_command(i, ops[i]);
		}
	}
	printf("%d", calc_score());
}


#include<stdio.h>
#include<memory.h>
bool sadari[30][10][2];//sadari[i][a][0] : i��° ��ٸ��� i-1��° ��ٸ��� a���ο� ����Ǿ� �ִ°�
						//sadari[i][a][1] : i��° ��󸮰� i+1��° ��ٸ��� a���ο� ����Ǿ� �ִ°�
int N, H, M;
bool test() {
	
	for (int i = 0; i < N; i++) {
		int now = i;
		for (int j = 0; j < H; j++) {
			if (sadari[j][now][0] == true) {
				now = now - 1;
			}
			else if (sadari[j][now][1] == true) {
				now = now + 1;
			}
		}
		if (now != i)return false;
	}
	return true;
}
bool flag;
void set_sadari(int remind, int idx) {
	if (flag)return;
	if (remind == 0) {
		if (test())
			flag = true;
		return;
	}
	if (idx >= N*H)return;
	set_sadari(remind, idx + 1);
	if (idx%N == 0) {
		if (sadari[idx / N][idx%N][1] == false) {//0->1�ΰ��� ���μ��� ������Ѵ�.
			if (sadari[idx / N][idx%N + 1][1] == false) {//1->2�� ���� ���μ��� ������Ѵ�.
				sadari[idx / N][idx%N][1] = true;
				sadari[idx / N][idx%N + 1][0] = true;
				set_sadari(remind - 1, idx + 1);
				sadari[idx / N][idx%N][1] = false;
				sadari[idx / N][idx%N + 1][0] = false;
			}
		}
		return;
	}
	if (idx%N == N - 2) {
		if (sadari[idx / N][idx%N][0] == false && sadari[idx/N][idx%N][1] == false) {
			sadari[idx / N][idx%N][1] = true;
			sadari[idx / N][idx%N+1][0] = true;
			set_sadari(remind - 1, idx + 1);
			sadari[idx / N][idx%N][1] = false;
			sadari[idx / N][idx%N+1][0] = false;

		}
		return;
	}
	if (idx%N == N - 1)return;
	if (sadari[idx / N][idx%N][0] == false) {
		if (sadari[idx / N][idx%N][1] == false) {
			if (sadari[idx / N][idx%N + 1][1] == false) {
				sadari[idx / N][idx%N][1] = true;
				sadari[idx / N][idx%N + 1][0] = true;
				set_sadari(remind - 1, idx + 1);
				sadari[idx / N][idx%N][1] = false;
				sadari[idx / N][idx%N + 1][0] = false;
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &N, &M, &H);
	memset(sadari, false, sizeof(sadari));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		b--;
		a--;
		sadari[a][b][1] = true;
		sadari[a][b+1][0] = true;
	}
	int ans = -1;
	flag= false;
	for (int i = 0; i <= 3; i++) {
		set_sadari(i, 0);
		if (flag) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}

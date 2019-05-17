#include<stdio.h>

int money[6] = { 500,100,50,10,5,1 };

int main() {
	int ans, total;
	ans = 0;
	scanf("%d", &total);
	total = 1000 - total;
	for (int i = 0; i < 6; i++) {
		while (total > 0) {
			total -= money[i];
			ans++;
		}
		if (total < 0) {
			total += money[i];
			ans--;
		}
		else if (total == 0) {
			break;
		}
	}
	printf("%d", ans);
}
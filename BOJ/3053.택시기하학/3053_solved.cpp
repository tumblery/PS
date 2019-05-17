#include<stdio.h>
#define M_PI 3.14159265358979323846
int main() {
	int r;
	scanf("%d", &r);
	double a = r*r*M_PI;
	double b = r*r * 2;
	printf("%0.6lf\n%0.6lf", a, b);
}
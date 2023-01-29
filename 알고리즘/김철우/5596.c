#include<stdio.h>
int main() {
	int a[5] = { 0 }, b[5] = { 0 };
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i < 4; i++) {
		scanf("%d ", &a[i]);
		sum1 += a[i];
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &b[i]);
		sum2 += b[i];
	}
	if (sum1 < sum2) printf("%d", sum2);
	else printf("%d", sum1);
}

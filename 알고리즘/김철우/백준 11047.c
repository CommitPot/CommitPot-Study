#include<stdio.h>
#include<stdlib.h>
int main() {
	int a, b, r = 0;
	int arr[11];
	scanf("%d %d", &a, &b);
	for (int i = a - 1; i >= 0; i--) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < a; i++) {
		r += b / arr[i];
		b %= arr[i];
	}
	printf("%d", r);
	return 0;
}

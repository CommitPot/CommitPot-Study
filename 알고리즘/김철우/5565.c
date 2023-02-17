#include<stdio.h>
int main() {
	int n, sum = 0;
	int arr[9];
	scanf("%d", &n);
	for (int i = 0; i < 9; i++) {
		scanf("%d\n", &arr[i]);
		sum += arr[i];
	}
	printf("%d", n - sum);
}

#include<stdio.h>
int main() {
	int a = 0;
	
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) {
		for (int j = a-i; j > 0; j--) {
			printf(" ");
		}
		for (int k = 0; k < 2*i-1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

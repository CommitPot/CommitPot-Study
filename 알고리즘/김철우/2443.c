#include<stdio.h>
int main() {
	int a = 0;
	
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j < i; j++) {
			printf(" ");
		}
		for (int k = 2*a-i; k >= i; k--) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

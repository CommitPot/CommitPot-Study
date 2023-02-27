#include<stdio.h>
int main() {
	int a, b,c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", (a + b) % c);
	printf("%d\n", ((a%c)+(b%c))%c);
	printf("%d\n", (a * b) % c);
	printf("%d", ((a % c) * (b % c)) % c);
}

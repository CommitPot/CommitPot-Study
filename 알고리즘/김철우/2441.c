#include<stdio.h>
int main() {
    int a = 0;
    scanf_s("%d", &a);

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= i-1 ; j++) {
            printf(" ");
        }
        for (int j = 1; j <= a - i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

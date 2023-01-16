#include<stdio.h>
int main() {
    int a = 0;
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - i ; j++) {
            printf("*");
        }
        printf("\n");
    }
}

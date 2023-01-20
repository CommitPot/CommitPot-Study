#include<stdio.h>
int main() {
    int a = 0;
    scanf_s("%d", &a);

    for(int i = 0; i < a; i++) {
        for (int j = 0; j < a-i-1; j++) {
            printf(" ");
        }
        for (int k = a-i; k <= a; k++) {
            printf("*");
        }
        printf("\n");
    }
    
}

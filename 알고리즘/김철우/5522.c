#include<stdio.h>
int main() {
    int a,sum = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d\n", &a);
        sum += a;
    }
    printf("%d", sum);
    
} 

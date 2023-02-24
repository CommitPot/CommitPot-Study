#include <stdio.h>

int main() {
    int a = 0, b = 0;

    scanf("%d %d", &a, &b);

    if(a < 2) {
        printf("Before");
    }
    else if(a > 2) {
        printf("After");
    }
    else if(a == 2){
        if(b == 18) {
            printf("Special");
        }
        if(b < 18) {
            printf("Before");
        }
        if(b > 18) {
            printf("After");
        }
    }
}

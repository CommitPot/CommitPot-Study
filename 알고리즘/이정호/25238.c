#include <stdio.h>

int main() {
    int a = 0, b= 0;

    scanf("%d %d", &a, &b);

    if(a * (100 - b) / 100 >= 100) {
        printf("0");
    }
    else {
        printf("1");
    }
}

#include <stdio.h>

int c(int b) {
    return b < 0 ? b * -1 : b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b){
        int t = a;
        a = b;
        b = t;
    }
    printf("%d", (b - 1) / 4 - (a - 1) / 4 + c((b - 1) % 4 - (a - 1) % 4));
}

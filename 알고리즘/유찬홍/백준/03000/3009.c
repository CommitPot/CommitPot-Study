#include <stdio.h>

int main() {
    int a = 0, b = 0;
    for (int i = 0, c, d; i < 3; i++) {
        scanf("%d %d", &c, &d);
        a ^= c;
        b ^= d;
    }
    printf("%d %d", a, b);
}

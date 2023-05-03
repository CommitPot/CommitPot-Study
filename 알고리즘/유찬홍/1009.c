#include <stdio.h>

int main() {
    int t, a, b;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        int a1 = a, c;
        c = b % 4 == 0 ? 4 : b % 4;
        for (int j = 1; j < c; j++) {
            a *= a1;
        }
        printf("%d\n", a % 10 == 0 ? 10 : a % 10);
    }
}

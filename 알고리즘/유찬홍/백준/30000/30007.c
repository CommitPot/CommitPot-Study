#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", a * (c - 1)+ b);
    }
}

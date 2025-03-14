#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        int x = a + b;
        printf("%d\n", x * (x * (x + 1) / 2 - x));
    }
}

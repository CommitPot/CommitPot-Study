#include <stdio.h>

int main() {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        r = r < a * b ? a * b : r;
    }
    printf("%d", r);
}

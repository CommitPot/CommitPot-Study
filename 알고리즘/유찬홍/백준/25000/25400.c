#include <stdio.h>

int main() {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) scanf("%d", &j), r += r == --j;
    printf("%d", n - r);
}

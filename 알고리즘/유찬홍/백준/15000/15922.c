#include <stdio.h>

int main() {
    int n, s = -1e9 - 1, e = -1e9 - 1, r = 0;
    scanf("%d", &n);
    for (int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (e < a) r += e - s, s = a, e = b;
        else if (b > e) e = b;
    }
    printf("%d", r + e - s);
}

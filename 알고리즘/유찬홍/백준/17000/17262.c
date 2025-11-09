#include <stdio.h>

int main() {
    int n, s = 1e9, e = 0;
    scanf("%d", &n);
    for (int i = 0, b, c; i < n; i++) {
        scanf("%d %d", &b, &c);
        if (c < s) s = c;
        if (b > e) e = b;
    }
    printf("%d", s < e ? e - s : 0);
}

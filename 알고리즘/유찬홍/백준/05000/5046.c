#include <stdio.h>

int main() {
    int n, b, h, w, r = 1e9;
    scanf("%d %d %d %d", &n, &b, &h, &w);
    for (int i = 0, a; i < h; i++) {
        scanf("%d", &a);
        for (int j = 0, c; j < w; j++) {
            scanf("%d", &c);
            if (c >= n && a * c <= b) r = r < a * n ? r : a * n;
        }
    }
    r == 1e9 ? printf("stay home") : printf("%d", r);
}

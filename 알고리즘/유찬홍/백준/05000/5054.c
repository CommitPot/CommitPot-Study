#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int b = 1e9, c = -1;
        for (int i = 0, a; i < n; i++) {
            scanf("%d", &a);
            b = b > a ? a : b;
            c = c < a ? a : c;
        }
        printf("%d\n", (c - b) * 2);
    }
}

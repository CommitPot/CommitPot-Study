#include <stdio.h>

int main() {
    int t, n, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a = -1e9, b = 1e9;
        while (n--) {
            scanf("%d", &c);
            if (c > a) a = c;
            if (c < b) b = c;
        }
        printf("%d %d\n", b, a);
    }
}

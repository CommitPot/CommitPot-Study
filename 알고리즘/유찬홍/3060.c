#include <stdio.h>

int main() {
    int n, a, b;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        int s = 0, c = 1, r = 1;
        for (int i = 0; i < 6; i++) {
            scanf("%d", &b);
            s += b;
        }
        while (a / s >= c) c *= 4, r++;
        printf("%d\n", r);
    }
}

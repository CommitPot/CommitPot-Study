#include <stdio.h>

int main() {
    int t, n, a = 0, w[3] = {};
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0, j; i < n; i++) {
            scanf("%d", &j);
            a += j;
            if (w[0] <= j) {
                w[1] = i;
                w[2] = w[0] < j ? 1 : w[2] + 1;
                w[0] = j;
            }
        }
        if (w[2] > 1) printf("no winner\n");
        else printf("%sority winner %d\n", w[0] > a - w[0] ? "maj" : "min", w[1] + 1);
        w[0] = w[1] = w[2] = a = 0;
    }
}

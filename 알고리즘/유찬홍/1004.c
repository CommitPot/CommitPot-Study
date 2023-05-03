#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int a, b, c, d, n, x, y, r, co = 0;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
        for (int j = 0; j < n; j++) {
            scanf("%d %d %d", &x, &y, &r);
            double o = sqrt((a - x) * (a - x) + (b - y) * (b - y));
            double p = sqrt((c - x) * (c - x) + (d - y) * (d - y));
            if (r > o && r < p) co++;
            if (r > p && r < o) co++;
        }
        printf("%d\n", co);
    }
}

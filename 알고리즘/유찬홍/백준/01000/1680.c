#include <stdio.h>

int main() {
    int t, a, b, c, d, r, w;
    scanf("%d", &t);
    while (t--) {
        r = w = 0;
        scanf("%d %d", &a, &b);
        while (b--) {
            scanf("%d %d", &c, &d);
            w += d;
            if (w == a) w = 0, r += c * 2;
            else if (w > a) w = d, r += c * 2;
        }
        printf("%d\n", r + (w ? c * 2 : 0));
    }
}

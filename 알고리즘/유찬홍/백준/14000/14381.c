#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1, a, f; i <= t; i++) {
        int b[10] = {}, c = 0, d = 0;
        scanf("%d", &a);
        f = a;
        while (d < 10 && f) {
            f = ++c * a;
            int x = f;
            while (x) {
                int e = x % 10;
                if (!b[e]) b[e] = 1, d++;
                x /= 10;
            }
        }
        if (!d) printf("Case #%d: INSOMNIA\n", i);
        else printf("Case #%d: %d\n", i, f);
    }
}

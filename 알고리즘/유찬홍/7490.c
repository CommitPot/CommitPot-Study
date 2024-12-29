#include <stdio.h>

char r[18] = "1";

void f(int s, int v, int i, int n) {
    if (i > n) {
        s += v;
        r[(i - 1) * 2 - 1] = 0;
        if (!s) printf("%s\n", r);
        return;
    }

    r[(i - 1) * 2] = i + 48;
    r[(i - 1) * 2 - 1] = ' ';
    f(v ? s : 0, (v ? v : s) * 10 + (v < 0 ? -i : i), i + 1, n);
    r[(i - 1) * 2 - 1] = '+';
    f(s + v, i, i + 1, n);
    r[(i - 1) * 2 - 1] = '-';
    f(s + v, -i, i + 1, n);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        f(1, 0, 2, n);
        printf("\n");
    }
}

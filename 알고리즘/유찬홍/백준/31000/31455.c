#include <stdio.h>

char s[1025][1025];

int sum(int a, int b, int x, int y) {
    int r = 0;
    for (int i = a; i <= x; i++) {
        for (int j = b; j <= y; j++) {
            r += s[i][j] - 48;
        }
    }
    return r;
}

int f(int a, int b, int x, int y, int p) {
    int r = sum(a, b, x, y), v = 0;
    if (p) return r;
    if (a == x || b == y) return 0;
    v += f(a, b, (a + x) / 2, (b + y) / 2, r % 4 == 0);
    v += f(a, (b + y) / 2 + 1, (a + x) / 2, y, r % 4 == 1);
    v += f((a + x) / 2 + 1, b, x, (b + y) / 2, r % 4 == 2);
    v += f((a + x) / 2 + 1, (b + y) / 2 + 1, x, y, r % 4 == 3);
    return v;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        printf("%d\n", sum(0, 0, n - 1, n - 1) - f(0, 0, n - 1, n - 1, 0));
    }
}

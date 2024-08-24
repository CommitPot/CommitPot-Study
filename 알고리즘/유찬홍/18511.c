#include <stdio.h>

int a, b, c[3];

int max(int x, int y) { return x > y ? x : y; }

int f(int v, int l) {
    if (v > a) return v / 10;
    if (!l) return v;
    int x = 0;
    for (int i = 0; i < b; i++) {
        x = max(x, f(v * 10 + c[i], l - 1));
    }
    return x;
}

int main() {
    scanf("%d %d", &a, &b);
    for (int i = 0; i < b; i++) scanf("%d", &c[i]);
    int d = a, e = 0;
    while (d) d /= 10, e++;
    printf("%d", f(0, e));
}

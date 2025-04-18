#include <stdio.h>

int f(int x) {
    if (x < 10) return x;
    return x % 10 && f(x / 10);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        while (!f(++n));
        printf("%d\n", n);
    }
}

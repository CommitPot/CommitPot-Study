#include <stdio.h>

int main() {
    int n, a = 0, b = 1, c = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a = b;
        b = c;
        c = a + b;
        c %= 1000000007;
    }
    printf("%d %d", a, n > 2 ? n - 2 : 0);
    return 0;
}
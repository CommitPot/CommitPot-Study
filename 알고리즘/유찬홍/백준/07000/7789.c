#include <stdio.h>

int main() {
    int n, m, a = 1, b = 1;
    scanf("%d %d", &n, &m);
    m = m * 1000000 + n;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) a = 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) b = 0;
    }
    printf("%s", a && b ? "Yes" : "No");
}

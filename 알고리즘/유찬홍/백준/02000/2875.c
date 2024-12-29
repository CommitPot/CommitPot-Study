#include <stdio.h>

int main() {
    int n, m, k, c = 0;
    scanf("%d %d %d", &n, &m, &k);
    while (1) {
        n -= 2;
        m -= 1;
        if (n >= 0 && m >= 0 && n + m >= k) c++;
        else break;
    }
    printf("%d", c);
}

#include <stdio.h>

int main() {
    int n, a, b, c, d[1000001] = {};
    scanf("%d %d %d %d", &n, &a, &b, &c);
    d[a] = d[b] = d[c] = 1;
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (d[a] || d[b] || d[c]) {
            printf("1");
            return 0;
        }
        d[a] = d[b] = d[c] = 1;
    }
    printf("0");
}

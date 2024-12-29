#include <stdio.h>

int main() {
    int t, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int count = 0;
        scanf("%d %d", &n, &m);
        for (int j = n; j <= m; j++) {
            int p = j;
            if (p == 0) count++;
            while (p > 0) {
                int a = p % 10;
                p /= 10;
                if (a == 0) count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
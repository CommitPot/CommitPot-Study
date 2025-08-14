#include <stdio.h>

int main() {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                r += i / 10 == m || i % 10 == m || j / 10 == m || j % 10 == m || k / 10 == m || k % 10 == m;
            }
        }
    }
    printf("%d", r);
}

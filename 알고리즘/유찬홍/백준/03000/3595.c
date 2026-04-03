#include <math.h>
#include <stdio.h>

int main() {
    int n, r[4] = {1e9};
    scanf("%d", &n);
    int a = sqrt(n);
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= i; j++) {
            int k = n / i / j;
            int x = j * k * 2 + i * j * 2 + i * k * 2;
            if (i * j * k == n && r[0] > x) {
                r[0] = x, r[1] = i, r[2] = j, r[3] = k;
            }
        }
    }
    printf("%d %d %d", r[1], r[2], r[3]);
}

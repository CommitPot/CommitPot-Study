#include <stdio.h>

int main() {
    int n, a, b, j = 0;
    long long r = 0;
    scanf("%d %d", &n, &a);
    for (int i = 1; i < n; i++) {
        scanf("%d", &b);
        if (b > a) j++;
        else {
            j++;
            r += (long long) j * (j - 1) / 2;
            j = 0;
        }
        a = b;
    }
    j++;
    printf("%lld", r + n + (long long) j * (j - 1) / 2);
}

#include <stdio.h>

int main() {
    int n, i, r = 0;
    scanf("%d", &n);
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) r++;
    }
    printf("%d", r * 2 + (i * i == n));
}

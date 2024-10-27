#include <stdio.h>

int main() {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n / 3; i++) {
        for (int j = i; j <= n - i - j; j++) {
            if (i * 2 + j * 2 > n) r++;
        }
    }
    printf("%d", r);
}

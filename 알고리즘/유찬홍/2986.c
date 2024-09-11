#include <stdio.h>

int main() {
    int n, c = 1;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            c = n / i;
            break;
        }
    }
    printf("%d", n - c);
}

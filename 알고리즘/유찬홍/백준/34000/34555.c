#include <stdio.h>

int main() {
    int n, a;
    scanf("%d", &n);
    a = n / 2 + n % 2;
    for (int i = 1; i <= n; i++) {
        printf("%d ", i & 1 ? a - i / 2 : a + i / 2);
    }
}

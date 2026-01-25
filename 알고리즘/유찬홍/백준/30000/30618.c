#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", (i - 1) * 2 < n ? i * 2 - 1 : (n - i + 1) * 2);
    }
}

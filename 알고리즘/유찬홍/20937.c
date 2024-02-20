#include <stdio.h>

int main() {
    int n, a[50001] = {0};
    scanf("%d", &n);
    for (int i = n; i > 0; i--) scanf("%d", &n), a[n]++;
    n = 0;
    for (int i = 1; i < 50001; i++) {
        if (n < a[i]) n = a[i];
    }
    printf("%d", n);
}

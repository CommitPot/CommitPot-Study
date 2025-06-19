#include <stdio.h>

int main() {
    int n, a[51], b = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        if (j < a[i]) j = a[i], b++;
        if (k < a[n - i - 1]) k = a[n - i - 1], c++;
    }
    printf("%d\n%d", b, c);
}

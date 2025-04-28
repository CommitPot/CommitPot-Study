#include <stdio.h>

int main() {
    int n, a[1001] = {}, r = 0;
    scanf("%d", &n);
    for (int i = 0, b; i < n; i++) {
        scanf("%d", &b);
        a[b]++;
    }
    for (int i = 1; i < 1001; i++) {
        if (r < a[i]) r = a[i];
    }
    printf("%d", r);
}

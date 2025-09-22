#include <stdio.h>
int main() {
    int n, a[2] = {1e9, 1e9};
    scanf("%d", &n);
    for (int i = 0, b, c = 0; i < n; i++) {
        scanf("%d", &b);
        if (b == -1) {
            c = 1;
            continue;
        }
        a[c] = a[c] < b ? a[c] : b;
    }
    printf("%d", a[0] + a[1]);
}

#include <stdio.h>

int main() {
    int n, a[51], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    while (1) {
        int v = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] & 1) a[i]--, r++;
            a[i] /= 2;
            v += a[i];
        }
        if (!v) break;
        r++;
    }
    printf("%d", r);
}

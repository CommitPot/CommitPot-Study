#include <stdio.h>

int main() {
    int n, a[104] = {}, b[27];
    for (int i = 2; i < 11; i++) {
        if (a[i]) continue;
        for (int j = i * 2; j < 104; j += i) a[j] = 1;
    }
    for (int i = 2, j = 0; i < 104; i++) {
        if (!a[i]) b[j++] = i;
    }
    scanf("%d", &n);
    for (int i = 1; i < 27; i++) {
        if (b[i - 1] * b[i] > n) {
            printf("%d", b[i - 1] * b[i]);
            break;
        }
    }
}

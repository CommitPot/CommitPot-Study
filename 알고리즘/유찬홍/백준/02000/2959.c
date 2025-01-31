#include <stdio.h>

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 3; i++) {
        for (int j = i, k; j < 4; j++) {
            if (a[i] > a[j]) {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
    printf("%d", a[0] * a[2]);
}

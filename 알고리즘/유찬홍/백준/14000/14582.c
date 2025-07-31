#include <stdio.h>

int main() {
    int a[19], r = 0;
    for (int i = 0; i < 18; i++) scanf("%d", &a[i]);
    for (int i = 0, j = 0, k = 0; i < 9; i++) {
        j += a[i];
        if (j > k) r = 1;
        k += a[i + 9];
    }
    printf("%s", r ? "Yes" : "No");
}

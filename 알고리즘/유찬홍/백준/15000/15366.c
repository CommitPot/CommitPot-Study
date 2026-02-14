#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, a[201];
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    qsort(a + n, n, 4, c);
    for (int i = 0; i < n; i++) {
        if (a[i] > a[i + n]) {
            printf("NE");
            return 0;
        }
    }
    printf("DA");
}

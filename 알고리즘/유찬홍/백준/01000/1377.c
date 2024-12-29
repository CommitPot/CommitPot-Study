#include <stdio.h>
#include <stdlib.h>

typedef struct c {
    int i, j;
} c;

int comp(const void *a, const void *b) {
    return (((c *) a)->i - ((c *) b)->i);
}

int main() {
    int n, rs = 0;
    c arr[500000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].i);
        arr[i].j = i;
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    for (int i = 0; i < n; i++) {
        if (rs < arr[i].j - i) {
            rs = arr[i].j - i;
        }
    }
    printf("%d", rs + 1);
}
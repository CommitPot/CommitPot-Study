#include <stdio.h>
#include <stdlib.h>

typedef struct cow {
    int a, b;
} cow;

int comp(const void *a, const void *b) {
    return (((cow *) a)->a - ((cow *) b)->a);
}

int main() {
    int n;
    cow arr[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    int count = arr[0].a + arr[0].b;
    for (int i = 1; i < n; i++) {
        if (arr[i].a > count) count += (arr[i].a - count) + arr[i].b;
        else {
            count += arr[i].b;
        }
    }
    printf("%d", count);
    return 0;
}
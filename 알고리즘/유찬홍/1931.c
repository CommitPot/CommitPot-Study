#include <stdio.h>
#include <stdlib.h>

typedef struct l {
    int a, b;
} l;

int comp(const void *a, const void *b) {
    l a1 = *(l *) a;
    l b1 = *(l *) b;
    if (a1.b > b1.b) return 1;
    else if (a1.b == b1.b) {
        if (a1.a > b1.a) return 1;
        else return -1;
    }
    return -1;
}

int main() {
    int n, index = 0, count = 1;
    l arr[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    for (int i = 1; i < n; i++) {
        if (arr[i].a >= arr[index].b) count++, index = i;
    }
    printf("%d", count);
    return 0;
}
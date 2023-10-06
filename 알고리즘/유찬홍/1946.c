#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    int x, y;
} e;

int comp(const void *a, const void *b) {
    e *a1 = (e *) a;
    e *b1 = (e *) b;
    return a1->x - b1->x;
}

int main() {
    int t, n;
    e arr[100001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &arr[i].x, &arr[i].y);
        }
        qsort(arr, n, sizeof(arr[0]), comp);
        int rs = 1, min = arr[0].y;
        for (int i = 1; i < n; i++) {
            if (min > arr[i].y) {
                rs++;
                min = arr[i].y;
            }
        }
        printf("%d\n", rs);
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int a, b;
} element;

int comp(const void *a, const void *b) {
    return ((element *) a)->a - ((element *) b)->a;
}


int main() {
    element arr[100001];
    int n, rs = 0, bs[100001] = {0}, p[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].a, &arr[i].b);
    qsort(arr, n, sizeof(arr[0]), comp);
    bs[0] = arr[0].b;
    for (int i = 1; i < n; i++) {
        if (arr[i].b > bs[rs]) bs[++rs] = arr[i].b, p[i] = rs;
        else {
            int s = 0, e = rs;
            while (s < e) {
                int mid = (s + e) / 2;
                if (arr[i].b > bs[mid]) s = mid + 1;
                else e = mid;
            }
            bs[e] = arr[i].b;
            p[i] = e;
        }
    }
    printf("%d\n", n - rs - 1);
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] == rs) {
            rs--;
            arr[i].a = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i].a != -1) printf("%d\n", arr[i].a);
    }
}

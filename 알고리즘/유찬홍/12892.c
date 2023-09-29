#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int p, v;
} element;

int comp(const void *a, const void *b) {
    return (((element *) a)->p - ((element *) b)->p);
}

int main() {
    int n, d;
    long long int rs = 0, p = 0;
    element arr[100000];
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].p, &arr[i].v);
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    int j = 0, k = 0;
    while (j <= k && k < n) {
        int sum = arr[k].p - arr[j].p;
        if (sum < d) rs += arr[k++].v;
        else rs -= arr[j++].v;
        if (p < rs) p = rs;
    }
    printf("%lld", p);
    return 0;
}

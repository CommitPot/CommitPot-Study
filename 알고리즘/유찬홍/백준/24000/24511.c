#include <stdio.h>

int main() {
    int n, m, a, f = 100000, r = 100000, arr[100001], arr1[200001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (!arr[i]) arr1[r++] = a;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        arr1[--f] = a;
        printf("%d ", arr1[--r]);
    }
}

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    if (*(long long int *) a < *(long long int *) b) return -1;
    else if (*(long long int *) a == *(long long int *) b) return 0;
    return 1;
}

int main() {
    int n;
    long long int ans = -1, arr[10001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, 8, comp);
    if (n % 2) ans = arr[--n];
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (arr[i] + arr[j] > ans) ans = arr[i] + arr[j];
    }
    printf("%lld", ans);
}

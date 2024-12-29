#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[100000], count = 2000000001, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    int j = 0, k = n - 1;
    while (j < k) {
        int sum = arr[j] + arr[k];
        if (count > abs(sum)) {
            count = abs(sum);
            a = arr[j];
            b = arr[k];
        }
        if (sum < 0) j++;
        else k--;
    }
    printf("%d %d", a, b);
}
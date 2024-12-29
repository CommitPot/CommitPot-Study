#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, m, arr[100000] = {0}, count = 2000000000;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    int j = 0, k = 1;
    while (j < n) {
        int sum = arr[k] - arr[j];
        if (sum < m) k++;
        else {
            if (sum < count) count = sum;
            j++;
        }
    }
    printf("%d", count);
    return 0;
}
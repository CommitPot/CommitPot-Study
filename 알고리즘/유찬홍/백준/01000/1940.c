#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, m, count = 0, arr[15000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    int j = 0, k = n - 1;
    while (j < k) {
        int sum = arr[j] + arr[k];
        if (m > sum) j++;
        else if (m < sum) k--;
        else {
            count++;
            j++, k--;
        }
    }
    printf("%d", count);
}
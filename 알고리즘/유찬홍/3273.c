#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, x, arr[100000], count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    qsort(arr, n, 4, comp);
    int j = 0, k = n - 1;
    while (j < k) {
        int sum = arr[j] + arr[k];
        if (sum < x) j++;
        else if (sum > x) k--;
        else {
            count++;
            j++;
        }
    }
    printf("%d", count);
}
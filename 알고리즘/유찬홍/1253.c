#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[2000], count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) {
        int j = 0, k = n - 1;
        while (j < k) {
            if (j == i) {
                j++;
                continue;
            } else if (k == i) {
                k--;
                continue;
            }
            int sum = arr[j] + arr[k];
            if (sum > arr[i]) k--;
            else if (sum < arr[i]) j++;
            else {
                count++;
                break;
            }
        }
    }
    printf("%d", count);
}
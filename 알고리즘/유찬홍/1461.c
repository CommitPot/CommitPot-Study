#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}


int main() {
    int n, m, idx = 0, arr[51], sum = 0, min = 10000000, max = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) idx++;
    }
    for (int i = 0; i < idx; i += m) {
        sum += abs(arr[i]) * 2;
    }
    for (int i = n - 1; i >= idx; i -= m) {
        sum += arr[i] * 2;
    }
    printf("%d", abs(min) < abs(max) ? sum - max : sum - abs(min));
}

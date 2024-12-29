#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, arr[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int sum = arr[0];
    qsort(arr, n, 4, comp);
    for (int i = 1; i < n; i++) {
        int temp = (i + 1) * arr[i];
        if (temp > sum) sum = temp;
    }
    printf("%d", sum);
    return 0;
}
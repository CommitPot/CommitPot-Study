#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int comp(const void *a, const void *b) {
    int *a1 = (int *) a, *b1 = (int *) b;
    if (*a1 > *b1) return 1;
    else if (*a1 < *b1) return -1;
    return 0;
}

int bs(int *array, int k, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (array[mid] == k) return 1;
        else if (array[mid] > k) end = mid - 1;
        else start = mid + 1;
    }
    return 0;
}

int main() {
    int N = 0, M = 0;

    int arr[MAX_SIZE + 1] = {0,}, arr1[MAX_SIZE + 1] = {0,};

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    qsort(arr, N, 4, comp);

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &arr1[i]);
        printf("%d\n", bs(arr, arr1[i], 0, N - 1));
    }
}

#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int b, c, d, sum = 0, sum1 = 0, arr[1001] = {0}, arr1[1001] = {0}, arr2[1001] = {0};
    scanf("%d %d %d", &b, &c, &d);
    for (int i = 0; i < b; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < c; i++) scanf("%d", &arr1[i]);
    for (int i = 0; i < d; ++i) scanf("%d", &arr2[i]);
    qsort(arr, b, 4, comp);
    qsort(arr1, c, 4, comp);
    qsort(arr2, d, 4, comp);
    int minV = min(d, min(b, c));
    for (int i = 0; i < minV; i++) {
        sum += (arr[i] + arr1[i] + arr2[i]) * 0.9;
        sum1 += arr[i] + arr1[i] + arr2[i];
    }
    int maxV = max(d, max(b, c));
    for (int i = minV; i < maxV; i++) {
        sum += arr[i] + arr1[i] + arr2[i];
        sum1 += arr[i] + arr1[i] + arr2[i];
    }
    printf("%d\n%d", sum1, sum);
}

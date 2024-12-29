#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[5];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, 5, 4, comp);
        if (arr[3] - arr[1] > 3) printf("KIN\n");
        else printf("%d\n", arr[1] + arr[2] + arr[3]);
    }
}
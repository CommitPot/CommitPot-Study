#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int arr[3], a, b;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, 3, 4, comp);
    a = arr[1] - arr[0];
    b = arr[2] - arr[1];
    if (a > b) {
        printf("%d", arr[0] + b);
    } else if (a < b) {
        printf("%d", arr[1] + a);
    } else {
        printf("%d", arr[2] + a);
    }
}

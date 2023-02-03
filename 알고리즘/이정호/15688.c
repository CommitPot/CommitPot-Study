#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int comp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int arr[MAX_SIZE];

    for(int j=0; j<n; j++) {
        scanf("%d", &arr[j]);
    }

    qsort(arr, n, sizeof(int), comp);

    for(int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }
}

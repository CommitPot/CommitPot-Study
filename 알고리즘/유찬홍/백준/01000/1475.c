#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    char arr[8];
    int arr1[10] = {0};
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        arr1[arr[i] - '0']++;
    }
    arr1[6] = arr1[9] = (arr1[6] + arr1[9]) / 2 + (arr1[6] + arr1[9]) % 2;
    qsort(arr1, 10, 4, comp);
    printf("%d", arr1[0]);
}
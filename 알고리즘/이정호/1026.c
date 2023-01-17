
#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
} // 오름차순 정렬

int comp1(const void *a, const void *b) {
    return (*(int *) b - *(int *) a);
} // 내림차순 정렬

int main() {
    int arrA[50], arrB[50];
    int n = 0, sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }

    qsort(arrA, n, sizeof(int), comp);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arrB[i]);
    }

    qsort(arrB, n, sizeof(int), comp1);

    // 일단 배열을 입력 받는다

    for (int k = 0; k < n; k++) {
        sum += arrA[k] * arrB[k];
    }

    printf("%d", sum);

}

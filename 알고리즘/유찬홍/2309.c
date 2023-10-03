#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void func(int *a, int *b, int sum, int *arr) {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                *a = i;
                *b = j;
                return;
            }
        }
    }
}

int main() {
    int arr[9], sum = 0, a, b;
    for (int i = 0; i < 9; i++) scanf("%d", &arr[i]), sum += arr[i];
    qsort(arr, 9, 4, comp);
    func(&a, &b, sum, arr);
    for (int i = 0; i < 9; i++) {
        if (i == a || i == b) continue;
        printf("%d\n", arr[i]);
    }
}

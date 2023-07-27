#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[51], num[1001] = {0}, arr1[51];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        num[arr[i]]++;
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 1001; j++) {
            if (!i) {
                if (num[j] > 0) {
                    arr1[i] = j;
                    num[j]--;
                    break;
                }
            } else {
                if (num[j] > 0 && arr1[i - 1] + 1 != j) {
                    arr1[i] = j;
                    num[j]--;
                    break;
                }
            }
        }
        int a = -1;
        for (int j = 0; j < 1001; j++) {
            if (num[j] > 0 && arr1[i] + 1 != j && j != arr1[i]) {
                a = j;
                break;
            }
        }
        if (a == -1) {
            for (int j = 0; j < 1001; j++) {
                if (num[j] > 0 && arr1[i] != j){
                    num[arr1[i]]++;
                    arr1[i] = j;
                    num[j]--;
                    break;
                }
            }
        }
    }
    for (int j = 0; j < 1001; j++) {
        if (num[j] > 0) {
            arr1[n - 1] = j;
            num[j]--;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
}

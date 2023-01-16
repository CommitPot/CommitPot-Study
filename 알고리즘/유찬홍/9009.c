#include <stdio.h>

int main() {
    int n, a, arr[46] = {0, 1};
    for (int i = 2; i < 46; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        int j = 45, arr1[20], c = 0;
        while (a > 0) {
            if (arr[j] > a) j--;
            else {
                arr1[c++] = arr[j];
                a -= arr[j];
            }
        }
        for (int k = c - 1; k > 0; k--) {
            printf("%d ", arr1[k]);
        }
        printf("%d\n", arr1[0]);
    }
    return 0;
}
#include <stdio.h>
#include <memory.h>

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    for (int i = n * n, j = 0, k = 0, f = 2; i >= 1; i--) {
        arr[j][k] = i;
        if (f == 0) {
            if (j - 1 >= 0 && !arr[j - 1][k]) j--;
            else k--, f = 1;
        } else if (f == 1) {
            if (k - 1 >= 0 && !arr[j][k - 1]) k--;
            else j++, f = 2;
        } else if (f == 2) {
            if (j + 1 < n && !arr[j + 1][k]) j++;
            else k++, f = 3;
        } else {
            if (k + 1 < n && !arr[j][k + 1]) k++;
            else j--, f = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == m)a = i, b = j;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", a + 1, b + 1);
}

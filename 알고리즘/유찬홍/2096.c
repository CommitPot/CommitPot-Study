#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, arr[100001][3], arr1[100001][3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
            arr1[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j % 2 == 0) {
                if (j == 0) {
                    arr[i][j] += max(arr[i - 1][j], arr[i - 1][j + 1]);
                    arr1[i][j] += min(arr1[i - 1][j], arr1[i - 1][j + 1]);
                } else {
                    arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
                    arr1[i][j] += min(arr1[i - 1][j], arr1[i - 1][j - 1]);
                }
            } else {
                int max = 0, max1 = 10000000;
                for (int k = 0; k < 3; k++) {
                    if (max < arr[i - 1][k]) max = arr[i - 1][k];
                    if (max1 > arr1[i - 1][k]) max1 = arr1[i - 1][k];
                }
                arr[i][j] += max;
                arr1[i][j] += max1;
            }
        }
    }
    int big = 0, small = 10000000;
    for (int i = 0; i < 3; i++) {
        if (arr[n - 1][i] > big) big = arr[n - 1][i];
        if (arr1[n - 1][i] < small) small = arr1[n - 1][i];
    }
    printf("%d %d", big, small);
}

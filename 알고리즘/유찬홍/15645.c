#include <stdio.h>

int min(int a, int b){return a > b ? b : a;}
int max(int a, int b){return a > b ? a : b;}
int main() {
    int n, arr[100000][3], arr1[100000][3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
            arr1[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (!j) {
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j + 1]);
                arr1[i][j] += min(arr1[i - 1][j], arr1[i - 1][j + 1]);
            } else if (j == 1){
                arr[i][j] += max(max(arr[i - 1][j], arr[i - 1][j - 1]), arr[i - 1][j + 1]);
                arr1[i][j] += min(min(arr1[i - 1][j], arr1[i - 1][j - 1]), arr1[i -1][j + 1]);
            } else {
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
                arr1[i][j] += min(arr1[i - 1][j], arr1[i - 1][j - 1]);
            }
        }
    }
    int max = 0, min = 100000000;
    for (int i = 0; i < 3; i++) {
        if (max < arr[n - 1][i]) max = arr[n - 1][i];
        if (min > arr1[n - 1][i]) min = arr1[n - 1][i];
    }
    printf("%d %d", max, min);
}

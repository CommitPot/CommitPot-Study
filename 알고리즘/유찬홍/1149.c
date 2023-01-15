#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, arr[1000][1000], big = 100000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) arr[i][j] += min(arr[i - 1][j + 1], arr[i - 1][j + 2]);
            else if (j == 1) arr[i][j] += min(arr[i - 1][j - 1], arr[i - 1][j + 1]);
            else arr[i][j] += min(arr[i - 1][j - 2], arr[i - 1][j - 1]);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (arr[n - 1][i] < big) big = arr[n - 1][i];
    }
    printf("%d", big);
}
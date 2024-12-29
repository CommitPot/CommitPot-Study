#include <stdio.h>

int main() {
    int r, c, w, sum = 0, arr[31][31];
    arr[0][0] = arr[0][1] = arr[1][1] = 1;
    scanf("%d %d %d", &r, &c, &w);
    int q = c - 1;
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) arr[i][j] = 1;
            else arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    for (int i = r - 1; i < r + w - 1; i++) {
        for (int j = c - 1; j <= q; j++) {
            sum += arr[i][j];
        }
        q++;
    }
    printf("%d", sum);
    return 0;
}
#include <stdio.h>

int main() {
    int n, a = 1000000000, arr[101][10] = {0};
    scanf("%d", &n);
    for (int i = 1; i < 10; i++) {
        arr[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (!j) arr[i][0] = arr[i - 1][1] % a;
            else if (j == 9) arr[i][9] = arr[i - 1][8] % a;
            else arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % a;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = (sum + arr[n][i]) % a;
    }
    printf("%d", sum);
}

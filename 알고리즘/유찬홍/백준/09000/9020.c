#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, arr[10001] = {0};
    for (int i = 2; i <= 100; i++) {
        if (arr[i] == 0) {
            for (int j = i * 2; j <= 10000; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        int a, b, sum = 10000;
        for (int j = 2; j <= m; j++) {
            if (arr[j] == 0 && arr[m - j] == 0 && sum > abs(j * 2 - m)) {
                a = j;
                b = m - j;
                sum = abs(j * 2 - m);
            }
        }
        printf("%d %d\n", a, b);
    }
}
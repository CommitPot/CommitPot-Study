#include <stdio.h>

int main() {
    int n, arr[1000001] = {0};
    for (int i = 2; i <= 1000; i++) {
        if (arr[i] == 0) {
            for (int j = i * 2; j <= 1000000; j += i) {
                arr[j] = 1;
            }
        }
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) return 0;
        for (int j = 2; j <= n; j++) {
            if (j % 2 == 1 && arr[j] == 0 && arr[n - j] == 0) {
                printf("%d = %d + %d\n", n, j, n - j);
                break;
            } else if (j == n) printf("Goldbach's conjecture is wrong.\n");
        }
    }
}
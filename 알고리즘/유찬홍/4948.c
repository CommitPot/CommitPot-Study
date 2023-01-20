#include <stdio.h>

int main() {
    while (1) {
        int n, count = 0, arr[250000] = {0};
        scanf("%d", &n);
        if (!n) return 0;
        for (int i = 2; i <= 500; i++) {
            if (arr[i] == 0) {
                for (int j = i * 2; j <= 250000; j += i) {
                    arr[j] = 1;
                }
            }
        }
        for (int i = n + 1; i <= n * 2; i++) {
            if (arr[i] == 0) count++;
        }
        printf("%d\n", count);
    }
}
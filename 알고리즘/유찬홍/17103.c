#include <stdio.h>

int main() {
    int n, t, arr[2000001] = {0};
    for (int i = 2; i <= 1000; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 1000000; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        int count = 0;
        for (int j = 2; j <= n / 2; j++) {
            if (!arr[j] && !arr[n - j]) count++;
        }
        printf("%d\n", count);
    }
}
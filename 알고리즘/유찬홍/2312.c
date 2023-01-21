#include <stdio.h>

int main() {
    int t, n, arr[200001] = {0};
    for (int i = 2; i <= 317; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 100000; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int a = 2;
        while (n > 1) {
            int count = 0;
            if (n % a == 0) {
                while (n % a == 0) {
                    count++;
                    n /= a;
                }
                printf("%d %d\n", a, count);
            } else do a++; while (arr[a]);
        }
    }
}
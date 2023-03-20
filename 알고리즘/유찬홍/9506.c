#include <stdio.h>

int main() {
    int n;
    while (1) {
        int sum = 0, arr[50001], c = 0;
        scanf("%d", &n);
        if (n == -1) return 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
                arr[c++] = i;
            }
        }
        if (sum == n) {
            printf("%d = %d", n, arr[0]);
            for (int i = 1; i < c; i++) {
                printf(" + %d", arr[i]);
            }
        } else {
            printf("%d is NOT perfect.", n);
        }
        printf("\n");
    }
}
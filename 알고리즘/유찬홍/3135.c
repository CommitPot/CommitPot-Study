#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, n, arr[6], sum = 1000000000;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int s = a > b ? a - b : b - a;
    for (int i = 1; i <= n; i++) {
        int c = abs(b - arr[i]) + 1;
        if (s > c && sum > c) {
            sum = c;
        }
    }
    printf("%d", sum == 1000000000 ? s : sum);
}

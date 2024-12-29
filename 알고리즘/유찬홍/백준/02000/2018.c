#include <stdio.h>

int main() {
    int n, j = 1, k = 1, sum = 1, count = 0;
    scanf("%d", &n);
    while (j <= k) {
        if (sum > n) sum -= j++;
        else if (sum < n) sum += ++k;
        else count++, sum -= j++;
    }
    printf("%d", count);
    return 0;
}
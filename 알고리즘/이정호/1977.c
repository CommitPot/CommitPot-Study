#include <stdio.h>

int main() {
    int m = 0, n = 0, sum = 0, min = 10000, count = 0;
    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (j * j == i) {
                sum += i;
                if (count == 0) {
                    min = i;
                }
                count++;
            }
        }
    }

    if (sum == 0) {
        printf("-1");
    } else {
        printf("%d\n%d", sum, min);
    }
}

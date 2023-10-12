#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j > 0) {
            int k = j % 10;
            if (k % 3 == 0 && k) {
                sum++;
            }
            j /= 10;
        }
    }
    printf("%d", sum);
}

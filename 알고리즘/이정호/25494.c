#include <stdio.h>

int main() {
    int T = 0, x = 0, y = 0, z = 0;

    scanf("%d", &T);

    while (T--) {
        int count = 0;
        scanf("%d %d %d", &x, &y, &z);
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                for (int k = 1; k <= z; k++) {
                    if (i % j == j % k && j % k == k % i) {
                        count++;
                    }
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

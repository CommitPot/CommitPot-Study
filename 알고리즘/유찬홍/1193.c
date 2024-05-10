#include <stdio.h>

int main() {
    int n, c = 1, i = 0;
    scanf("%d", &n);
    while (1) {
        for (int j = ++i, k = 1; j != 0; j--, k++) {
            if (c++ == n) {
                printf("%d/%d", i % 2 ? j : k, i % 2 ? k : j);
                return 0;
            }
        }
    }
}

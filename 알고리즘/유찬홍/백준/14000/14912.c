#include <stdio.h>

int main() {
    int n, d, r = 0;
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j) {
            if (j % 10 == d) r++;
            j /= 10;
        }
    }
    printf("%d", r);
}

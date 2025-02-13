#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n << 1; i++) {
        for (int j = 0; j < (n >> 1 << 1) + (n & 1); j++) {
            printf("%c", (i + j) & 1 ? ' ' : '*');
        }
        printf("\n");
    }
}

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) printf(" ");
        for (int j = 0; j < 2 * i - 1; j++) printf("%c", j & 1 ? ' ' : '*');
        printf("\n");
    }
}

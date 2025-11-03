#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n & 1) {
        for (int i = 0; i < n; i++) printf("*");
        printf("\n");
        for (int i = 0; i <= n / 2; i++) {
            for (int j = i; j < n / 2; j++) printf(" ");
            printf("*");
            if (i) {
                for (int j = 1; j < i * 2; j++) printf(" ");
                printf("*");
            }
            printf("\n");
        }
    } else printf("I LOVE CBNU");
}

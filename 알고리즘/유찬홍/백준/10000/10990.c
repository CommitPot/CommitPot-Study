#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--) printf(" ");
        for (int j = 1; j < i * 2; j++) printf("%c", j == 1 || j == i * 2 - 1 ? '*' : ' ');
        printf("\n");
    }
}

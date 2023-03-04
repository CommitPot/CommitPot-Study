#include <stdio.h>

int main() {
    int n = 0, sum = 0;
    char a;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &a);
        sum += a - 64;
    }
    printf("%d", sum);
}
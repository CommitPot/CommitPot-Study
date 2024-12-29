#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 1, j = 1; n > i; i += ++j);
    printf("%d", j % 2 ? i - n : n > i ? 0 : n < i ? 0 : i + ++j - n);
}

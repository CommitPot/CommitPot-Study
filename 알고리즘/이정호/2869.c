#include <stdio.h>

int main() {
    int a = 0, b = 0, v = 0, sum = 0;

    scanf("%d %d %d", &a, &b, &v);

    sum = (v - b - 1) / (a - b) + 1;

    printf("%d", sum);
}

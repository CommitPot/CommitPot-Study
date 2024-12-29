#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int small = x < y ? x : y;
    int big = x > y ? x : y;
    printf("%d", small / 10 + small + big);
    return 0;
}
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (n / 2 + 1) * (n - n / 2 + 1));
}

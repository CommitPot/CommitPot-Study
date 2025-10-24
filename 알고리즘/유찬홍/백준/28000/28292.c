#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", n > 5 ? 3 : n > 2 ? 2 : 1);
}

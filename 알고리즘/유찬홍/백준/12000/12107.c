#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%c", n - 1 ? 'A' : 'B');
    return 0;
}
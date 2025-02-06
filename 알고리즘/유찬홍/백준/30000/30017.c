#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", n - 1 > m ? m * 2 + 1 : n * 2 - 1);
}

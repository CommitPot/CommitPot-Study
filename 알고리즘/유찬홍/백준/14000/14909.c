#include <stdio.h>

int main() {
    int n, c = 0;
    while (scanf("%d", &n) != EOF) if (n > 0) c++;
    printf("%d", c);
}

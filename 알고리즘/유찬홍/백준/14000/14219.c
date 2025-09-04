#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%s", n * m % 3 ? "NO" :"YES");
}

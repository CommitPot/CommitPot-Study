#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n > 1) printf("%s", n == 2 && k == 1 ? "1 2" : "-1");
    else while (k--) printf("1 ");
}

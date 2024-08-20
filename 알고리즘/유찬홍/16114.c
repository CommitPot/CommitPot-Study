#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m != 1 && m % 2) printf("ERROR");
    else if ((n > 0 && !m) || (m == 1 && n < 0)) printf("INFINITE");
    else printf("%d", n > 0 && m && ~m % 2 ? n / (m / 2) - ((n % (m / 2)) ? 0 : 1) : 0);
}

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("SN %d", n);
    if (m < 27) printf("%c", m + 64);
    else printf("%c%c", (m - 27) / 26 + 97, ((m - 1) % 26) + 97);
}

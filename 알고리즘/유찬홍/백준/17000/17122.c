#include <stdio.h>

int main() {
    int n, m;
    char a[3];
    scanf("%d", &n);
    while (n--) {
        scanf("%s %d", a, &m);
        int x = (a[1] - 49) * 8 + a[0] - 64;
        printf("%s\n", ((x - 1) / 8 + (x - 1) % 8) % 2 == ((m - 1) / 8 + (m - 1) % 8) % 2 ? "YES" : "NO");
    }
}

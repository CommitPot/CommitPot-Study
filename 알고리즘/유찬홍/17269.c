#include <stdio.h>

int main() {
    int b = 0, c = 0, g = 0, f[201];
    char *a = "32124313113132122212111221", d[101], e[101];
    scanf("%*d %*d %s %s", d, e);
    while (d[b] || e[c]) {
        if (d[b]) f[g++] = a[d[b++] - 65] - 48;
        if (e[c]) f[g++] = a[e[c++] - 65] - 48;
    }
    while (--g > 1) {
        for (int i = 0; i < g; i++) f[i] = (f[i] + f[i + 1]) % 10;
    }
    printf("%d%%", f[0] * 10 + f[1]);
}

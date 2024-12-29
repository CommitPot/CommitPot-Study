#include <stdio.h>
#include <string.h>

char *f(int v, int k) {
    static char s[1];
    if (!v && !k) return s;
    return strcat(f(v / 2, --k), v % 2 ? "7" : "4");
}

int main() {
    int n, x = 1, y = 1;
    scanf("%d", &n);
    while (x * 2 + 1 <= n) x = x * 2 + 1, y++;
    printf("%s", f(n - x, y));
}

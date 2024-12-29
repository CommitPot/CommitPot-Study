#include <stdio.h>
#include <string.h>

char *f(int v, int k) {
    static char *s;
    if (!k && !v) return strcpy(s, "");
    return strcat(f(v / 2, k / 2), ~k & 1 ? "V" : "딸기");
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%s\n", f(8, n % 28 > 15 ? 28 - n % 28 + 2 : n % 28 ? n % 28 : 2));
    }
}

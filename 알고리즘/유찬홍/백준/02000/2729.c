#include <stdio.h>
#include <string.h>

void h(char *s, int l) {
    for (int i = 0; i < l / 2; i++) {
        int t = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = t;
    }
}

int main() {
    int n;
    char a[81], b[81];
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", a, b);
        int c = strlen(a), d = strlen(b);
        h(a, c);
        h(b, d);
        int e = c > d ? c : d;
        for (int i = 0; i < e; i++) {
            if (!a[i]) while (i < e) a[i++] = 48;
            if (!b[i]) while (i < e) b[i++] = 48;
        }
        a[e] = b[e] = 0;
        char f[82];
        int g = 0;
        for (int i = 0; i < e; i++) {
            f[i] = a[i] + b[i] - 48 + g;
            if (f[i] > 49) f[i] -= 2, g = 1;
            else g = 0;
        }
        if (g) f[e++] = 49;
        h(f, e);
        f[e] = g = 0;
        while (f[g++] == 48);
        printf("%s\n", g - 1 == e ? "0" : &f[g - 1]);
    }
}

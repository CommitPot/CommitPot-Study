#include <stdio.h>

int main() {
    int n, m, k = 5, i = 0, p = 0;
    scanf("%d %d", &n, &m);
    while (k) {
        int x = i++, j = 0;
        char s[32];
        do {
            s[j++] = x % 2 + 48;
            x /= 2;
        } while (x);
        for (int l = 0, o = j - 1; l < o; l++, o--) {
            char t = s[l];
            s[l] = s[o];
            s[o] = t;
        }
        for (int l = 0; l < j; l++) {
            if (!k) break;
            if ((p + l) % n == m - 1) printf("%c ", s[l]), k--;
        }
        p += j;
    }
}

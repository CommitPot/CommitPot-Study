#include <stdio.h>

int main() {
    int n;
    char s[1000001];
    scanf("%d", &n);
    while (n--) {
        char a[2][1000001];
        int t[2] = {};
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            if (s[i] == '<') {
                if (t[0]) a[1][t[1]++] = a[0][--t[0]];
            } else if (s[i] == '>') {
                if (t[1]) a[0][t[0]++] = a[1][--t[1]];
            } else if (s[i] == '-') {
                if (t[0]) t[0]--;
            } else a[0][t[0]++] = s[i];
        }
        a[0][t[0]] = 0;
        for (int i = 0, j = t[1] - 1; i < j; i++, j--) {
            char b = a[1][i];
            a[1][i] = a[1][j];
            a[1][j] = b;
        }
        a[1][t[1]] = 0;
        printf("%s%s\n", a[0], a[1]);
    }
}

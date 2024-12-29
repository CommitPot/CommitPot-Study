#include <stdio.h>

char r = 'F';

void f(char m[26][27], char *vis, int v, int t) {
    if (v == t) {
        r = 'T';
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (!vis[i] && m[v][i]) {
            vis[i] = 1;
            f(m, vis, i, t);
        }
    }
}

int main() {
    int n;
    char m[26][27] = {};
    scanf("%d ", &n);
    while (n--) {
        char s[7];
        scanf(" %[^\n]", s);
        m[s[0] - 97][s[5] - 97] = 1;
    }
    scanf("%d", &n);
    while (n--) {
        char s[7];
        scanf(" %[^\n]", s);
        char vis[26] = {};
        f(m, vis, s[0] - 97, s[5] - 97);
        printf("%c\n", r);
        r = 'F';
    }
}

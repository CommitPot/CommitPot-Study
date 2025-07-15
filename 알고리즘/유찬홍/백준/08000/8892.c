#include <stdio.h>
#include <string.h>

int f(char *s, int l) {
    for (int i = 0, j = l - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

void g(int n, char s[101][10001]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            char c[20001], d[20001];
            strcpy(c, s[i]);
            strcat(c, s[j]);
            if (f(c, strlen(c))) {
                printf("%s\n", c);
                return;
            }
            strcpy(d, s[j]);
            strcat(d, s[i]);
            if (f(d, strlen(d))) {
                printf("%s\n", d);
                return;
            }
        }
    }
    printf("0\n");
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        char s[100][10001];
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        g(n, s);
    }
}

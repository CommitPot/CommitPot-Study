#include <stdio.h>

int main() {
    int t, n, m;
    char s[101];
    scanf("%d", &t);
    while (t--) {
        int r = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            for (int j = 0; s[j]; j++) r += s[j] == '.';
        }
        printf("%s\n", r & 1 ? "sewon" : "pizza");
    }
}

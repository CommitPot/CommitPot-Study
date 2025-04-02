#include <stdio.h>

int main() {
    int n, t;
    scanf("%d", &t);
    while (t--) {
        int a[26] = {};
        char s[1001];
        scanf("%s", s);
        for (int i = 0; s[i]; i++) a[s[i] - 65]++;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int b[27] = {};
            for (int j = 0; s[j]; j++) {
                if (b[s[j] - 65] < a[s[j] - 65]) b[s[j] - 65]++;
                else b[26] = 1;
            }
            printf("%s\n", b[26] ? "NO" : "YES");
        }
    }
}

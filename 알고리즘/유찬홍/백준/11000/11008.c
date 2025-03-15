#include <stdio.h>
#include <string.h>

int main() {
    int t;
    char s[10001], p[101];
    scanf("%d", &t);
    while(t--) {
        scanf("%s %s", s, p);
        int l = strlen(p), n = strlen(s), r = 0;
        for (int i = 0; i < n; i++) {
            if (n - i >= l) {
                int k = 1;
                for (int j = 0; j < l; j++) if (s[i + j] != p[j]) k = 0;
                if (k) i += l - 1;
            }
            r++;
        }
        printf("%d\n", r);
    }
}

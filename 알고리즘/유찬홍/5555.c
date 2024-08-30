#include <stdio.h>
#include <string.h>

int main() {
    int n, r = 0;
    char s[11], m[21];
    scanf("%s %d", s, &n);
    int l = strlen(s);
    while (n--) {
        scanf("%s", m);
        int k = strlen(m);
        for (int i = k; i < k + l; i++) m[i] = m[i - k];
        for (int i = 0; i < k; i++) {
            int o = 0;
            for (int j = 0; j < l; j++) if (m[i + j] == s[j]) o++;
            if (o == l) {
                r++;
                break;
            }
        }
    }
    printf("%d", r);
}

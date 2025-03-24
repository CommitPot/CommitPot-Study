#include <stdio.h>

int main() {
    int n, r = 0;
    char s[101];
    scanf("%d %s", &n, s);
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            int v = 0, w = 0;
            for (int k = j + 1; k <= j + i - 1; k++) {
                if (s[k] == 'N') v++;
                if (s[k] == 'A') w++;
            }
            if (s[j] == s[j + i] && s[j] == 'A' && v == 1 && !w) r++;
        }
    }
    printf("%d", r);
}

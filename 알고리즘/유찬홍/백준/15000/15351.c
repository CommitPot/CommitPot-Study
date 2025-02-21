#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[31];
        int r = 0;
        scanf(" %[^\n]", s);
        for (int j = 0; s[j]; j++) {
            if (s[j] != 32) r += s[j] - 64;
        }
        if (r == 100) printf("PERFECT LIFE\n");
        else printf("%d\n", r);
    }
}

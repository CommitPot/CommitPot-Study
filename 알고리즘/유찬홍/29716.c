#include <stdio.h>

int main() {
    int a, b, r = 0;
    char s[101];
    scanf("%d %d", &a, &b);
    while (b--) {
        scanf(" %[^\n]", s);
        int k = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == 32) k++;
            else if (s[i] > 64 && s[i] < 91) k += 4;
            else k += 2;
        }
        if (a >= k) r++;
    }
    printf("%d", r);
}

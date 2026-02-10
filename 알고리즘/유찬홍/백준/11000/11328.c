#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a[26] = {}, b = 0, l = 0;
        char c[2002];
        scanf(" %[^\n]", c);
        while (c[l] != 32) a[c[l++] - 97]++;
        while (c[++l]) a[c[l] - 97]--;
        for (int i = 0; i < 26; i++) b |= a[i];
        printf("%sossible\n", b ? "Imp" : "P");
    }
}

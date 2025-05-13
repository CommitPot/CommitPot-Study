#include <stdio.h>

int main() {
    int t;
    char s[21], a[] = "22233344455566677778889999";
    scanf("%d", &t);
    for (int i = 0, l, m; i < t; i++) {
        l = 0, m = 0;
        scanf("%s", s);
        for (int j = 0; s[j]; j++) {
            if (s[j] > 90) s[j] -= 32;
            s[j] = a[s[j] - 65], l++;
        }
        for (int j = 0, k = l - 1; j < k; j++, k--) {
            if (s[j] != s[k]) m = 1;
        }
        printf("%s\n", m ? "NO" : "YES");
    }
}

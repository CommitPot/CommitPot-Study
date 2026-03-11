#include <stdio.h>

int f(int v) {
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

int main() {
    int t;
    char s[300001];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        long long r = 1, j = -1;
        for (int i = 0; s[i]; i++) {
            if (f(s[i])) {
                if (j < 0) j = i;
                else r = r * (i - j) % 1000000007, j = i;
            }
        }
        printf("%lld\n", j < 0 ? -1 : r > 1 ? r : 1);
    }
}


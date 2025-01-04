#include <stdio.h>

int main() {
    int n;
    long long r = 0;
    char s[5000001];
    scanf("%d %s", &n, s);
    for (int i = 0; s[i]; i++) {
        if (s[i] < 58) {
            int j = 1, k = s[i] - 48;
            while (s[i + j] < 58 && s[i + j] > 47) k = k * 10 + (s[i + j++] - 48);
            if (j < 7) r += k;
            i += j;
        }
    }
    printf("%lld", r);
}

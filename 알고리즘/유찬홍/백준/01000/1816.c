#include <stdio.h>

int main() {
    int n, p[1000001] = {};
    for (int i = 2; i < 1001; i++) {
        if (!p[i]) {
            for (int j = i * 2; j < 1000001; j += i) p[j] = 1;
        }
    }
    long long s;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &s);
        int k = 1;
        for (int i = 2; i < 1000001; i++) {
            if (!p[i] && s % i == 0) {
                k = 0;
                break;
            }
        }
        printf("%s\n", k ? "YES" : "NO");
    }
}

#include <stdio.h>

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 100001; i++) {
        int b[1001], c = 1;
        b[1] = i;
        for (int j = 2; j <= n; j++) {
            b[j] = a[j - 1] - b[j - 1];
            if (b[j] < 0) c = 0;
        }
        if (b[n] + b[1] == a[n] && c) {
            for (int j = 1; j <= n; j++) printf("%d\n", b[j]);
            return 0;
        }
    }
}

#include <stdio.h>

int main() {
    int t, n, p[318138] = {}, r[3001];
    p[0] = p[1] = 1;
    for (int i = 2, k = 1; i * i <= 318137; i++) {
        if (p[i]) continue;
        for (int j = i * 2; j <= 318137; j += i) p[j] = 1;
    }
    for (int i = 1, j = 1, k = 0; j < 3001; i++) {
        while(p[k++]);
        if (!p[i]) r[j++] = k - 1;
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", r[n]);
    }
}

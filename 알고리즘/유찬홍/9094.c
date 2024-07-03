#include <stdio.h>

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        int c = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                c += !((i * i + j * j + m) % (i * j));
            }
        }
        printf("%d\n", c);
    }
}

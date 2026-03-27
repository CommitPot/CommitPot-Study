#include <stdio.h>

int main() {
    int n, m, a[101], b[3] = {1e9, 0, 0};
    char k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0, l; i < m; i++) {
        scanf("%d ", &l);
        for (int j = 0; j < n; j++) {
            scanf(" %c", &k);
            b[2] += k == 'O' ? a[j] : 0;
        }
        if (b[1] <= b[2]) {
            if (b[1] < b[2]) b[0] = l, b[1] = b[2];
            else b[0] = b[0] < l ? b[0] : l;
        }
        b[2] = 0;
    }
    printf("%d %d", b[0], b[1]);
}

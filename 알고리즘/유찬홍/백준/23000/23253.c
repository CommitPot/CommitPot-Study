#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < m; i++) {
        scanf("%d", &j);
        int a = 1e9;
        for (int k = 0, l; k < j; k++) {
            scanf("%d", &l);
            if (l > a) {
                printf("No");
                return 0;
            }
            a = l;
        }
    }
    printf("Yes");
}

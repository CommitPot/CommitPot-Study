#include <stdio.h>

int main() {
    int n, p, m, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p, &m);
        int count = 0, arr[501] = {0};
        for (int j = 0; j < p; j++) {
            scanf("%d", &a);
            if (arr[a] > 0) count++;
            else arr[a]++;
        }
        printf("%d\n", count);
    }
    return 0;
}
#include <stdio.h>

int main() {
    int n, a, f = -1, r = -1, v[2] = {0, 1e9};
    scanf("%d", &n);
    for (int i = 0, j; i < n; i++) {
        scanf("%d", &j);
        if (j == 2) ++f;
        else scanf("%d", &a), r++;
        if (v[0] <= r - f) {
            if (v[0] == r - f && v[1] > a) v[1] = a;
            if (v[0] < r - f) v[0] = r - f, v[1] = a;
        }
    }
    printf("%d %d", v[0], v[1]);
}

#include <stdio.h>

int n, k, arr[12];

void func(int x, int len) {
    if (x == n) {
        if (!--k) {
            for (int i = 0; i <= len; i++) {
                printf("%d%s", arr[i], i == len ? "" : "+");
            }
        }
        return;
    }
    for (int i = 1; i < 4; i++) {
        if (x + i <= n) {
            arr[++len] = i;
            func(x + i, len--);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    func(0, -1);
    if (k > 0) printf("-1");
}

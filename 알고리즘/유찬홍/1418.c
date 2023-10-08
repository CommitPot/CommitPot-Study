#include <stdio.h>

int main() {
    int n, k, c = 0, arr[100001] = {0};
    arr[1] = 1;
    scanf("%d %d", &n, &k);
    for (int i = 2; i <= n; i++) {
        if (!arr[i]) {
            arr[i] = i;
            for (int j = i * 2; j <= n; j += i) {
                arr[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (k >= arr[i]) c++;
    }
    printf("%d", c);
}

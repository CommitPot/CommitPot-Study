#include <stdio.h>

int main() {
    int n, k, coin[101] = {0}, arr[10001] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    arr[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - coin[i] >= 0) {
                arr[j] += arr[j - coin[i]];
            }
        }
    }
    printf("%d", arr[k]);
}

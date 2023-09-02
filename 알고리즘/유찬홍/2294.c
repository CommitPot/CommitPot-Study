#include <stdio.h>

int main() {
    int n, k, v[101], arr[10001] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= k; i++) arr[i] = 100001;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= v[i] && arr[j] > arr[j - v[i]] + 1) arr[j] = arr[j - v[i]] + 1;
        }
    }
    printf("%d", arr[k] == 100001 ? -1 : arr[k]);
}

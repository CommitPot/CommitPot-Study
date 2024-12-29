#include <stdio.h>

int main() {
    int n, arr[250001];
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        int sum = -1e4;
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > 0) arr[i] += arr[i - 1];
            if (sum < arr[i]) sum = arr[i];
        }
        printf("%d\n", sum);
    }
}

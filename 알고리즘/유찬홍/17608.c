#include <stdio.h>

int main() {
    int n, arr[100001], max = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (max < arr[i]) {
            max = arr[i];
            cnt++;
        }
    }
    printf("%d", cnt);
}

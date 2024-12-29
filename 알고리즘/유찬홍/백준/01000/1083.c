#include <stdio.h>

int main() {
    int n, m, arr[51];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        int c = 0, max = arr[i];
        if (!m) break;
        for (int j = i + 1; j < n; j++) {
            if (max < arr[j] && m >= j - i) {
                max = arr[j];
                c = j - i;
            }
        }
        for (int j = i + c; j > i; j--) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
        m -= c;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

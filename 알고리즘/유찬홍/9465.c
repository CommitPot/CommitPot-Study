#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int arr[100001][2] = {0};
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j][0]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j][1]);
        }
        arr[1][0] += arr[0][1];
        arr[1][1] += arr[0][0];
        for (int j = 2; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                if (!k) {
                    arr[j][0] += max(arr[j - 1][1], arr[j - 2][1]);
                } else {
                    arr[j][1] += max(arr[j - 1][0], arr[j - 2][0]);
                }
            }
        }
        printf("%d\n", max(arr[n - 1][0], arr[n - 1][1]));
    }
}

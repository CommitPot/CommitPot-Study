#include <stdio.h>

int main() {
    int arr[100001], arr1[1000001], arr2[100001];
    int n, m, bs[100001], rs = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        arr1[m - 1] = i;
    }
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[arr[i] - 1];
    }
    bs[0] = arr2[0];
    for (int i = 1; i < n; i++) {
        if (bs[rs] < arr2[i]) bs[++rs] = arr2[i];
        else {
            int s = 0, e = rs;
            while (s < e) {
                int mid = (s + e) / 2;
                if (arr2[i] > bs[mid]) s = mid + 1;
                else e = mid;
            }
            bs[e] = arr2[i];
        }
    }
    printf("%d", rs + 1);
}

#include <stdio.h>

int main() {
    int n, arr[40000], arr1[40000], rs = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    arr1[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr1[rs] < arr[i]) arr1[++rs] = arr[i];
        else {
            int s = 0, e = rs;
            while (s < e) {
                int mid = (s + e) / 2;
                if (arr[i] > arr1[mid]) s = mid + 1;
                else e = mid;
            }
            arr1[e] = arr[i];
        }
    }
    printf("%d", rs + 1);
}
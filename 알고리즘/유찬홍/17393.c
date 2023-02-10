#include <stdio.h>

int main() {
    int n, arr2[500000];
    long long int arr[500000], arr1[500000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &arr1[i]);
    for (int i = 0; i < n; i++) {
        int s = 0, e = n;
        while (s < e) {
            int mid = (s + e) / 2;
            if (arr1[mid] <= arr[i]) s = mid + 1;
            else e = mid;
        }
        arr2[i] = e - 1 - i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    return 0;
}
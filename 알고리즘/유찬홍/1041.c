#include <stdio.h>

long long int max(long long int a, long long int b) { return a > b ? a : b; }

int main() {
    long long int sum = 0, n, arr[7], arr1[9], arr2[9], min = 1000000000, min1, min2 = 1000000000;
    scanf("%lld", &n);
    for (int i = 1; i <= 6; i++) scanf("%lld", &arr[i]);
    if (n == 1) {
        long long a = 0, b = 0;
        for (int i = 1; i <= 6; i++) {
            a += arr[i];
            if (b < arr[i]) b = arr[i];
        }
        printf("%lld", a - b);
        return 0;
    }
    arr1[0] = arr[1] + arr[2] + arr[3];
    arr2[0] = max(arr[1], max(arr[2], arr[3]));
    arr1[1] = arr[1] + arr[2] + arr[4];
    arr2[1] = max(arr[1], max(arr[2], arr[4]));
    arr1[2] = arr[1] + arr[4] + arr[5];
    arr2[2] = max(arr[1], max(arr[4], arr[5]));
    arr1[3] = arr[1] + arr[3] + arr[5];
    arr2[3] = max(arr[1], max(arr[3], arr[5]));
    arr1[4] = arr[5] + arr[4] + arr[6];
    arr2[4] = max(arr[5], max(arr[4], arr[6]));
    arr1[5] = arr[5] + arr[3] + arr[6];
    arr2[5] = max(arr[5], max(arr[3], arr[6]));
    arr1[6] = arr[3] + arr[2] + arr[6];
    arr2[6] = max(arr[3], max(arr[2], arr[6]));
    arr1[7] = arr[4] + arr[2] + arr[6];
    arr2[7] = max(arr[4], max(arr[2], arr[6]));
    for (int i = 0; i < 8; i++) {
        if (min > arr1[i]) {
            min = arr1[i];
            min1 = arr2[i];
        }
    }
    for (int i = 1; i <= 6; i++) {
        if (min2 > arr[i]) min2 = arr[i];
    }
    sum += (n - 2) * (n - 2) * 5 * min2 + (n - 2) * 4 * min2;
    printf("%lld", sum + (min - min1) * (n - 2) * 8 + min * 4 + (min - min1) * 4);
}

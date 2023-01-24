#include <stdio.h>

int arr[8000001] = {0};

int main() {
    int n, k = 0, l = 0, count = 0;
    scanf("%d", &n);
    int n1 = n, c = 0, arr1[n];
    for (int i = 2; i <= 2000; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 4000000; j += i) {
                arr[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n1 + 1; i++) {
        if (!arr[i]) arr1[c++] = i;
        else n1++;
    }
    while (l <= n) {
        int sum = 0;
        for (int m = k; m <= l; m++) {
            sum += arr1[m];
        }
        if (n > sum) l++;
        else if (n < sum) k++;
        else {
            k++;
            l++;
            count++;
        }
    }
    printf("%d", count);
}
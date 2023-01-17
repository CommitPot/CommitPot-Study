#include <stdio.h>

int main() {
    int n, arr[100000], sum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i] + arr[i - 1]) arr[i] += arr[i - 1];
        sum = sum > arr[i] ? sum : arr[i];
    }
    printf("%d", sum);
}
#include <stdio.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int n, arr[50001];
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) arr[i] = 1000000;
    for (int i = 1; i * i <= n; i++) arr[i * i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j < i; j++) {
            arr[i] = min(arr[i], arr[i - j * j] + arr[j * j]);
        }
    }
    printf("%d", arr[n]);
}

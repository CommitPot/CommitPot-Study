#include <stdio.h>

int main() {
    int n, arr[100000], bs[100000], rs = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bs[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > bs[rs]) bs[++rs] = arr[i];
        else {
            int s = 0, e = rs;
            while (s < e){
                int mid = (s + e) / 2;
                if (arr[i] > bs[mid]) s = mid + 1;
                else e = mid;
            }
            bs[e] = arr[i];
        }
    }
    printf("%d", n - rs - 1);
}
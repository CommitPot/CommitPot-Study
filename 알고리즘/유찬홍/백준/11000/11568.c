#include <stdio.h>

int main() {
    int n, arr[1001], rs[1001] = {0}, rs1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    rs[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > rs[rs1]) rs[++rs1] = arr[i];
        else {
            int s = 0, e = rs1;
            while (s < e) {
                int mid = (s + e) / 2;
                if (rs[mid] < arr[i]) s = mid + 1;
                else e = mid;
            }
            rs[e] = arr[i];
        }
    }
    printf("%d", rs1 + 1);
    return 0;
}
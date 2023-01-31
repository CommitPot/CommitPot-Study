#include <stdio.h>

int main() {
    int n, c = 0, arr[1000001], bs[1000001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > bs[c - 1]) bs[c++] = arr[i];
        else {
            int s = 0, e = c;
            while (s < e) {
                int mid = (s + e) / 2;
                if (arr[i] > bs[mid]) s = mid + 1;
                else e = mid;
            }
            int pos = e;
            bs[pos] = arr[i];
        }
    }
    printf("%d", c);
    return 0;
}
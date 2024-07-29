#include <stdio.h>

int main() {
    char a[400001];
    int n, rs = 0, d[10] = {};
    scanf("%d %[^\n]s", &n, a);
    for (int l = 0, r = 0, k = 0; r < n * 2 - 1;) {
        if (k <= 2 && d[a[r] - 48]) d[a[r] - 48]++, r += 2;
        else {
            if (k < 2) d[a[r] - 48]++, r += 2, k++;
            else {
                if (!--d[a[l] - 48]) k--;
                l += 2;
            }
        }
        rs = r - l < rs ? rs : r - l;
    }
    printf("%d", rs / 2);
}

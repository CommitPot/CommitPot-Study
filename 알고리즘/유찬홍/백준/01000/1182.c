#include <stdio.h>

int n, s, cnt = 0, arr[21];

void bt(int ind, int sum) {
    if (ind == n) return;
    sum += arr[ind];

    if (sum == s) cnt++;

    bt(ind + 1, sum);
    bt(ind + 1, sum - arr[ind]);
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    bt(0, 0);
    printf("%d", cnt);
}

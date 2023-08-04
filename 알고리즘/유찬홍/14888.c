#include <stdio.h>

int n, min = 2000000000, max = -2000000000, arr[12], op[4], opVis[4] = {0};

void bt(int sum, int c) {
    if (c + 1 == n) {
        if (sum > max) max = sum;
        if (sum < min) min = sum;
        return;
    }
    c++;
    for (int i = 0; i < 4; i++) {
        if (opVis[i] == op[i]) continue;
        opVis[i]++;
        if (i == 0) bt(sum + arr[c], c);
        else if (i == 1) bt(sum - arr[c], c);
        else if (i == 2) bt(sum * arr[c], c);
        else if (i == 3) {
            if (sum < 0) bt((sum * -1 / arr[c]) * -1, c);
            else bt(sum / arr[c], c);
        }
        opVis[i]--;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &op[i]);
    bt(arr[0], 0);
    printf("%d\n%d", max, min);
}

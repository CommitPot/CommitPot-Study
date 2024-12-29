#include <stdio.h>

int main() {
    int n, x, max = 0, c = 0, arr[250001] = {0};
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= n - x + 1; i++) {
        int sum = arr[i + x - 1] - arr[i - 1];
        if (max < sum) max = sum, c = 0;
        if (max == sum) c++;
    }
    if (max) printf("%d\n%d", max, c);
    else printf("SAD");
    return 0;
}
#include <stdio.h>

int main() {
    int n, k, max = 0, arr[100001] = {0}, input[200001];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    int i = 0, j = 0;
    while (j < n) {
        if (arr[input[j]] < k) {
            arr[input[j]]++;
            j++;
            if (max < j - i) max = j - i;
        } else {
            arr[input[i++]]--;
        }
    }
    printf("%d", max);
    return 0;
}
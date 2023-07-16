#include <stdio.h>

int main() {
    int n, cnt = 0, arr[1000001] = {0}, rs[1000001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != rs[i]) {
            cnt++;
            arr[i] = !arr[i];

            if (i + 1 < n) arr[i + 1] = !arr[i + 1];
            if (i + 2 < n) arr[i + 2] = !arr[i + 2];
        }
    }
    printf("%d", cnt);
}

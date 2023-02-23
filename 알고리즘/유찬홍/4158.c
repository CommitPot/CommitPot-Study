#include <stdio.h>

int main() {
    while (1) {
        int n, m, a, c = 0, arr[100001] = {0};
        scanf("%d %d", &n, &m);
        if (!n && !m) return 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &a);
            int s = 0, e = n - 1;
            while (s <= e){
                int mid = (s + e) / 2;
                if (arr[mid] < a) s = mid + 1;
                else if (arr[mid] > a) e = mid - 1;
                else {
                    c++;
                    break;
                }
            }
        }
        printf("%d\n", c);
    }
}
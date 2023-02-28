#include <stdio.h>
#include <string.h>

int main() {
    int n, s = 0, e = 0, rs = 0, alpha[26] = {0};
    char arr[100001];
    scanf("%d %s", &n, arr);
    int c = 0, len = strlen(arr);
    while (e < len) {
        if (!alpha[arr[e] - 97]) c++;
        alpha[arr[e++] - 97]++;
        if (c <= n) {
            if (rs < e - s) rs = e - s;
        } else {
            if (alpha[arr[s] - 97] == 1) c--;
            alpha[arr[s++] - 97]--;
        }
    }
    printf("%d", rs);
    return 0;
}
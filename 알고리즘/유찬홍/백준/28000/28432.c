#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    char arr[102][11], arr1[102][11], a = '0', b = '0';
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        if (arr[i][0] != '?' && a == '0') continue;
        if (arr[i][0] == '?') {
            if (i == 0) a = '1';
            else {
                int len = strlen(arr[i - 1]);
                a = arr[i - 1][len - 1];
            }
        } else if (arr[i - 1][0] == '?') {
            b = arr[i][0];
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        int len = strlen(arr1[i]);
        if ((a == '1' || a == arr1[i][0]) && (b == arr1[i][len - 1] || b == '0')) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (strcmp(arr1[i], arr[j]) == 0) {
                    c = 1;
                    break;
                }
            }
            if (!c) {
                printf("%s", arr1[i]);
                break;
            }
        }
    }
}

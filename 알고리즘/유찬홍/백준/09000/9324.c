#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char arr[100001];
        int alpha[27] = {0}, a = 0;
        scanf("%s", arr);
        int len = strlen(arr);
        for (int j = 0; j < len; j++) {
            alpha[arr[j] - 65]++;
            if (alpha[arr[j] - 65] % 3 == 0) {
                if (arr[j + 1] != arr[j]) {
                    a++;
                    break;
                } else j++;
            }
        }
        printf("%s", !a ? "OK\n" : "FAKE\n");
    }
}

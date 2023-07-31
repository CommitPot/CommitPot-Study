#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[81];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int len = strlen(arr);
        int a = -1, d = 0;
        char b, c = 58;
        for (int j = len - 1; j >= 1; j--) {
            if (arr[j] > arr[j - 1]) {
                a = j - 1;
                b = arr[j - 1];
                break;
            }
        }
        if (a == -1 || len < 2) {
            printf("BIGGEST\n");
            continue;
        }
        for (int j = len - 1; j >= a; j--) {
            if (b < arr[j] && c > arr[j]) {
                c = arr[j];
                d = j;
            }
        }
        arr[a] = c;
        arr[d] = b;
        for (int j = a + 1, k = len - 1; j < k; j++, k--) {
            char tmp = arr[j];
            arr[j] = arr[k];
            arr[k] = tmp;
        }
        printf("%s\n", arr);
    }
}

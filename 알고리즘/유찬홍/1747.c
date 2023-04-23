#include <stdio.h>

int main() {
    int n, arr[1005001] = {0};
    arr[1] = 1;
    for (int i = 2; i <= 1002; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= 1005000; j += i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    while (1) {
        int n1 = n, a = -1;
        if (!arr[n]) {
            char s[10];
            while (n1 > 0) {
                char n2 = n1 % 10;
                n1 /= 10;
                s[++a] = n2 + 48;
            }
            int c = 0;
            for (int i = a, j = 0; i >= 0; i--, j++) {
                if (s[i] == s[j]) c++;
            }
            if (c == a + 1) {
                for (int i = a; i >= 0; i--) {
                    printf("%c", s[i]);
                }
                break;
            }
        }
        n++;
    }
}

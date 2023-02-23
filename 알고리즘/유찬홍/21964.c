#include <stdio.h>

int main() {
    int n;
    char arr[100001];
    scanf("%d %s", &n, arr);
    for (int i = 0; i < n; i++) {
        if (n - i <= 5) printf("%c", arr[i]);
    }
    return 0;
}
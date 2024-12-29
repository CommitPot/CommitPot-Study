#include <stdio.h>

int main() {
    int n, i = 0, sum = 0;
    char arr[100];
    scanf("%d", &n);
    while (n > 0) {
        if (n % 2 == 0) arr[i++] = '0';
        else arr[i++] = '1';
        n /= 2;
    }
    for (int j = i - 1, k = 1; j >= 0; j--, k *= 2) {
        sum += arr[j] == '1' ? k : 0;
    }
    printf("%d", sum);
}

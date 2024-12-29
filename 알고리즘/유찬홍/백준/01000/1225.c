#include <stdio.h>
#include <string.h>

int main() {
    long long int sum = 0;
    char arr[10001], arr1[10001];
    scanf("%s %s", arr, arr1);
    int len = strlen(arr), len1 = strlen(arr1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len1; j++) {
            sum += (arr[i] - 48) * (arr1[j] - 48);
        }
    }
    printf("%lld", sum);
}
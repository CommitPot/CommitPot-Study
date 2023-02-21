#include <stdio.h>
#include <string.h>


int main() {
    char arr[100000001];
    scanf("%s", arr);
    int len = strlen(arr), sum = 0, sum1 = 0;
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        sum += arr[i], sum1 += arr[j];
    }
    if (sum == sum1) printf("LUCKY");
    else printf("READY");
}
#include <stdio.h>
#include <string.h>

int isPalindrome(char *s, int l, int r) {
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return isPalindrome(s, l + 1, r - 1);
}

int main() {
    char arr[101];
    scanf("%s", arr);
    int len = strlen(arr);
    printf("%d", isPalindrome(arr, 0, strlen(arr) - 1));
    return 0;
}
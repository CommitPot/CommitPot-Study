#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(char *s, int l, int r) {
    count++;
    if (l >= r) return count;
    else if (s[l] != s[r]) return count;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(char *s, int l, int r) {
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return isPalindrome(s, l + 1, r - 1);
}

int main() {
    int n;
    char arr[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        printf("%d %d\n", isPalindrome(arr, 0, strlen(arr) - 1), recursion(arr, 0, strlen(arr) - 1));
        count = 0;
    }
    return 0;
}
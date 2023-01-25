#include <stdio.h>
#include <string.h>


int palindrome(char *arr, int j, int k, int c) {
    if (c > 1) return 2;
    while (j < k) {
        if (arr[j] == arr[k]) {
            j++, k--;
        } else {
            if (!palindrome(arr, j + 1, k, c + 1) || !palindrome(arr, j, k - 1, c + 1)) return 1;
            else return 2;
        }
    }
    return 0;
}

int main() {
    int n;
    char arr[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        int j = 0, k = strlen(arr) - 1;
        printf("%d\n", palindrome(arr, j, k, 0));
    }
    return 0;
}
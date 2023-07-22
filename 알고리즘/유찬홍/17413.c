#include <stdio.h>
#include <string.h>

int main() {
    char arr[100001], arr1[100001], stack[100001];
    scanf("%[^\n]s", arr);
    int len = strlen(arr), len1 = 0, top = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == '<') {
            while (top != -1) {
                arr1[len1++] = stack[top--];
            }
            while (arr[i] != '>') {
                arr1[len1++] = arr[i];
                i++;
            }
            arr1[len1++] = '>';
        } else {
            if (arr[i] == ' ') {
                while (top != -1) {
                    arr1[len1++] = stack[top--];
                }
                arr1[len1++] = ' ';
            } else {
                stack[++top] = arr[i];
            }
        }
    }
    while (top != -1) {
        arr1[len1++] = stack[top--];
    }
    printf("%s", arr1);
}

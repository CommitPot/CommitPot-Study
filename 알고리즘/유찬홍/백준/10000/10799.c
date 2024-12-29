#include <stdio.h>
#include <string.h>

int main() {
    int count = 0, c = 0, top = 0;
    char stack[100001], arr[100001];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        if (arr[i] == '(') stack[top++] = arr[i];
        else {
            if (arr[i - 1] == '(') {
                top--;
                count += top;
            } else top--, count++;
        }
    }
    printf("%d", count);
    return 0;
}
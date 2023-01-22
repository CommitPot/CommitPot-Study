#include <stdio.h>
#include <string.h>

int main() {
    int n, c = 0, arr1[26], top = -1;
    double stack[100];
    char arr[101];
    scanf("%d %s", &n, arr);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    int len = strlen(arr);
    for (int i = 65; i < 91; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[j] == i) arr[j] = arr1[c] + 48;
        }
        c++;
    }
    double op1, op2;
    for (int i = 0; i < len; i++) {
        if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {
            op2 = stack[top--];
            op1 = stack[top--];
            switch (arr[i]) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op1 - op2;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    stack[++top] = op1 / op2;
                    break;
            }
        } else {
            stack[++top] = arr[i] - 48;
        }
    }
    printf("%.2lf", stack[0]);
    return 0;
}
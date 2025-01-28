#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[3][9];
    scanf("%s %s %s", s[0], s[1], s[2]);
    int a = atoi(s[2]) ? atoi(s[2]) + 1 : atoi(s[1]) ? atoi(s[1]) + 2 : atoi(s[0]) + 3;
    if (a % 3 && a % 5) printf("%d", a);
    else printf("%s", a % 3 ? "Buzz" : a % 5 ? "Fizz" : "FizzBuzz");
}

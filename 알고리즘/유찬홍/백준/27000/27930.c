#include <stdio.h>

int main() {
    int a = 0, b = 0;
    char s[500001], y[] = "YONSEI", k[] = "KOREA";
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
       if (y[a] == s[i]) a++;
       if (k[b] == s[i]) b++;
       if (a == 6 | b == 5) break; 
    }
    printf("%s", b > 4 ? k : y);
}

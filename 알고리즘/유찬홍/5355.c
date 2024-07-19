#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        double n;
        char s[10];
        scanf("%lf %[^\n]", &n, s);
        for (int i = 0; s[i]; i++) {
            if (s[i] == ' ') continue;
            if (s[i] == '@') n *= 3;
            if (s[i] == '%') n += 5;
            if (s[i] == '#') n -= 7;
        }
        printf("%.2lf\n", n);
    }
}

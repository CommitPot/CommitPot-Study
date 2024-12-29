#include <stdio.h>

int f(char c) {
    return (c == 41 ? 2 : c % 10) - 2;
}

int main() {
    char s[31];
    int v[31], t = -1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 40 || s[i] == 91) v[++t] = f(s[i]);
        else {
            if (t == -1) *s = 0;
            else if (v[t] > 1) {
                if (f(s[i]) - v[t - 1] == 2) v[t - 1] = v[t] * (f(s[i]) + 2), t--;
                else *s = 0;
            } else if (f(s[i]) - v[t] == 2) v[t] = f(s[i]) + 2;
            else *s = 0;
        }
        while (t && v[t] > 1 && v[t - 1] > 1) v[t - 1] += v[t], t--;
    }
    printf("%d", *s && !t && v[0] > 1 ? v[0] : 0);
}

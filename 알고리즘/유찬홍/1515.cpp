#include <cstdio>
#include <string>

using namespace std;

int main() {
    int n = 1, k = 0;
    string a, b = "1";
    char s[3001];
    scanf("%s", s);
    a = s;
    for (auto i: a) {
        bool d = true;
        while (d) {
            for (int j = k; j < b.size(); j++) {
                if (b[j] == i) {
                    k = j + 1;
                    d = false;
                    break;
                }
            }
            if (d) b = to_string(++n), k = 0;
        }
    }
    printf("%d", n);
}

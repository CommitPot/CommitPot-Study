#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char a;
    cin >> a;
    switch (a) {
        case 'M':
            cout << "MatKor";
            break;
        case 'W':
            cout << "WiCys";
            break;
        case 'C':
            cout << "CyKor";
            break;
        case 'A':
            cout << "AlKor";
            break;
        case '$':
            cout << "$clear";
            break;
    }
}

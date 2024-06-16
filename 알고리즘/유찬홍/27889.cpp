#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    if (s == "NLCS") cout << "North London Collegiate School";
    if (s == "BHA") cout << "Branksome Hall Asia";
    if (s == "KIS") cout << "Korea International School";
    if (s == "SJA") cout << "St. Johnsbury Academy";
}

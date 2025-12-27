#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string s;
    cin >> n;
    unordered_map<string, string> map;
    map["Algorithm"] = "204";
    map["DataAnalysis"] = "207";
    map["ArtificialIntelligence"] = "302";
    map["CyberSecurity"] = "B101";
    map["Network"] = "303";
    map["Startup"] = "501";
    map["TestStrategy"] = "105";
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << map[s] << "\n";
    }
}

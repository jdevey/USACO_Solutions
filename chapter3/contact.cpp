/*
ID: deveyjo1
TASK: contact
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w+", stdout);
#endif
    int a, b, selected;
    cin >> a >> b >> selected;
    string line, s;
    while (getline(cin, line)) {
        s += line;
    }
    int n = s.size();
    map<string, int> m;
    for (int i = 0; i < n; ++i) {
        string basis = s.substr(i, a - 1);
        for (int j = i + a - 1; j < min(i + b, n); ++j) {
            basis += s[j];
            ++m[basis];
        }
    }
    auto cmpLambda = [](const string& a, const string& b) {
        return a.size() == b.size() ? a < b : a.size() < b.size();
    };
    map<int, vector<string>, greater<>> ans;
    for (auto& x : m) {
        ans[x.second].push_back(x.first);
    }
    for (auto& x : ans) {
        cout << x.first << endl;
        sort(x.second.begin(), x.second.end(), cmpLambda);
        for (int i = 0; i < x.second.size(); ++i) {
            bool newline = i == x.second.size() - 1 || i % 6 == 5;
            cout << x.second[i] << (newline ? "\n" : " ");
        }
        --selected;
        if (selected == 0) {
            break;
        }
    }
	return 0;
}

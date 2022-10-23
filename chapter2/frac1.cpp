/*
ID: deveyjo1
TASK: frac1
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i <= n; ++i) {
        for (int j = max(i, 1); j <= n; ++j) {
            int g = __gcd(i, j), num = i / g, den = j / g;
            if (!vis[num][den]) {
                a.emplace_back(num, den);
                vis[num][den] = true;
            }
        }
    }
    sort(a.begin(), a.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first * b.second < b.first * a.second;
    });
    for (auto x : a) {
        cout << x.first << '/' << x.second << endl;
    }
	return 0;
}

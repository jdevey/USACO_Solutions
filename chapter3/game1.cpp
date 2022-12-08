/*
ID: deveyjo1
TASK: game1
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i].first = a[i];
        dp[i][i].second = 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j + i < n; ++j) {
            int left = a[j] + dp[j + 1][j + i].second;
            int right = a[j + i] + dp[j][j + i - 1].second;
            dp[j][j + i].first = max(left, right);
            dp[j][j + i].second = left >= right ? dp[j + 1][j + i].first : dp[j][j + i - 1].first;
        }
    }
    cout << dp[0][n - 1].first << ' ' << dp[0][n - 1].second << endl;
	return 0;
}

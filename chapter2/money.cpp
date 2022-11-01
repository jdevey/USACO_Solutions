/*
ID: deveyjo1
TASK: money
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("money.in", "r", stdin);
    freopen("money.out", "w+", stdout);
#endif
    int v, n;
    cin >> v >> n;
    vector<int> coins(v);
    for (int i = 0; i < v; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<vector<ll>> dp(v + 1, vector<ll>(n + 1));
    for (int i = 0; i <= v; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= v; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);
        }
    }
    cout << dp[v][n] << endl;
	return 0;
}

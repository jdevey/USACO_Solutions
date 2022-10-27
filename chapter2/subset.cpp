/*
ID: deveyjo1
TASK: subset
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tri(int n) {
    return n * (n + 1) / 2;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<map<int, ll>> dp(n + 1, map<int, ll>());
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = -tri(i); j <= tri(i); ++j) {
            dp[i][j] = dp[i - 1][i - j] + dp[i - 1][i + j];
        }
    }
    cout << dp[n][0] / 2 << endl;
	return 0;
}

/*
ID: deveyjo1
TASK: numtri
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]) + a[i][j];
        }
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, dp[n][i + 1]);
    }
    cout << mx << endl;
	return 0;
}

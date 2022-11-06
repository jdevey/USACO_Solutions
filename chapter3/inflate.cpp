/*
ID: deveyjo1
TASK: inflate
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w+", stdout);
#endif
    int m, n;
    scanf("%d %d", &m, &n);
    pair<int, int> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second >> a[i].first;
    }
    int dp[m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m - a[i].first; ++j) {
            dp[j + a[i].first] = max(dp[j + a[i].first], dp[j] + a[i].second);
        }
    }
    printf("%d\n", dp[m]);
	return 0;
}

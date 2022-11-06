/*
ID: deveyjo1
TASK: stamps
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w+", stdout);
#endif
    int k, n;
    cin >> k >> n;
    int stamps[n], maxstamp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> stamps[i];
        maxstamp = max(maxstamp, stamps[i]);
    }
    sort(stamps, stamps + n);
    int end = maxstamp * k;
    vector<uint8_t> dp(end + 1);
    for (int i = 0; i < n; ++i) {
        dp[stamps[i]] = 1;
    }
    for (int i = 1; i <= end; ++i) {
        if (dp[i] == 0 || dp[i] == k) {
            continue;
        }
        for (int j = 0; j < n && i + stamps[j] <= end; ++j) {
            int value = stamps[j];
            uint8_t nxt = dp[i + value];
            uint8_t nw = dp[i] + 1;
            dp[i + value] = nxt == 0 ? nw : min(nxt, nw);
        }
    }
    int best = 0, last0 = 0;
    for (int i = 1; i <= end; ++i) {
        if (dp[i] > 0) {
            best = max(best, i - last0);
        }
        else {
            last0 = i;
        }
    }
    cout << best << endl;
	return 0;
}

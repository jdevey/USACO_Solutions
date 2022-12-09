/*
ID: deveyjo1
TASK: rockers
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w+", stdout);
#endif
    int n, t, m;
    cin >> n >> t >> m;
    int best = 0;
    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        vector<bool> comb(n);
        for (int j = 0, cp = i; j < n; ++j, cp >>= 1) {
            comb[j] = cp % 2;
        }
        vector<int> used(m);
        int fit = 0;
        for (int j = 0, pt = 0; j < n; ++j) {
            if (comb[j] && songs[j] <= t) {
                if (used[pt] + songs[j] > t) {
                    ++pt;
                    if (pt == m) {
                        break;
                    }
                }
                used[pt] += songs[j];
                ++fit;
            }
        }
        best = max(best, fit);
    }
    cout << best << endl;
	return 0;
}

/*
ID: deveyjo1
TASK: kimbits
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w+", stdout);
#endif
    ll n, L, I;
    cin >> n >> L >> I;
    vector<vector<ll>> ncr(32, vector<ll>(32)), ncrs(32, vector<ll>(32));
    for (int i = 0; i < 32; ++i) {
        ncr[i][0] = 1;
        ncrs[i][0] = 1;
        ncrs[0][i] = 1;
    }
    for (int i = 1; i < 32; ++i) {
        for (int j = 1; j < 32; ++j) {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
            ncrs[i][j] = ncr[i][j] + ncrs[i][j - 1];
        }
    }
    string ans(n, '0');
    while (L > 0 && I > 1) {
        int len = 0;
        while (ncrs[len][L] < I) {
            ++len;
        }
        ans[n - len] = '1';
        I -= ncrs[len - 1][L];
        --L;
    }
    cout << ans << endl;
	return 0;
}

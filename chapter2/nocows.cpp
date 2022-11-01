/*
ID: deveyjo1
TASK: nocows
LANG: C++17
*/
#include <bits/stdc++.h>
#define MD 9901
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w+", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector<vector<int>> maxheightdp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; ++i) {
        maxheightdp[i][1] = 1;
    }
    for (int i = 2; i <= k; ++i) {
        for (int j = 3; j <= n; ++j) {
            for (int m = 1; m < j - 1; ++m) {
                maxheightdp[i][j] += maxheightdp[i - 1][m] * maxheightdp[i - 1][j - m - 1];
                maxheightdp[i][j] %= MD;
            }
        }
    }
    cout << (maxheightdp[k][n] - maxheightdp[k - 1][n] + MD) % MD << endl;
	return 0;
}

/*
ID: deveyjo1
TASK: range
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("range.in", "r", stdin);
    freopen("range.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<vector<int>> ps(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ps[i][j] = (i == 0 ? 0 : ps[i - 1][j]) +
                    (j == 0 ? 0 : ps[i][j - 1]) -
                    (i > 0 && j > 0 ? ps[i - 1][j - 1] : 0) +
                    (grid[i][j] == '1');
        }
    }
    vector<int> found(251);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            for (int k = 2; k <= min(i, j) + 1; ++k) {
                int sm = ps[i][j] -
                        (i + 1 == k ? 0 : ps[i - k][j]) -
                        (j + 1 == k ? 0 : ps[i][j - k]) +
                        (i - k >= 0 && j - k >= 0 ? ps[i - k][j - k] : 0);
                found[k] += sm == k * k;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (found[i] > 0) {
            cout << i << ' ' << found[i] << endl;
        }
    }
	return 0;
}

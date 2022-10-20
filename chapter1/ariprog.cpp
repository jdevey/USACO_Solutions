/*
ID: deveyjo1
TASK: ariprog
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w+", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int mx = m * m * 2 + 1;
    bool cs[mx];
    vector<int> bisquares;
    memset(cs, 0, sizeof(cs));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            int sm = i * i + j * j;
            if (!cs[sm]) {
                bisquares.push_back(sm);
                cs[i * i + j * j] = true;
            }
        }
    }
    sort(bisquares.begin(), bisquares.end());
    vector<pair<int, int>> ans;
    for (int i = 0; i < bisquares.size(); ++i) {
        // With second operand in the conditional, the slowest run is approximately 10x faster
        for (int j = i + 1; j < bisquares.size() && bisquares[i] + (bisquares[j] - bisquares[i]) * (n - 1) < mx; ++j) {
            int cnt = 1;
            for (int k = bisquares[j]; k < mx; k += (bisquares[j] - bisquares[i])) {
                if (cs[k]) {
                    ++cnt;
                } else {
                    break;
                }
                if (cnt == n) {
                    ans.emplace_back(bisquares[i], bisquares[j] - bisquares[i]);
                    break;
                }
            }
        }
    }
    sort(ans.begin(), ans.end(), [](const pair<int, int>& a, const pair <int, int>& b) {
        return a.second == b.second ? a < b : a.second < b.second;
    });
    printf(ans.empty() ? "NONE\n" : "");
    for (auto x : ans) {
        printf("%d %d\n", x.first, x.second);
    }
    return 0;
}

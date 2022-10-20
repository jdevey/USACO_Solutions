/*
ID: deveyjo1
TASK: milk3
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(vector<int> &capacity, vector<int> &buckets, vector<bool> &vis, set<int> &ans) {
    int hash = buckets[0] * 441 + buckets[1] * 21 + buckets[2];
    if (vis[hash]) {
        return;
    }
    vis[hash] = true;
    if (buckets[0] == 0) {
        ans.insert(buckets[2]);
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int pour = min(buckets[i], capacity[j] - buckets[j]);
            if (pour > 0) {
                buckets[i] -= pour;
                buckets[j] += pour;
                dfs(capacity, buckets, vis, ans);
                buckets[i] += pour;
                buckets[j] -= pour;
            }
        }
    }
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w+", stdout);
#endif
    vector<int> capacity(3), buckets(3, 0);
    cin >> capacity[0] >> capacity[1] >> capacity[2];
    buckets[2] = capacity[2];
    vector<bool> vis(21 * 21 * 21, false);
    set<int> ans;
    dfs(capacity, buckets, vis, ans);
    for (auto x : ans) {
        cout << x << (x == *--ans.end() ? "" : " ");
    }
    cout << endl;
    return 0;
}

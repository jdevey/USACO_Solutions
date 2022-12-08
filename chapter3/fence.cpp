/*
ID: deveyjo1
TASK: fence
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void hierholz(vector<vector<pair<int, int>>>& adj, vector<int>& path, vector<bool>& vis, int curr) {
    for (auto& e : adj[curr]) {
        if (vis[e.second]) {
            continue;
        }
        vis[e.second] = true;
        hierholz(adj, path, vis, e.first);
    }
    path.push_back(curr);
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w+", stdout);
#endif
    int n, m;
    cin >> m;
    vector<vector<pair<int, int>>> adj;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        n = max({n, a, b});
        if (adj.size() < n) {
            adj.resize(n);
        }
        --a;
        --b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> path;
    vector<bool> vis(m + 1);
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() % 2 == 1) {
            start = i;
            break;
        }
    }
    hierholz(adj, path, vis, start);
    for (int i = path.size() - 1; i > -1; --i) {
        cout << path[i] + 1 << endl;
    }
	return 0;
}

/*
ID: deveyjo1
TASK: agrinet
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 0});
    vector<bool> vis(n);
    int cst = 0;
    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        if (vis[top.second]) {
            continue;
        }
        vis[top.second] = true;
        cst += top.first;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                q.push({adj[top.second][i], i});
            }
        }
    }
    cout << cst << endl;
	return 0;
}

/*
ID: deveyjo1
TASK: butter
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w+", stdout);
#endif
    int cowCnt, n, m;
    cin >> cowCnt >> n >> m;
    vector<int> cows(cowCnt);
    for (int i = 0; i < cowCnt; ++i) {
        cin >> cows[i];
        --cows[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    int best = 1e9;
    for (int i = 0; i < n; ++i) {
        q.push({0, i});
        vector<int> dist(n, 1e9);
        dist[i] = 0;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            for (auto &a : adj[top.second]) {
                int newdist = dist[top.second] + a.second;
                if (newdist < dist[a.first]) {
                    dist[a.first] = newdist;
                    q.push({newdist, a.first});
                }
            }
        }
        int sm = 0;
        for (int j = 0; j < cowCnt; ++j) {
            sm += dist[cows[j]];
        }
        best = min(best, sm);
    }
    cout << best << endl;
    return 0;
}

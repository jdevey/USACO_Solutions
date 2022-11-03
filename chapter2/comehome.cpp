/*
ID: deveyjo1
TASK: comehome
LANG: C++17
*/
#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;

int toind(char c) {
    return isupper(c) ? c - 'A' : c - 'a' + 26;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w+", stdout);
#endif
    int m;
    cin >> m;
    vector<vector<pair<int,int>>> adj(52);
    for (int i = 0; i < m; ++i) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        int aind = toind(a);
        int bind = toind(b);
        adj[aind].emplace_back(bind, w);
        adj[bind].emplace_back(aind, w);
    }
    vector<bool> vis(52);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    q.push({0, 25});
    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        if (vis[top.second]) {
            continue;
        }
        vis[top.second] = true;
        if (top.second < 25) {
            cout << char(top.second + 'A') << ' ' << top.first << endl;
            break;
        }
        for (auto& a : adj[top.second]) {
            if (!vis[a.first]) {
                q.push({top.first + a.second, a.first});
            }
        }
    }
	return 0;
}

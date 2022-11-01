/*
ID: deveyjo1
TASK: concom
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct N {
    vector<pair<int, int>> in, out;
};

void update(vector<N> &adj, vector<vector<int>> &own, int a, int b, int amt) {
    own[a][b] += amt;
    if (own[a][b] > 50 && own[a][b] - amt < 51) {
        for (auto &c : adj[b].out) {
            update(adj, own, a, c.first, c.second);
        }
    }
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w+", stdout);
#endif
    int m, mx = 100;
    cin >> m;
    vector<N> adj(mx);
    for (int i = 0; i < m; ++i) {
        int from, to, p;
        cin >> from >> to >> p;
        --from;
        --to;
        adj[from].out.emplace_back(to, p);
        adj[to].in.emplace_back(from, p);
    }
    vector<vector<int>> own(mx, vector<int>(mx));
    for (int i = 0; i < mx; ++i) {
        for (auto &c : adj[i].out) {
            update(adj, own, i, c.first, c.second);
        }
    }
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < mx; ++j) {
            if (own[i][j] > 50 && i != j) {
                cout << i + 1 << ' ' << j + 1 << endl;
            }
        }
    }
    return 0;
}

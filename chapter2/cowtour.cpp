/*
ID: deveyjo1
TASK: cowtour
LANG: C++17
*/
#include <bits/stdc++.h>

#define inf 1e9
using namespace std;
typedef long long ll;

int getrep(vector<int>& reps, int x) {
    while (x != reps[x]) {
        x = reps[x];
    }
    return x;
}

bool same(vector<int>& reps, int a, int b) {
    return getrep(reps, a) == getrep(reps, b);
}

void unify(vector<int>& reps, vector<int>& sizes, int a, int b) {
    if (same(reps, a, b)) {
        return;
    }
    int ra = getrep(reps, a);
    int rb = getrep(reps, b);
    int sa = sizes[ra];
    int sb = sizes[rb];
    if (sa < sb) {
        sizes[rb] += sizes[ra];
        reps[ra] = rb;
    }
    else {
        sizes[ra] += sizes[rb];
        reps[rb] = ra;
    }
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<int, int>> loc(n);
    for (int i = 0; i < n; ++i) {
        cin >> loc[i].second >> loc[i].first;
    }
    vector<string> adj(n);
    for (int i = 0; i < n; ++i) {
        cin >> adj[i];
    }
    vector<int> sizes(n), reps(n);
    for (int i = 0; i < n; ++i) {
        sizes[i] = 1;
        reps[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == '1') {
                unify(reps, sizes, i, j);
            }
        }
    }
    vector<vector<double>> dist(n, vector<double>(n, inf));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] == '1') {
                dist[i][j] = hypot(abs(loc[j].first - loc[i].first), abs(loc[j].second - loc[i].second));
            }
            if (i == j) {
                dist[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // find max distance from vertex to other any vertex in component
    double totalmax = 0;
    vector<double> maxdist(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (same(reps, i, j)) {
                maxdist[i] = max(maxdist[i], dist[i][j]);
                totalmax = max(totalmax, maxdist[i]);
            }
        }
    }
    double mn = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!same(reps, i, j)) {
                double d = hypot(abs(loc[j].first - loc[i].first), abs(loc[j].second - loc[i].second));
                mn = min(mn, maxdist[i] + maxdist[j] + d);
            }
        }
    }
    cout << fixed << setprecision(6) << max(mn, totalmax) << endl;
    return 0;
}

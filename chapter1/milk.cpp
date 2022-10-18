/*
ID: deveyjo1
TASK: milk
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w+", stdout);
#endif
    int n, m, cost = 0;
    cin >> n >> m;
    vector <pair <int, int>> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m && n; ++i) {
        int bought = min(n, v[i].second);
        n -= bought;
        cost += bought * v[i].first;
    }
    cout << cost << endl;
	return 0;
}

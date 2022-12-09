/*
ID: deveyjo1
TASK: fence9
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w+", stdout);
#endif
    int n, m, p;
    cin >> n >> m >> p;
    if (m == 0 || p == 0) {
        cout << 0 << endl;
        return 0;
    }
    int sm = 0;
    for (int i = 1; i < m; ++i) {
        int r = (i * (n - p) - 1 + p * m) / m;
        int l = (n * i) / m;
        sm += r - l;
    }
    cout << sm << endl;
	return 0;
}

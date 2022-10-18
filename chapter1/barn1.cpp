/*
ID: deveyjo1
TASK: barn1
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w+", stdout);
#endif
    int m, s, c;
    cin >> m >> s >> c;
    vector <int> a(c), diff(c - 1);
    for (int i = 0; i < c; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < c - 1; ++i) {
        diff[i] = a[i + 1] - a[i] - 1;
    }
    sort(diff.begin(), diff.end(), greater<>());
    int total = 0;
    for (int i = 0; i < min(m - 1, c - 1); ++i) {
        total += diff[i];
    }
    cout << a.back() - a.front() - total + 1 << endl;
	return 0;
}

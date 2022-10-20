/*
ID: deveyjo1
TASK: skidesign
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int best = 1e9;
    for (int i = 0; i <= 83; ++i) {
        int total = 0;
        for (int j = 0; j < n; ++j) {
            int diff = a[j] >= i && a[j] <= i + 17 ? 0 : a[j] < i ? i - a[j] : a[j] - i - 17;
            total += diff * diff;
        }
        best = min(best, total);
    }
    cout << best << endl;
	return 0;
}

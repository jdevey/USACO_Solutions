/*
ID: deveyjo1
TASK: humble
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w+", stdout);
#endif
    int k, n;
    cin >> k >> n;
    int a[k];
    set<int> s;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(a, a + k);
    auto median = s.lower_bound(a[k / 2]);
    for (int i = 0; i < n - 1; ++i) {
        int beg = *s.begin();
        for (int j = 0; j < k && (ll) beg * a[j] < (1LL << 31); ++j) {
            int candidate = beg * a[j];
            if ((candidate <= *median || s.size() < 2 * n) && s.find(candidate) == s.end()) {
                s.insert(candidate);
                if (candidate < *median) {
                    advance(median, -1 * (s.size() % 2 == 1));
                }
                else {
                    advance(median, s.size() % 2 == 0);
                }
            }
        }
        advance(median, 1 * (s.size() % 2 == 1));
        s.erase(s.begin());
    }
    cout << *s.begin() << endl;
    return 0;
}

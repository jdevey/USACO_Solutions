/*
ID: deveyjo1
TASK: gift1
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    map <string, int> m;
    string indexed[n];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        indexed[i] = s;
        m[s] = 0;
    }
    for (int i = 0; i < n; ++i) {
        string name;
        cin >> name;
        int x, g;
        cin >> x >> g;
        if (g > 0) {
            int md = x % g;
            m[name] -= x - md;
            for (int j = 0; j < g; ++j) {
                string recipient;
                cin >> recipient;
                m[recipient] += x / g;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << indexed[i] << ' ' << m[indexed[i]] << endl;
    }
	return 0;
}

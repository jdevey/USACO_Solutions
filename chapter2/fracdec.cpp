/*
ID: deveyjo1
TASK: fracdec
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w+", stdout);
#endif
    int n, d;
    cin >> n >> d;
    string s = to_string(n / d) + '.';
    n %= d;
    map<int, int> m;
    while (true) {
        if (n == 0) {
            break;
        }
        if (m.find(n) != m.end()) {
            s.insert(m[n], "(");
            s += ')';
            break;
        }
        m[n] = s.size();
        n *= 10;
        int div = n / d;
        s += '0' + div;
        n %= d;
    }
    if (s.back() == '.') {
        s += '0';
    }
    for (int i = 0; i < s.size(); i += 76) {
        string printable = s.substr(i, min((int) s.size() - i, 76));
        cout << printable << endl;
    }
    return 0;
}

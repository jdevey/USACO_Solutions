/*
ID: deveyjo1
TASK: palsquare
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_b(int b, int n) {
    string ans;
    while (n) {
        int d = n % b;
        ans += d > 9 ? 'A' - 10 + d : '0' + d;
        n /= b;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool is_pal(const string& s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w+", stdout);
#endif
    int b;
    cin >> b;
    for (int i = 1; i <= 300; ++i) {
        if (is_pal(to_b(b, i * i))) {
            cout << to_b(b, i) << ' ' << to_b(b, i * i) << endl;
        }
    }
	return 0;
}

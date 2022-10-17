/*
ID: deveyjo1
TASK: dualpal
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_b(int b, int n) {
    string ans;
    while (n) {
        ans += '0' + n % b;
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
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w+", stdout);
#endif
    int n, s;
    cin >> n >> s;
    for (int i = s + 1, cnt = 0; cnt < n; ++i) {
        int pal_cnt = 0;
        for (int j = 2; j < 11; ++j) {
            pal_cnt += is_pal(to_b(j, i));
        }
        if (pal_cnt > 1) {
            cout << i << endl;
            ++cnt;
        }
    }
	return 0;
}

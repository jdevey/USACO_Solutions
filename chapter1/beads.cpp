/*
ID: deveyjo1
TASK: beads
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int last_diff(string &s, int ind, vector<vector<int>> &last) {
    return s[ind] == 'r' ? last[0][ind] : last[1][ind];
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w+", stdout);
#endif
    int n, mx = 0;
    cin >> n;
    string s;
    cin >> s;
    int r_count = 0, b_count = 0;
    for (int i = 0; i < n; ++i) {
        r_count += s[i] == 'b';
        b_count += s[i] == 'r';
    }
    if (!(r_count > 0 && b_count > 0)) {
        cout << n << endl;
        return 0;
    }
    s += s;
    n *= 2;
    vector<vector<int>> last(2, vector<int>(n, -1));
    last[0][0] = s[0] == 'b' ? 0 : -1;
    last[1][0] = s[0] == 'r' ? 0 : -1;
    for (int i = 1; i < n; ++i) {
        last[0][i] = s[i] == 'b' ? i : last[0][i - 1];
        last[1][i] = s[i] == 'r' ? i : last[1][i - 1];
        int ind = i;
        s[i] = s[i] == 'w' ? last[0][i] < last[1][i] ? 'r' : 'w' : s[i];
        for (int j = 0; j < 2 && ind != -1; ++j) {
            ind = last_diff(s, ind, last);
        }
        if (ind != -1) {
            mx = max(mx, i - ind);
        }
    }
    cout << min(mx, n / 2) << endl;
    return 0;
}

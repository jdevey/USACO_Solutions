/*
ID: deveyjo1
TASK: runround
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isBadCycle(vector<int>& a, int ind, int newNum) {
    int n = a.size();
    int orig = a[ind];
    a[ind] = newNum;
    int cnt = 0;
    int cs[n];
    memset(cs, 0, sizeof(cs));
    bool badCycle = false;
    for (int i = 0; i <= ind; ++cs[i], i = (i + a[i]) % n, ++cnt) {
        if (cs[i]) {
            if (cnt < n) {
                badCycle = true;
            }
            break;
        }
    }
    a[ind] = orig;
    return badCycle;
}

bool dfs(vector<int> &a, int n, vector<bool> &vis, vector<bool> &used, int ind, bool lesserAllowed) {
    if (ind == n) {
        return true;
    }
    int orig = a[ind];
    for (int i = lesserAllowed ? 1 : orig; i < 10; ++i) {
        if (!used[i] && !vis[(ind + i) % n] && i % n != 0 && !isBadCycle(a, ind, i)) {
            used[i] = true;
            vis[(ind + i) % n] = true;
            a[ind] = i;
            bool good = dfs(a, n, vis, used, ind + 1, lesserAllowed || i != orig);
            if (good) {
                return true;
            }
            used[i] = false;
            vis[(ind + i) % n] = false;
            a[ind] = orig;
        }
    }
    return false;
}

vector<int> solve1(int x) {
    string s;
    s = to_string(x);
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    vector<bool> vis(n, false), used(10, false);
    bool found = false;
    for (int i = a[0]; i < 10; ++i) {
        used[i] = true;
        vis[i % n] = true;
        a[0] = i;
        found |= dfs(a, n, vis, used, 1, i != s[0] - '0');
        if (found) {
            return a;
        }
        used[i] = false;
        vis[i % n] = false;
        a[0] = s[0] - '0';
    }
    return vector<int>();
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w+", stdout);
#endif
    vector<int> v = {4, 1, 5, 3, 2};
    nextPermutation(v);

    int n;
    cin >> n;
    ++n;
    vector<int> ans = solve1(n);
    if (ans.empty()) {
        int prod = 1;
        while (prod < n) {
            prod *= 10;
        }
        ans = solve1(prod);
    }
    for (auto d : ans) {
        cout << d;
    }
    cout << endl;
    return 0;
}

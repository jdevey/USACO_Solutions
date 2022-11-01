/*
ID: deveyjo1
TASK: zerosum
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    int prod = 1;
    for (int i = 1; i < n; ++i) {
        prod *= 3;
    }
    vector<int> basis;
    for (int i = 1; i <= n; ++i) {
        basis.push_back(i);
    }
    map<int, string> strop = {
            {0, " "},
            {1, "+"},
            {2, "-"}
    };
    vector<string> ans;
    for (int i = 0; i < prod; ++i) {
        vector<int> combo, bc = basis;
        for (int j = 0, cp = i; j < n - 1; ++j, cp /= 3) {
            combo.push_back(cp % 3);
        }
        string s = "1";
        for (int j = 1; j < n; ++j) {
            s += string(strop[combo[j - 1]]) + to_string(basis[j]);
        }
        for (int j = n - 2; j > -1; --j) {
            if (combo[j] == 0) {
                bc[j] = stoi(to_string(bc[j]) + to_string(bc[j + 1]));
                bc.erase(bc.begin() + j + 1);
                combo.erase(combo.begin() + j);
            }
        }
        int sm = bc[0];
        for (int j = 1; j < bc.size(); ++j) {
            sm += bc[j] * (combo[j - 1] == 1 ? 1 : -1);
        }
        if (sm == 0) {
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x << endl;
    }
    return 0;
}

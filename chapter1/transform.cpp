/*
ID: deveyjo1
TASK: transform
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(vector <string>& a, vector <string>& b) {
    bool good = true;
    for (int i = 0; i < a.size(); ++i) {
        good &= a[i] == b[i];
    }
    return good;
}

vector <string> do90(vector <string>& a) {
    vector <string> t(a.size(), string(a.size(), 0));
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a.size(); ++j) {
            t[j][a.size() - i - 1] = a[i][j];
        }
    }
    return t;
}

vector <string> do_flip(vector <string>& a) {
    vector <string> t(a.size(), string(a.size(), 0));
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a.size(); ++j) {
            t[i][j] = a[i][a.size() - j - 1];
        }
    }
    return t;
}

int solve(vector <string>& a, vector <string>& b) {
    a = do90(a);
    if (cmp(a, b)) {
        return 1;
    }
    a = do90(a);
    if (cmp(a, b)) {
        return 2;
    }
    a = do90(a);
    if (cmp(a, b)) {
        return 3;
    }
    a = do90(a);
    a = do_flip(a);
    if (cmp(a, b)) {
        return 4;
    }
    for (int i = 0; i < 3; ++i) {
        a = do90(a);
        if (cmp(a, b)) {
            return 5;
        }
    }
    a = do90(a);
    a = do_flip(a);
    if (cmp(a, b)) {
        return 6;
    }
    return 7;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector <string> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cout << solve(a, b) << endl;
	return 0;
}

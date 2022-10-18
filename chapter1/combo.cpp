/*
ID: deveyjo1
TASK: combo
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int pw(int a, int b) {
    int prod = 1;
    for (int i = 0; i < b; ++i) {
        prod *= a;
    }
    return prod;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector <int> i1(3), i2(3);
    for (int i = 0; i < 3; ++i) {
        cin >> i1[i];
        --i1[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> i2[i];
        --i2[i];
    }
    vector <int> s1, s2;
    vector <vector <int>> combos(pw(5, 3));
    for (int i = 0; i < pw(5, 3); ++i) {
        for (int j = 0, cp = i; j < 3; ++j) {
            combos[i].push_back(cp % 5 - 2);
            cp /= 5;
        }
    }
    for (auto& c : combos) {
        int r1 = 0, r2 = 0;
        for (int i = 0; i < 3; ++i) {
            r1 += (i1[i] + c[i] + n) % n * pw(n, i);
            r2 += (i2[i] + c[i] + n) % n * pw(n, i);
        }
        s1.push_back(r1);
        s2.push_back(r2);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector <int> set_and(125);
    auto it = set_intersection(s1.begin(), s1.begin() + 125, s2.begin(), s2.begin() + 125, set_and.begin());
    cout << 250 - (it - set_and.begin()) << endl;
	return 0;
}

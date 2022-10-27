/*
ID: deveyjo1
TASK: preface
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<int> m1 = {0, 1, 2, 3, 1, 0, 1, 2, 3, 1}, m2 = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
    int i = 0;
    int v = 0;
    int x = 0;
    int l = 0;
    int c = 0;
    int d = 0;
    int m = 0;
    for (int j = 1; j <= n; ++j) {
        i += m1[j % 10];
        v += m2[j % 10];
        x += m1[j / 10 % 10] + (j % 10 == 9);
        l += m2[j / 10 % 10];
        c += m1[j / 100 % 10] + (j / 10 % 10 == 9);
        d += m2[j / 100 % 10];
        m += m1[j / 1000 % 10] + (j / 100 % 10 == 9);
    }
    cout << "I " << i << endl;
    if (v) cout << "V " << v << endl;
    if (x) cout << "X " << x << endl;
    if (l) cout << "L " << l << endl;
    if (c) cout << "C " << c << endl;
    if (d) cout << "D " << d << endl;
    if (m) cout << "M " << m << endl;
	return 0;
}

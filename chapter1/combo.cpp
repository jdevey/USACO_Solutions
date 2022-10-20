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
    int prod = 1;
    for (int i = 0; i < 3; ++i) {
        prod *= max(min(5 - min((i1[i] - i2[i] + n) % n, (i2[i] - i1[i] + n) % n), n), 0);
    }
    int total = pw(min(n, 5), 3) * 2;
    cout << total - prod << endl;
	return 0;
}

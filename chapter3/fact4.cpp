/*
ID: deveyjo1
TASK: fact4
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w+", stdout);
#endif
    ll n, prod = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        prod *= i;
        while (prod % 10 == 0) {
            prod /= 10;
        }
        prod %= 100000;
    }
    cout << prod % 10 << endl;
	return 0;
}

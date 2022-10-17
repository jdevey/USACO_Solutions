/*
ID: deveyjo1
TASK: ride
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w+", stdout);
#endif
    string a, b;
    cin >> a >> b;
    auto l = [](string& s) {
        int prod = 1;
        for (auto c : s) {
            prod *= c - 'A' + 1;
        }
        return prod;
    };
    cout << (l(a) % 47 == l(b) % 47 ? "GO" : "STAY") << endl;
	return 0;
}

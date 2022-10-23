/*
ID: deveyjo1
TASK: hamming
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w+", stdout);
#endif
    int n, b, d;
    cin >> n >> b >> d;
    vector<int> codewords;
    for (int i = 0; i < 1 << b && codewords.size() < n; ++i) {
        bool good = true;
        for (auto c : codewords) {
            if (__builtin_popcount(c ^ i) < d) {
                good = false;
                break;
            }
        }
        if (good) {
            codewords.push_back(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << codewords[i] << (i == n - 1 ? "" : i % 10 == 9 ? "\n" : " ");
    }
    cout << endl;
	return 0;
}

/*
ID: deveyjo1
TASK: milk2
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 1000000

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector <int> cs(MX, 0);
    int break_max = 0, work_max = 0, curr_break = 0, curr_work = 0, curr = 0, mn = 1e9, mx = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        mn = min(mn, a);
        mx = max(mx, b);
        ++cs[a];
        --cs[b];
    }
    for (int i = mn; i < mx; ++i) {
        curr += cs[i];
        if (curr == 0) {
            curr_work = 0;
            ++curr_break;
            break_max = max(break_max, curr_break);
        }
        else {
            curr_break = 0;
            ++curr_work;
            work_max = max(work_max, curr_work);
        }
    }
    cout << work_max << ' ' << break_max << endl;
	return 0;
}

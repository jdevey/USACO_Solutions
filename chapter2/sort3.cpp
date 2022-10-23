/*
ID: deveyjo1
TASK: sort3
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<int>a(n), cs(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++cs[a[i]];
    }
    vector<vector<int>>pos(3, vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        int section = i < cs[0] ? 0 : i < cs[0] + cs[1] ? 1 : 2;
        ++pos[section][a[i]];
    }
    int cnt = 0;
    int onezero = min(pos[0][1], pos[1][0]);
    cnt += onezero;
    pos[0][1] -= onezero;
    pos[1][0] -= onezero;
    pos[0][0] += onezero;
    pos[1][1] += onezero;
    int twozero = min(pos[0][2], pos[2][0]);
    cnt += twozero;
    pos[0][2] -= twozero;
    pos[2][0] -= twozero;
    pos[0][0] += twozero;
    pos[2][2] += twozero;
    int twoone = min(pos[1][2], pos[2][1]);
    cnt += twoone;
    pos[1][2] -= twoone;
    pos[2][1] -= twoone;
    pos[1][1] += twoone;
    pos[2][2] += twoone;
    cnt += (pos[0][1] + pos[0][2] + pos[1][0] + pos[1][2] + pos[2][0] + pos[2][1]) * 2 / 3;
    cout << cnt << endl;
	return 0;
}

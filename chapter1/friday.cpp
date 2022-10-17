/*
ID: deveyjo1
TASK: friday
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_leap(int n) {
    return n % 400 == 0 || n % 100 != 0 && n % 4 == 0;
}

int days_per_mon(int y, int m) {
    if (m == 1) {
        return 28 + is_leap(y);
    }
    else if (m == 3 || m == 5 || m == 8 || m == 10) {
        return 30;
    }
    return 31;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w+", stdout);
#endif
    int n, day = 0;
    cin >> n;
    vector <int> days(7, 0);
    for (int i = 1900; i < 1900 + n; ++i) {
        for (int j = 0; j < 12; ++j) {
            ++days[day];
            day += days_per_mon(i, j);
            day %= 7;
        }
    }
    for (int i = 0; i < 7; ++i) {
        cout << days[i] << (i == 6 ? "" : " ");
    }
    cout << endl;
	return 0;
}

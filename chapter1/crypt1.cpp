/*
ID: deveyjo1
TASK: crypt1
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
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < pw(n, 5); ++i) {
        vector<int> nums;
        for (int j = 0, cp = i; j < 5; ++j) {
            nums.push_back(a[cp % n]);
            cp /= n;
        }
        int n1 = nums[0] * 100 + nums[1] * 10 + nums[2], n2 = nums[3] * 10 + nums[4];
        vector<int> required = {n2 / 10 * n1, n2 % 10 * n1, n1 * n2};
        if (required[0] > 999 || required[1] > 999 || required[2] > 9999) {
            continue;
        }
        bool good = true;
        for (auto r : required) {
            while (r) {
                if (find(a.begin(), a.end(), r % 10) == a.end()) {
                    good = false;
                    break;
                }
                r /= 10;
            }
        }
        cnt += good;
    }
    cout << cnt << endl;
    return 0;
}

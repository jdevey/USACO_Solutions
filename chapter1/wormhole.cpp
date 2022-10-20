/*
ID: deveyjo1
TASK: wormhole
LANG: C++17
*/
// This is the most complex 0-bug program I have ever written that worked first try.
// It is the solution to train.usaco.org/usacoprob2?a=bWWdavuWBbH&S=wormhole
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num_combinations(int n) {
    int prod = 1;
    for (int i = 1; i < n; ++++i) {
        prod *= i;
    }
    return prod;
}

vector <int> get_pairings(int x, int n) {
    vector <int> pairings;
    for (int i = n - 1; i > 0; ----i) {
        pairings.push_back(x % i);
        x /= i;
    }
    return pairings;
}

bool dfs(vector <pair <int, int>>& positions, vector <int>& pair_arr, vector <bool>& vis, int curr) {
    int n = positions.size();
    if (vis[curr]) {
        return true;
    }
    if (curr == n - 1) {
        return false;
    }
    vis[curr] = true;
    auto nxt = positions[curr + 1];
    if (nxt.first != positions[curr].first) { // diff y
        return false;
    }
    return dfs(positions, pair_arr, vis, pair_arr[curr + 1]);
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w+", stdout);
#endif
    int n;
    cin >> n;
    vector <pair <int, int>> positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> positions[i].second >> positions[i].first;
    }
    int cnt = 0;
    sort(positions.begin(), positions.end());
    for (int i = 0; i < num_combinations(n); ++i) {
        vector <int> pairings = get_pairings(i, n), pair_arr(n), available(n);
        for (int j = 0; j < n; ++j) {
            available[j] = j;
        }
        for (int j = 0; j < n / 2; ++j) {
            int curr = available[0], pairing = available[pairings[j] + 1];
            pair_arr[curr] = pairing;
            pair_arr[pairing] = curr;
            available.erase(available.begin() + pairings[j] + 1);
            available.erase(available.begin());
        }
        bool found_loop = false;
        for (int j = 0; j < n; ++j) {
            vector <bool> vis(n, false);
            if (dfs(positions, pair_arr, vis, j)) {
                found_loop = true;
                break;
            }
        }
        cnt += found_loop;
    }
    cout << cnt << endl;
	return 0;
}

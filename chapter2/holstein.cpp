/*
ID: deveyjo1
TASK: holstein
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w+", stdout);
#endif
    int v;
    cin >> v;
    vector<int> req(v);
    for (int i = 0; i < v; ++i) {
        cin >> req[i];
    }
    int g;
    cin >> g;
    vector<vector<int>> feeds(g, vector<int>(v));
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> feeds[i][j];
        }
    }
    vector<int> bestCombination(g + 1, 0);
    for (int i = 0; i < 1 << g; ++i) {
        vector<int> sums(v, 0), combination;
        for (int j = 0; j < g; ++j) {
            if (i & (1 << j)) {
                combination.push_back(j + 1);
                for (int k = 0; k < v; ++k) {
                    sums[k] += feeds[j][k];
                }
            }
        }
        bool good = true;
        for (int j = 0; j < v; ++j) {
            if (sums[j] < req[j]) {
                good = false;
                break;
            }
        }
        if (good && combination.size() < bestCombination.size()) {
            bestCombination = combination;
        }
    }
    cout << bestCombination.size() << ' ';
    for (int i = 0; i < bestCombination.size(); ++i) {
        cout << bestCombination[i] << (i == bestCombination.size() - 1 ? "" : " ");
    }
    cout << endl;
	return 0;
}

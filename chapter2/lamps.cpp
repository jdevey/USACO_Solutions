/*
ID: deveyjo1
TASK: lamps
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<bool>> masks = {
        {true},
        {true,  false},
        {false, true},
        {true,  false, false}
};

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w+", stdout);
#endif
    int n, numPresses;
    cin >> n >> numPresses;
    vector<vector<int>> onoff(2);
    for (int i = 0; i < 2; ++i) {
        int input;
        do {
            cin >> input;
            --input;
            onoff[i].push_back(input);
        } while (input != -2);
        onoff[i].pop_back();
    }
    vector<pair<string, int>> combinations;
    for (int i = 0; i < 16; ++i) {
        string lamps(n, '1');
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            if (i & (1 << j)) {
                ++cnt;
                for (int k = 0, mi = 0; k < n; ++k, mi = (mi + 1) % masks[j].size()) {
                    lamps[k] = '0' + (lamps[k] == '1') ^ masks[j][mi];
                }
            }
        }
        combinations.emplace_back(lamps, cnt);
    }
    sort(combinations.begin(), combinations.end());
    bool found = false;
    for (auto &c : combinations) {
        string &s = c.first;
        int &counter = c.second;
        if ((counter & 1) != (numPresses & 1) || numPresses < counter) {
            continue;
        }
        bool good = true;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < onoff[i].size(); ++j) {
                if ((~i & 1) ^ (s[onoff[i][j]] - '0')) {
                    good = false;
                    break;
                }
            }
            if (!good) {
                break;
            }
        }
        if (good) {
            found = true;
            cout << s << endl;
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

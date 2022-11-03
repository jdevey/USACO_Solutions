/*
ID: deveyjo1
TASK: ttwo
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>> direcs = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
};

int hashstate(int rot, int y, int x) {
    return rot * 100 + y * 10 + x;
}

bool isvalid(vector<string>& board, int y, int x) {
    return y > -1 && y < 10 && x > -1 && x < 10 && board[y][x] != '*';
}

void nxt(vector<string>& board, int& rot, int& y, int& x) {
    auto& d = direcs[rot];
    int newy = y + d.first;
    int newx = x + d.second;
    if (!isvalid(board, newy, newx)) {
        ++rot;
        rot %= 4;
    }
    else {
        y = newy;
        x = newx;
    }
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w+", stdout);
#endif
    vector<string> land(10);
    int fy, fx, frot = 0, cy, cx, crot = 0;
    for (int i = 0; i < 10; ++i) {
        cin >> land[i];
        int fpos = land[i].find('F');
        int cpos = land[i].find('C');
        if (fpos != string::npos) {
            fy = i;
            fx = fpos;
        }
        if (cpos != string::npos) {
            cy = i;
            cx = cpos;
        }
    }
    set<int> states;
    bool found = false;
    int stepcnt = 0;
    while (true) {
        if (fy == cy && fx == cx) {
            found = true;
            cout << stepcnt << endl;
            break;
        }
        int state = hashstate(frot, fy, fx) * 400 + hashstate(crot, cy, cx);
        if (states.find(state) != states.end()) {
            break;
        }
        states.insert(state);
        nxt(land, frot, fy, fx);
        nxt(land, crot, cy, cx);
        ++stepcnt;
    }
    if (!found) {
        cout << 0 << endl;
    }
	return 0;
}

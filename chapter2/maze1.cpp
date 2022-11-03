/*
ID: deveyjo1
TASK: maze1
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int w, h;

vector<pair<int, int>> direcs = {
        {-1, 0},
        {0,  1},
        {1,  0},
        {0,  -1}
};

bool isedge(vector<string> &board, int y, int x) {
    return y == 0 || y == 2 * h || x == 0 || x == 2 * w;
}

bool isvalid(vector<string> &board, int y, int x) {
    return y > 0 && y < 2 * h && x > 0 && x < 2 * w && board[y][x] == ' ';
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w+", stdout);
#endif
    cin >> w >> h;
    string line;
    getline(cin, line);
    vector<string> board;
    for (int i = 0; i < 2 * h + 1; ++i) {
        getline(cin, line);
        board.push_back(line);
    }
    vector<vector<vector<int>>> dists(2, vector<vector<int>>(2 * h + 1, vector<int>(2 * w + 1, (int)1e9)));
    int distinc = 0;
    for (int i = 0; i < 2 * h + 1; ++i) {
        for (int j = 0; j < 2 * w + 1; ++j) {
            if (isedge(board, i, j) && board[i][j] == ' ') {
                int sy = max(min(i, 2 * h - 1), 1);
                int sx = max(min(j, 2 * w - 1), 1);
                queue<pair<int, int>> q;
                q.push({sy, sx});
                dists[distinc][sy][sx] = 1;
                vector<vector<bool>> vis(2 * h + 1, vector<bool>(2 * w + 1));
                vis[sy][sx] = true;
                while (!q.empty()) {
                    auto &front = q.front();
                    q.pop();
                    for (auto &d : direcs) {
                        int newy = front.first + d.first;
                        int newx = front.second + d.second;
                        if (isvalid(board, newy, newx)) {
                            newy += d.first;
                            newx += d.second;
                            if (!vis[newy][newx]) {
                                q.push({newy, newx});
                                vis[newy][newx] = true;
                                dists[distinc][newy][newx] = dists[distinc][front.first][front.second] + 1;
                            }
                        }
                    }
                }
                ++distinc;
            }
        }
    }
    int mx = 0;
    for (int i = 1; i < 2 * h; ++ ++i) {
        for (int j = 1; j < 2 * w; ++ ++j) {
            if (dists[0][i][j] != (int) 1e9) {
                mx = max(mx, min(dists[0][i][j], dists[1][i][j]));
            }
        }
    }
    cout << mx << endl;
    return 0;
}

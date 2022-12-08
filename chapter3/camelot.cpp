/*
ID: deveyjo1
TASK: camelot
LANG: C++17
*/
#include <bits/stdc++.h>

#define inf 1000000000
using namespace std;
typedef long long ll;

vector<pair<int, int>> out = {
        {2,  1},
        {1,  2},
        {-1, 2},
        {-2, 1},
        {-2, -1},
        {-1, -2},
        {1,  -2},
        {2,  -1}
};

bool isValid(int h, int w, int y, int x) {
    return y > -1 && y < h && x > -1 && x < w;
}

int getKingDist(int y1, int y2, int x1, int x2) {
    return max(abs(y1 - y2), abs(x1 - x2));
}

struct Point {
    int y, x;
};

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w+", stdout);
#endif
    int h, w;
    cin >> h >> w;
    int n = h * w;
    char xin;
    int yin;
    cin >> xin >> yin;
    Point king{yin - 1, xin - 'A'};
    int kingInd = king.y * w + king.x;
    vector<Point> knights;
    while (cin >> xin) {
        cin >> yin;
        knights.push_back(Point{yin - 1, xin - 'A'});
    }
    vector<vector<int>> dist(n, vector<int>(n, inf));
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int y = front / w;
            int x = front % w;
            for (auto &o : out) {
                int ny = y + o.first;
                int nx = x + o.second;
                int nind = ny * w + nx;
                if (isValid(h, w, ny, nx) && dist[i][nind] == inf) {
                    dist[i][nind] = dist[i][front] + 1;
                    q.push(nind);
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        int meetX = i % w;
        int meetY = i / w;
        int kngDist = getKingDist(king.y, meetY, king.x, meetX);
        int total = kngDist;
        int bestKnightDelta = 0;
        bool optimum = false;
        for (auto &k : knights) {
            int knightInd = k.y * w + k.x;
            int knightShortest = dist[i][knightInd];
            if (knightShortest == inf) {
                total = inf;
                continue;
            }
            int basis = knightShortest + kngDist;
            total += knightShortest;
            if (optimum) {
                continue;
            }
            int bestDeltaForKnight = 0;
            for (int extraSteps = 0;; extraSteps += 2) {
                assert(extraSteps < max(h, w));
                int closestToKingDuringPath = getKingDist(k.y, king.y, k.x, king.x);
                Point currPos = k;
                for (int expDist = dist[i][knightInd] + extraSteps; expDist > 0; --expDist) {
                    Point bestNewSquare;
                    int bestKingDist = inf;
                    int preference = inf;
                    for (auto &o : out) {
                        int ny = currPos.y + o.first;
                        int nx = currPos.x + o.second;
                        if (!isValid(h, w, ny, nx)) {
                            continue;
                        }
                        int nind = ny * w + nx;
                        int kd = getKingDist(ny, king.y, nx, king.x);
                        if (dist[i][nind] <= expDist) {
                            int p = dist[nind][kingInd] * 100 + kd;
                            if (p < preference) {
                                preference = p;
                                bestNewSquare = Point{ny, nx};
                            }
                            bestKingDist = min(bestKingDist, kd);
                        }
                    }
                    currPos = bestNewSquare;
                    closestToKingDuringPath = min(closestToKingDuringPath, bestKingDist);
                }
                int delta = dist[i][knightInd] + extraSteps + closestToKingDuringPath - basis;
                if (delta >= bestDeltaForKnight) {
                    break;
                }
                bestDeltaForKnight = delta;
                if (extraSteps == 0 && closestToKingDuringPath == 0) {
                    optimum = true; // optimum
                }
            }
            bestKnightDelta = min(bestKnightDelta, bestDeltaForKnight);
        }
        total += bestKnightDelta;
        ans = min(ans, total);
    }
    cout << ans << endl;
    return 0;
}

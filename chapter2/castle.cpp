/*
ID: deveyjo1
TASK: castle
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    int y, x;
};

vector<Point> direcs = {
        Point{0, -1},
        Point({-1, 0}),
        Point({0, 1}),
        Point({1, 0})
};

bool isValid(int n, int m, int y, int x) {
    return y > -1 && y < n && x > -1 && x < m;
}

void dfs(vector<vector<int>>& walls, vector<vector<int>>& component, int componentId, int& componentSize, int currY, int currX) {
    int n = walls.size(), m = walls[0].size();
    component[currY][currX] = componentId;
    ++componentSize;
    for (int i = 0; i < direcs.size(); ++i) {
        if (walls[currY][currX] & (1 << i)) {
            continue;
        }
        int newY = currY + direcs[i].y;
        int newX = currX + direcs[i].x;
        if (isValid(n, m, newY, newX) && component[newY][newX] == -1) {
            dfs(walls, component, componentId, componentSize, newY, newX);
        }
    }
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w+", stdout);
#endif
    int m, n;
    cin >> m >> n;
    vector<vector<int>> walls(n, vector<int>(m)), component(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> walls[i][j];
        }
    }
    int componentCount = -1, largestComponent = 0;
    vector<int> componentSizes;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (component[i][j] == -1) {
                int componentSize = 0;
                ++componentCount;
                dfs(walls, component, componentCount, componentSize, i, j);
                largestComponent = max(largestComponent, componentSize);
                componentSizes.push_back(componentSize);
            }
        }
    }
    cout << componentCount + 1 << endl << largestComponent << endl;
    int bestCombined = 0, yCoord = -1, xCoord = -1;
    char direction = 'A';
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j > -1; --j) {
            int currComp = component[j][i], currSize = componentSizes[currComp];
            if (walls[j][i] & 2 && j > 0 && currComp != component[j - 1][i]) {
                int combinedSize = currSize + componentSizes[component[j - 1][i]];
                if (combinedSize > bestCombined) {
                    bestCombined = combinedSize;
                    yCoord = j + 1;
                    xCoord = i + 1;
                    direction = 'N';
                }
            }
            if (walls[j][i] & 4 && i < m - 1 && currComp != component[j][i + 1]) {
                int combinedSize = currSize + componentSizes[component[j][i + 1]];
                if (combinedSize > bestCombined) {
                    bestCombined = combinedSize;
                    yCoord = j + 1;
                    xCoord = i + 1;
                    direction = 'E';
                }
            }
        }
    }
    assert(direction != 'A');
    cout << bestCombined << endl << yCoord << ' ' << xCoord << ' ' << direction << endl;
	return 0;
}

/*
ID: deveyjo1
TASK: prefix
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct N {
    char letter;
    bool isEndpoint = false, isRoot;
    vector<N> children;

    explicit N(char _letter, bool _isRoot = false) : letter(_letter), isRoot(_isRoot) {}

    void insert(string& p, int ind) {
        if (ind == p.size() - 1 && !isRoot) {
            isEndpoint = true;
            return;
        }
        int next = isRoot ? ind : ind + 1;
        bool found = false;
        for (auto& c : children) {
            if (p[next] == c.letter) {
                found = true;
                c.insert(p, next);
            }
        }
        if (!found) {
            children.emplace_back(p[next]);
            children.back().insert(p, next);
        }
    }

    bool contains(string& q, int ind) {
        if (ind == q.size() - 1 && !isRoot) {
            return isEndpoint;
        }
        int next = isRoot ? ind : ind + 1;
        for (auto& c : children) {
            if (q[next] == c.letter) {
                return c.contains(q, next);
            }
        }
        return false;
    }
};

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w+", stdout);
#endif
    N trie('#', true);
    string input;
    while (true) {
        cin >> input;
        if (input == ".") {
            break;
        }
        trie.insert(input, 0);
    }
    string s;
    while(getline(cin, input)) {
        s += input;
    }
    s.erase(remove_if(s.begin(), s.end(), [](char c) {
        return isspace(c);
    }), s.end());
    bool endpoints[s.size()];
    memset(endpoints, 0, sizeof(endpoints));
    int best = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || endpoints[i - 1]) {
            for (int j = i; j < min((int) s.size(), i + 10); ++j) {
                string sub = s.substr(i, j - i + 1);
                if (trie.contains(sub, 0)) {
                    endpoints[j] = true;
                    best = max(best, j + 1);
                }
            }
        }
    }
    cout << best << endl;
    return 0;
}

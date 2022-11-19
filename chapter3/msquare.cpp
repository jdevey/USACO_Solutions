/*
ID: deveyjo1
TASK: msquare
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string flip(string s) {
    swap(s[0], s[7]);
    swap(s[1], s[6]);
    swap(s[2], s[5]);
    swap(s[3], s[4]);
    return s;
}

string shift(const string& s) {
    string newstate = s;
    newstate[3] = s[2];
    newstate[2] = s[1];
    newstate[1] = s[0];
    newstate[0] = s[3];
    newstate[4] = s[5];
    newstate[5] = s[6];
    newstate[6] = s[7];
    newstate[7] = s[4];
    return newstate;
}

string rotate(const string& s) {
    string newstate = s;
    newstate[1] = s[6];
    newstate[2] = s[1];
    newstate[5] = s[2];
    newstate[6] = s[5];
    return newstate;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w+", stdout);
#endif
    string s(8, char(0));
    for (int i = 0; i < 8; ++i) {
        cin >> s[i];
    }
    queue<pair<string, string>> q;
    q.push({"12345678", ""});
    unordered_set<string> vis;
    string ans;
    while (!q.empty()) {
        auto& front = q.front();
        string state = front.first;
        string sequence = front.second;
        q.pop();
        if (state == s) {
            ans = sequence;
            break;
        }
        string flipped = flip(state);
        if (vis.find(flipped) == vis.end()) {
            vis.insert(flipped);
            q.push({flipped, sequence + 'A'});
        }
        string shifted = shift(state);
        if (vis.find(shifted) == vis.end()) {
            vis.insert(shifted);
            q.push({shifted, sequence + 'B'});
        }
        string rotated = rotate(state);
        if (vis.find(rotated) == vis.end()) {
            vis.insert(rotated);
            q.push({rotated, sequence + 'C'});
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i += 60) {
        cout << ans.substr(i, 60) << endl;
    }
    if (ans.empty()) {
        cout << endl;
    }
	return 0;
}

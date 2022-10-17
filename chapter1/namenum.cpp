/*
ID: deveyjo1
TASK: namenum
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w+", stdout);
#endif
    vector <string> v;
    fstream fin("dict.txt");
    string line;
    while (fin >> line) {
        v.push_back(line);
    }
    string code;
    cin >> code;
    bool found = false;
    for (auto& s : v) {
        if (s.size() != code.size()) {
            continue;
        }
        bool good = true;
        for (int i = 0; i < code.size(); ++i) {
            if ((s[i] - 65 - (s[i] >= 'Q')) / 3 != code[i] - 50) {
                good = false;
                break;
            }
        }
        if (good) {
            found = true;
            cout << s << endl;
        }
    }
    if (!found) {
        cout << "NONE" << endl;
    }
	return 0;
}

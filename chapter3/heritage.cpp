/*
ID: deveyjo1
TASK: heritage
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct N {
    int value;
    char letter;
    N* left = nullptr, *right = nullptr;
    N(int _value, char _letter) : value(_value), letter(_letter) {}
    void insert(int _value, char _letter) {
        if (_value < value) {
            if (left) {
                left->insert(_value, _letter);
            }
            else {
                left = new N(_value, _letter);
            }
        }
        else {
            if (right) {
                right->insert(_value, _letter);
            }
            else {
                right = new N(_value, _letter);
            }
        }
    }
    void output() const {
        if (left) {
            left->output();
        }
        if (right) {
            right->output();
        }
        cout << letter;
    }
    ~N() {
        delete left;
        delete right;
    }
};

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w+", stdout);
#endif
    string preOrder, inOrder;
    cin >> preOrder >> inOrder;
    map<char, int> ordering;
    int n = preOrder.size();
    for (int i = 0; i < n; ++i) {
        ordering[preOrder[i]] = i;
    }
    N* root = new N(ordering[inOrder[0]], inOrder[0]);
    for (int i = 1; i < n; ++i) {
        root->insert(ordering[inOrder[i]], inOrder[i]);
    }
    root->output();
    cout << endl;
    delete root;
	return 0;
}

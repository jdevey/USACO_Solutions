/*
ID: deveyjo1
TASK: shopping
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Offer {
    int discount = 0;
    vector<pair<int, int>> items;
};

struct Item {
    int needed, price;
};

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w+", stdout);
#endif
    int s;
    cin >> s;
    vector<Offer> offers;
    for (int i = 0; i < s; ++i) {
        int cnt;
        cin >> cnt;
        offers.emplace_back();
        for (int j = 0; j < cnt; ++j) {
            int code, amt;
            cin >> code >> amt;
            offers.back().items.emplace_back(code, amt);
        }
        cin >> offers.back().discount;
    }
    int b;
    cin >> b;
    vector<Item> items;
    map<int, int> codes;
    for (int i = 0; i < b; ++i) {
        int c, k, p;
        cin >> c >> k >> p;
        items.push_back(Item{k + 1, p});
        codes[c] = i;
    }
    int sz = 1;
    for (auto& i : items) {
        sz *= i.needed;
    }
    vector<int> dp(sz);
    for (int i = 0; i < sz; ++i) {
        vector<int> pos;
        for (int j = 0, cp = i; j < items.size(); ++j) {
            pos.push_back(cp % items[j].needed);
            cp /= items[j].needed;
        }
        for (int j = 0; j < items.size(); ++j) {
            dp[i] += items[j].price * pos[j];
        }
        for (auto& o : offers) {
            vector<int> used(items.size());
            for (auto& item : o.items) {
                used[codes[item.first]] = item.second;
            }
            int prevInd = 0, multiplier = 1;
            bool good = true;
            for (int j = 0; j < items.size(); ++j) {
                int remainingItemNeeded = pos[j] - used[j];
                if (remainingItemNeeded < 0) {
                    good = false;
                    break;
                }
                prevInd += remainingItemNeeded * multiplier;
                multiplier *= items[j].needed;
            }
            if (good) {
                dp[i] = min(dp[i], dp[prevInd] + o.discount);
            }
        }
    }
    cout << dp.back() << endl;
	return 0;
}

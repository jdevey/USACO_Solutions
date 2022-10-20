/*
ID: deveyjo1
TASK: sprime
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is_prime(vector<int> &primes, int n) {
    for (int i = 0; primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

void dfs(vector<int> &primes, int desired, int n, vector<int> &ans) {
    if (!is_prime(primes, n)) {
        return;
    }
    if (to_string(n).size() == desired) {
        ans.push_back(n);
    }
    else {
        n *= 10;
        for (int i = 1; i <= 9; ++i) {
            dfs(primes, desired, n + i, ans);
        }
    }
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w+", stdout);
#endif
    vector<int> primes, primepals({5, 7, 11});
    for (int i = 2; i < 10000; ++i) {
        bool prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            primes.push_back(i);
        }
    }
    int n;
    cin >> n;
    vector<int> ans, start({2, 3, 5, 7});
    for (auto x : start) {
        dfs(primes, n, x, ans);
    }
    for (auto x : ans) {
        printf("%d\n", x);
    }
    return 0;
}

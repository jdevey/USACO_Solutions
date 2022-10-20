/*
ID: deveyjo1
TASK: pprime
LANG: C++17
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(vector<int>& primes, int n) {
    for (int i = 0; primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

// Even-length palindromes cannot be prime (always divisible by 11)
int get_pal(int n) {
    string s = to_string(n);
    string t = s;
    s.pop_back();
    reverse(t.begin(), t.end());
    return stoi(s + t);
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w+", stdout);
#endif
    vector <int> primes, primepals({5, 7, 11});
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
    int a, b;
    cin >> a >> b;
    for (int i = 10; i < 10000; ++i) {
        int pal = get_pal(i);
        if (is_prime(primes, pal)) {
            primepals.push_back(pal);
        }
    }
    for (auto x : primepals) {
        if (x >= a && x <= b) {
            printf("%d\n", x);
        }
    }
	return 0;
}

/*
ID: deveyjo1
TASK: spin
LANG: C++17
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// first value of returned pair represents the modular multiplicative inverse of a with respect to b
pair<ll, ll> bezoutCoefficients(ll a, ll b) {
    ll q = a / b, s1 = 1, s2 = 0, t1 = 0, t2 = 1, temp;
    while (b > 0) {
        temp = b;
        b = a - q * b;
        a = temp;
        temp = s2;
        s2 = s1 - q * s2;
        s1 = temp;
        temp = t2;
        t2 = t1 - q * t2;
        t1 = temp;
        q = a / max(b, 1LL);
    }
    return {s1, t1};
}

struct Wedge {
    int start, extent;
};

struct Wheel {
    int speed;
    vector<Wedge> wedges;
};

void bruteSolve() {
    int numWheels = 5;
    vector<Wheel> wheels(numWheels);
    for (int i = 0; i < numWheels; ++i) {
        int speed, cnt;
        cin >> speed >> cnt;
        wheels[i].speed = speed;
        for (int j = 0; j < cnt; ++j) {
            int start, extent;
            cin >> start >> extent;
            wheels[i].wedges.push_back(Wedge{start, extent});
        }
    }
    int cs[360];
    memset(cs, 0, sizeof(cs));
    ll tfound = -1;
    for (ll t = 0; t < 360; ++t) {
        for (auto& wheel : wheels) {
            ll offset = t * wheel.speed;
            for (auto& wedge : wheel.wedges) {
                for (int p = 0; p <= wedge.extent; ++p) {
                    int pos = (offset + wedge.start + p) % 360;
                    ++cs[pos];
                }
            }
        }
        bool found = false;
        for (int c : cs) {
            if (c == numWheels) {
                found = true;
                break;
            }
        }
        if (found) {
            tfound = t;
            break;
        }
        memset(cs, 0, sizeof(cs));
    }
    cout << (tfound == -1 ? "none" : to_string(tfound)) << endl;
}

int main() {
#ifdef OFFLINE
    freopen("in.txt", "r", stdin);
#else
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w+", stdout);
#endif

//    cout << bezoutCoefficients(13, 360).first << endl;
    bruteSolve();


    return 0;
}

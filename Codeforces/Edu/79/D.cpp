//D.cpp
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 1e6 + 5;

vector<int> gift[N];
ll cnt[N], inv[N];

void init() {
    inv[1] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
}

int main() {
    init();
    int n;
    cin >> n;
    for (int i = 0, t; i < n; ++i) {
        cin >> t;
        gift[i].resize(t);
        for (int &j : gift[i]) {
            cin >> j;
            ++cnt[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        for (int j : gift[i]) tmp += cnt[j];
        ans = (ans + inv[gift[i].size()] * tmp % mod) % mod;
    }
    ans = ans * inv[n] % mod * inv[n] % mod;
    cout << ans << endl;
    return 0;
}
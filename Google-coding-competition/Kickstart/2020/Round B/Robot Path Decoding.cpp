//Robot Path Decoding.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll go(string &s, int l, int r, int mul) {
    pll res;
    for (int i = l; i <= r; ++i) {
        if (isdigit(s[i])) {
            int cnt = 0;
            for (int j = i + 1; j <= r; ++j) {
                if (s[j] == '(') ++cnt;
                if (s[j] == ')') --cnt;
                if (cnt == 0) {
                    pll t = go(s, i + 1, j, s[i] - '0');
                    i = j;
                    res.first += t.first;
                    res.second += t.second;
                    break;
                }
            }
        }
        if (s[i] == 'N') res.first += mod - 1;
        else if (s[i] == 'S') res.first += 1;
        else if (s[i] == 'E') res.second += 1;
        else if (s[i] == 'W') res.second += mod - 1;
        if (res.first > mod) res.first %= mod;
        if (res.second > mod) res.second %= mod;
    }
    res.first = res.first * mul;
    res.second = res.second * mul;
    if (res.first > mod) res.first %= mod;
    if (res.second > mod) res.second %= mod;
    return res;
}

int main() {
    int T;
    cin >> T;
    string s;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> s;
        pii ans = go(s, 0, s.length() - 1, 1);
        ans.first++; ans.second++;
        if (ans.first > mod) ans.first %= mod;
        if (ans.second > mod) ans.second %= mod;
        printf("Case #%d: %d %d\n", cas, ans.second, ans.first);
    }
    return 0;
}
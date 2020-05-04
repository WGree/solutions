//Overrandomized.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        ll u;
        cin >> u;
        map<char, ll> mp;
        set<char> S;
        string s;
        for (int i = 0; i < int(1e4); ++i) {
            cin >> u >> s;
            for (char c : s) S.emplace(c);
            ++mp[s[0]];
        }
        vector<pair<char, ll>> cnt(mp.begin(), mp.end());
        sort(cnt.begin(), cnt.end(), [](auto a, auto b) { return get<1>(a) > get<1>(b);});
        string ans;
        for (auto i : cnt) ans.push_back(i.first);
        for (char c : ans) S.erase(c);
        cout << "Case #" << cas << ": "
             << *S.begin() << ans << endl;
    }
    return 0;
}
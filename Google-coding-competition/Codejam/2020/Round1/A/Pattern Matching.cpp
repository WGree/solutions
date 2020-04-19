//Pattern Matching.cpp
#include <bits/stdc++.h>
using namespace std;

int n;
string ts[55];
vector<string> pre, suf, mid;

void prase() {
    pre.clear(); suf.clear(); mid.clear();
    for (int k = 0; k < n; ++k) {
        string &s = ts[k];
        int la = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                if (la == 0) pre.emplace_back(s.substr(la, i - la));
                else mid.emplace_back(s.substr(la, i - la));
                la = i + 1;
            }
        }
        suf.emplace_back(s.substr(la));
    }
}

bool check(string &s) {
    auto cmp = [&](string &a, string &b) { return a.length() > b.length(); };
    sort(pre.begin(), pre.end(), cmp);
    sort(suf.begin(), suf.end(), cmp);
    for (int i = 1; i < pre.size(); ++i) {
        if (pre[0].find(pre[i]) != 0) return true;
    }
    for (int i = 1; i < suf.size(); ++i) {
        if (suf[i].empty()) break;
        if (suf[0].rfind(suf[i]) != suf[0].length() - suf[i].length()) return true;
    }
    s = pre[0];
    for (string &t : mid) {
        s += t;
    }
    s += suf[0];
    return false;
}

int main() {
    int TT;
    cin >> TT;
    for (int cas = 1; cas <= TT; ++cas) {
        string ans;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> ts[i];
        prase();
        if (check(ans))
            ans = '*';
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}
//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    string s;
    while (q--) {
        cin >> s;
        string ans = s;
        ans.resize(unique(s.begin(), s.end())-s.begin());
        if (ans.size() == 1) {
            cout << s << endl;
            continue;
        }
        if (s[0] == s[1]) {
            s[1] = (s[0] ^ '1') + '0';
        }
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            cout << s[0] << s[1];
        }
        cout << endl;
    }
    return 0;
}
//c.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        int n, k;
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        string ans;
        if (s[k - 1] != s[0]) {
            ans = s[k - 1];
        } else {
            if (s[k] == s[n - 1]) {
                n = ceil(double(n) / k);
                cout << s[0];
                while (--n) ans.push_back(s[k]);
            } else {
                ans = s.substr(k - 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
//b.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int a[3] = {-1, -1,- 1}, ans = 1e9;
        for (int i = 0; i < s.length(); ++i) {
            a[s[i] - '1'] = i;
            if (a[0] != -1 && a[1] != -1 && a[2] != -1) {
                ans = min(ans, i - min({a[0], a[1], a[2]}) + 1);
            }
        }
        if (ans == 1e9) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
//Expogo.cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int x, y, fx = 0, fy = 0;
        cin >> x >> y;
        if (x < 0) fx = 1, x = -x;
        if (y < 0) fy = 1, y = -y;
        ll tot = 1;
        int lim = 0;
        while (tot <= x + y) tot <<= 1, ++lim;
        tot -= 1;
        int sp = tot ^ (x + y);
        sp >>= 1;
        string ans;
        for (int i = 0; i < lim; ++i) {
            if (x >> i & 1) {
                if (y >> i & 1) {
                    ans = "IMPOSSIBLE";
                    break;
                }
                if (sp >> i & 1) {
                    x += 1 << i;
                    if (fx) ans.push_back('E');
                    else ans.push_back('W');
                } else {
                    if (fx) ans.push_back('W');
                    else ans.push_back('E');
                }
            } else if (y >> i & 1) {
                if (sp >> i & 1) {
                    y += 1 << i;
                    if (fy) ans.push_back('N');
                    else ans.push_back('S');
                } else {
                    if (fy) ans.push_back('S');
                    else ans.push_back('N');
                }
            } else {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}
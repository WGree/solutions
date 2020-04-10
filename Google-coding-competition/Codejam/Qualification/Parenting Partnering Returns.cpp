//Parenting Partnering Returns.cpp
#include <bits/stdc++.h>
using namespace std;

struct rec {
    int l, r, id;
} act[1005];

bool cmp(rec &x, rec &y) {
    if (x.l != y.l)
        return x.l < y.l;
    return x.r < y.r;
};

int main() {
    int T;
    cin >> T;
    string s;
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> act[i].l >> act[i].r;
            act[i].id = i;
        }
        sort(act, act + n, cmp);

        string ans(n, 0);
        int c = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            if (act[i].l >= c) {
                ans[act[i].id] = 'C';
                c = act[i].r;
            } else if (act[i].l >= j) {
                ans[act[i].id] = 'J';
                j = act[i].r;
            } else {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}
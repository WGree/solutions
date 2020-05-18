//b.cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int nex[N][3];

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin  >> s;
        int n = s.length();
        s = ' ' + s;
        nex[n][0] = nex[n][1] = nex[n][2] = -1;
        for (int i = n - 1; i >= 0; --i) {
            nex[i][0] = nex[i + 1][0];
            nex[i][1] = nex[i + 1][1];
            nex[i][2] = nex[i + 1][2];
            nex[i][s[i + 1] - '1'] = i + 1;
        }
        if (nex[0][0] == -1 || nex[0][1] == -1 || nex[0][2] == -1) {
            cout << 0 << endl;
            continue;
        }
        int a[3] = {nex[0][0], nex[0][1], nex[0][2]};
        int ans = max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]}) + 1;
        while (1) {
            if (a[0] == -1 || a[1] == -1 || a[2] == -1)
                break;
            if (a[0] == min({a[0], a[1], a[2]}))
                a[0] = nex[a[0]][0];
            else if (a[1] == min({a[0], a[1], a[2]}))
                a[1] = nex[a[1]][1];
            else if (a[2] == min({a[0], a[1], a[2]}))
                a[2] = nex[a[2]][2];
            ans = min(ans, max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]}) + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
//Overexcited Fan.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        int f = -1;
        if (x == y && x == 0) {
            f = 0;
        }
        for (int i = 0; i < s.length() && f == -1; ++i) {
            if (s[i] == 'S') --y;
            else if (s[i] == 'N') ++y;
            else if (s[i] == 'E') ++x;
            else --x;
            if (abs(x) + abs(y) <= i + 1)
                f = i + 1;
        }
        printf("Case #%d: ", cas);
        if (f != -1) printf("%d\n", f);
        else puts("IMPOSSIBLE");
    }
    return 0;
}
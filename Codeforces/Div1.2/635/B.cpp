//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int x, n, m;
        cin >> x >> n >> m;
        while (x > 0) {
            if (n && x > 20) 
                --n, x = x / 2 + 10;
            else if (m) 
                --m, x -= 10;
            else break;
        }
        if (x > 0) puts("NO");
        else puts("YES");
    }
    return 0;
}
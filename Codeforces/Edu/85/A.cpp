//A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, n, ta, tb, f = 1;
        cin >> n;
        --n;
        cin >> a >> b;
        if (a < b) f = 0;
        while (n--) {
            cin >> ta >> tb;
            if (ta < tb) f = 0;
            if (a > ta || b > tb) f = 0;
            if (tb - b > ta - a) f = 0;
            a = ta, b = tb;
        }
        if (f) puts("YES");
        else puts("NO");
    }
    return 0;
}
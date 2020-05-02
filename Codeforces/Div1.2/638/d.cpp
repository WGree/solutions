//d.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int aans = 31 - __builtin_clz(n);
        vector<int> ans;
        --n;
        for (int i = 0, la = 1; i < aans; ++i) {
            int tp = min(1 << (i + 1), n / (aans - i));
            ans.emplace_back(tp - la);
            n -= tp;
            la = tp;
        }
        cout << aans << endl;
        for (int &i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
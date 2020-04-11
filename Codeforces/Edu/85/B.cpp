//B.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, x, num = 0;
        cin >> n >> x;
        vector<int> a;
        ll sum = 0;
        for (int i = 0, t; i < n; ++i) {
            cin >> t;
            if (t >= x) sum += t, ++num;
            else a.emplace_back(t);
        }
        sort(a.begin(), a.end());
        while (!a.empty()) {
            if ((sum + a.back()) / x < num + 1) break;
            sum += a.back();
            a.pop_back();
            ++num;
        }
        cout << num << endl;
    }
    return 0;
}
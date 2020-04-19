//Bike Tour.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
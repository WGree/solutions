///A.cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n / 2 + 1);
    for (int i = 1; i <= n / 2; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n / 2; ++i) {
        ans1 += abs(a[i] - 2 * i + 1);
    }
    for (int i = 1; i <= n / 2; ++i) {
        ans2 += abs(a[i] - 2 * i);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}